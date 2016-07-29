//
//  YLSpriteSheetImage.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/29.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <UIKit/UIKit.h>

#if __has_include(<YYKit/YYKit.h>)
#import <YLKit/YLAnimatedImageView.h>
#else
#import "YLAnimatedImageView.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface YLSpriteSheetImage : UIImage<YLAnimatedImage>

- (nullable instancetype)initWithSpriteSheetImage:(UIImage *)image
                                     contentRects:(NSArray<NSValue *> *)contentRects
                                   frameDurations:(NSArray<NSNumber *> *)frameDurations
                                        loopCount:(NSUInteger)loopCount;

@property (nonatomic, readonly) NSArray<NSValue *> *contentRects;
@property (nonatomic, readonly) NSArray<NSValue *> *frameDurations;
@property (nonatomic, readonly) NSUInteger loopCount;

- (CGRect)contentsRectForCALayerAtIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
