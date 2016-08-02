//
//  YLWebImageOperation.h
//  YLKit
//
//  Created by 张晓岚 on 16/8/1.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<YYKit/YYKit.h>)
#import <YLKit/YLImageCache.h>
#import <YLKit/YLWebImageManager.h>
#else
#import "YLImageCache.h"
//#import "YLWebImageManager.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface YLWebImageOperation : NSOperation

@property (nonatomic, strong, readonly)           NSURLRequest      *request;  ///< The image URL request.
@property (nullable, nonatomic, strong, readonly) NSURLResponse     *response; ///< The response for request.
@property (nullable, nonatomic, strong, readonly) YLImageCache      *cache;    ///< The image cache.
@property (nonatomic, strong, readonly)           NSString          *cacheKey; ///< The image cache key.
@property (nonatomic, readonly)                   YLWebImageOptions options;   ///< The operation's option.

@property (nonatomic) BOOL shouldUseCredentialStorage;
@property (nullable, nonatomic, strong) NSURLCredential *credential;

- (instancetype)initWithRequest:(NSURLRequest *)request
                        options:(YLWebImageOptions)options
                          cache:(nullable YLImageCache *)cache
                       cacheKey:(nullable NSString *)cacheKey
                       progress:(nullable YLWebImageProgressBlock)progress
                      transform:(nullable YLWebImageTransformBlock)transform
                     completion:(nullable YLWebImageCompletionBlock)completion NS_DESIGNATED_INITIALIZER;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


@end

NS_ASSUME_NONNULL_END