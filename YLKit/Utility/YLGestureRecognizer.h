//
//  YLGestureRecognizer.h
//  YLKit
//
//  Created by 张晓岚 on 16/8/11.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YYGestureRecognizerState) {
    YYGestureRecognizerStateBegan, ///< gesture start
    YYGestureRecognizerStateMoved, ///< gesture moved
    YYGestureRecognizerStateEnded, ///< gesture end
    YYGestureRecognizerStateCancelled, ///< gesture cancel
};

/**
 A simple UIGestureRecognizer subclass for receive touch events.
 */
@interface YLGestureRecognizer : UIGestureRecognizer

@property (nonatomic, readonly) CGPoint startPoint; ///< start point
@property (nonatomic, readonly) CGPoint lastPoint; ///< last move point.
@property (nonatomic, readonly) CGPoint currentPoint; ///< current move point.

/// The action block invoked by every gesture event.
@property (nullable, nonatomic, copy) void (^action)(YLGestureRecognizer *gesture, YYGestureRecognizerState state);

/// Cancel the gesture for current touch.
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
