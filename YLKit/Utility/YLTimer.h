//
//  YLTimer.h
//  YLKit
//
//  Created by 张晓岚 on 16/8/2.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 YYTimer is a thread-safe timer based on GCD. It has similar API with `NSTimer`.
 YYTimer object differ from NSTimer in a few ways:
 
 * It use GCD to produce timer tick, and won't be affected by runLoop.
 * It make a weak reference to the target, so it can avoid retain cycles.
 * It always fire on main thread.
 
 */
@interface YLTimer : NSObject

+ (YYTimer *)timerWithTimeInterval:(NSTimeInterval)interval
                            target:(id)target
                          selector:(SEL)selector
                           repeats:(BOOL)repeats;

- (instancetype)initWithFireTime:(NSTimeInterval)start
                        interval:(NSTimeInterval)interval
                          target:(id)target
                        selector:(SEL)selector
                         repeats:(BOOL)repeats NS_DESIGNATED_INITIALIZER;

@property (readonly) BOOL repeats;
@property (readonly) NSTimeInterval timeInterval;
@property (readonly, getter=isValid) BOOL valid;

- (void)invalidate;

- (void)fire;

@end

NS_ASSUME_NONNULL_END
