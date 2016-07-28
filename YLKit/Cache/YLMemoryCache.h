//
//  YLMemoryCache.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/28.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YLMemoryCache : NSObject

#pragma mark - Attribute

@property (nullable, copy) NSString *name;
@property (readonly) NSUInteger totalCount;
@property (readonly) NSUInteger totalCost;

#pragma mark - Limit

@property NSUInteger countLimit;
@property NSUInteger costLimit;
@property NSTimeInterval ageLimit;
@property NSTimeInterval autoTrimInterval;
@property BOOL shouldRemoveAllObjectsOnMemoryWarning;
@property BOOL shouldRemoveAllObjectsWhenEnteringBackground;
@property (nullable, copy) void(^didReceiveMemoryWarningBlock)(YLMemoryCache *cache);
@property (nullable, copy) void(^didEnterBackgroundBlock)(YLMemoryCache *cache);
@property BOOL releaseOnMainThread;
@property BOOL releaseAsynchronously;

#pragma mark - Access Methods

- (BOOL)containsObjectForKey:(id)key;
- (nullable id)objectForKey:(id)key;
- (void)setObject:(nullable id)object forKey:(id)key;
- (void)setObject:(nullable id)object forKey:(id)key withCost:(NSUInteger)cost;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;

#pragma mark - Trim

- (void)trimToCount:(NSUInteger)count;
- (void)trimToCost:(NSUInteger)cost;
- (void)trimToAge:(NSTimeInterval)age;

@end

NS_ASSUME_NONNULL_END













