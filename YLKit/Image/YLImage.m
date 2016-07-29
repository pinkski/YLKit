//
//  YLImage.m
//  YLKit
//
//  Created by 张晓岚 on 16/7/29.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import "YLImage.h"
#import "NSBundle+YLAdd.h"
#import "NSString+YLAdd.h"

@implementation YLImage {
    YLImageDecoder *_decoder;
    NSArray *_preloadedFrames;
    dispatch_semaphore_t _preloadedLock;
    NSUInteger _bytesPerFrame;
}

+ (YLImage *)imageNamed:(NSString *)name {
    if (name.length == 0) return nil;
    if ([name hasSuffix:@"/"]) return nil;
    
    NSString *res = name.stringByDeletingPathExtension;
    NSString *ext = name.pathExtension;
    NSString *path = nil;
    CGFloat scale = 1;
    
    NSArray *exts = ext.length > 0 ? @[ext] : @[@"", @"png", @"jpeg", @"jpg", @"gif", @"webp", @"apng"];
    NSArray *scales = [NSBundle preferredScales];
    for (int s = 0; s < scales.count; s++) {
        scale = ((NSNumber *)scales[s]).floatValue;
        NSString *scaledName = [res stringByAppendingNameScale:scale];
        for (NSString *e in exts) {
            path = [[NSBundle mainBundle] pathForResource:scaledName ofType:e];
            if (path) break;
        }
        if (path) break;
    }
    if (path.length == 0) return nil;
    
    NSData *data = [NSData dataWithContentsOfFile:path];
    if (data.length == 0) return nil;
    
    return [[self alloc] initWithData:data scale:scale];
}

+ (YLImage *)imageWithContentsOfFile:(NSString *)path {
    return [[self alloc] initWithContentsOfFile:path];
}

+ (YLImage *)imageWithData:(NSData *)data {
    return [[self alloc] initWithData:data];
}

+ (YLImage *)imageWithData:(NSData *)data scale:(CGFloat)scale {
    return [[self alloc] initWithData:data scale:scale];
}

- (instancetype)initWithContentsOfFile:(NSString *)path {
    NSData *data = [NSData dataWithContentsOfFile:path];
    return [self initWithData:data scale:path.pathScale];
}

- (instancetype)initWithData:(NSData *)data {
    return [self initWithData:data scale:1];
}




@end
