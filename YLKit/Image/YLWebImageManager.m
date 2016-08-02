//
//  YLWebImageManager.m
//  YLKit
//
//  Created by 张晓岚 on 16/8/1.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import "YLWebImageManager.h"
#import "YLImageCache.h"
#import "YLWebImageOperation.h"
#import "YLImageCoder.h"

@implementation YLWebImageManager

+ (instancetype)sharedManager {
    static YLWebImageManager *manager;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        YLImageCache *cache = [YLImageCache sharedCache];
        NSOperationQueue *queue = [NSOperationQueue new];
        if ([queue respondsToSelector:@selector(setQualityOfService:)]) {
            queue.qualityOfService = NSQualityOfServiceBackground;
        }
        manager = [[self alloc] initWithCache:cache queue:queue];
    });
    return manager;
}

@end
