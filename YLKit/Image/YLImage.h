//
//  YLImage.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/29.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#if __has_include(<YYKit/YYKit.h>)
#import <YLKit/YLAnimatedImageView.h>
#import <YLKit/YLImageCoder.h>
#else
#import "YLAnimatedImageView.h"
#import "YLImageCoder.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface YLImage : UIImage<YLAnimatedImage>

+ (nullable YLImage *)imageNamed:(NSString *)name;
+ (nullable YLImage *)imageWithContentsOfFile:(NSString *)path;
+ (nullable YLImage *)imageWithData:(NSData *)data;
+ (nullable YLImage *)imageWithData:(NSData *)data scale:(CGFloat)scale;

@property (nonatomic, readonly) YYImageType animatedImageType;
@property (nullable, nonatomic, readonly) NSData *animatedImageData;
@property (nonatomic, readonly) NSUInteger animatedImageMemorySize;
@property (nonatomic) BOOL preloadAllAnimatedImageFrames;



@end

NS_ASSUME_NONNULL_END
