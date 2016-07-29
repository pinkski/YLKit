//
//  NSBundle+YLAdd.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/29.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (YLAdd)

+ (NSArray<NSNumber *> *)preferredScales;

+ (nullable NSString *)pathForScaledResource:(NSString *)name
                                      ofType:(nullable NSString *)ext
                                 inDirectory:(NSString *)bundlePath;

- (nullable NSString *)pathForScaledResource:(NSString *)name ofType:(nullable NSString *)ext;

- (nullable NSString *)pathForScaledResource:(NSString *)name
                                      ofType:(nullable NSString *)ext
                                 inDirectory:(nullable NSString *)subpath;

@end

NS_ASSUME_NONNULL_END
