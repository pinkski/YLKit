//
//  YLDispatchQueuePool.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/28.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef YLDispatchQueuePool_h
#define YLDispatchQueuePool_h

NS_ASSUME_NONNULL_BEGIN

/**
 dispatch 队列池，存放多个队列，
 用这个类可以控制队列的线程数量 （替代concurrent queue）
 concurrent queue 执行大量block，当某个block被锁住时，会开启很多线程，抢占了大量资源从而影响到主线程
*/
@interface YLDispatchQueuePool : NSObject
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  创建并返回一个 pool
 *
 *  @param name       pool name
 *  @param queueCount 最大队列数量  （1， 32）
 *  @param qos        Queue quality of service  (QOS)
 *
 *  @return pool
 */
- (instancetype)initWithName:(nullable NSString *)name queueCount:(NSUInteger)queueCount qos:(NSQualityOfService)qos;

/// pool name
@property (nullable, nonatomic, strong) NSString *name;

/// 获取连续的队列
- (dispatch_queue_t)queue;

///
+ (instancetype)defaultPoolForQOS:(NSQualityOfService)qos;

@end

/// Get a serial queue from global queue pool with a specified qos.
extern dispatch_queue_t YYDispatchQueueGetForQOS(NSQualityOfService qos);

NS_ASSUME_NONNULL_END

#endif
