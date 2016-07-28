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

@interface YLDispatchQueuePool : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithName:(nullable NSString *)name queueCount:(NSUInteger)queueCount qos:(NSQualityOfService)qos;

@property (nullable, nonatomic, strong) NSString *name;

- (dispatch_queue_t)queue;

+ (instancetype)defaultPoolForQOS:(NSQualityOfService)qos;

@end

extern dispatch_queue_t YYDispatchQueueGetForQOS(NSQualityOfService qos);

NS_ASSUME_NONNULL_END

#endif
