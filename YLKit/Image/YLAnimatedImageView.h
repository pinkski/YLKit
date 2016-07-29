//
//  YLAnimatedImageView.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/29.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YLAnimatedImageView : UIImageView

@property (nonatomic) BOOL autoPlayAnimatedImage;
@property (nonatomic) NSUInteger currentAnimatedImageIndex;
@property (nonatomic, readonly) BOOL currentIsPlayingAnimation;
@property (nonatomic, copy) NSString *runloopMode;
@property (nonatomic) NSUInteger maxBufferSize;

@end

@protocol YLAnimatedImage <NSObject>

@required
- (NSUInteger)animatedImageFrameCount;
- (NSUInteger)animatedImageLoopCount;
- (NSUInteger)animatedImageBytesPerFrame;
- (nullable UIImage *)animatedImageFrameAtIndex:(NSUInteger)index;
- (NSTimeInterval)animatedImageDurationAtIndex:(NSUInteger)index;

@optional
- (CGRect)animatedImageContentsRectAtIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
