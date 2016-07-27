//
//  NSObject+YLModel.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/27.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  NSObject model
 */
@interface NSObject (YLModel)

+ (nullable instancetype)modelWithJSON:(id)json;

+ (nullable instancetype)modelWithDictionary:(NSDictionary *)dictionary;

+ (BOOL)modelSetWithJSON:(id)json;

+ (BOOL)modelSetWithDictionary:(NSDictionary *)dictionary;

+ (nullable id)modelToJSONObjct;

+ (nullable NSData *)modelToJSONData;

+ (nullable NSString *)modelToJSONString;

+ (nullable id)modelCopy;

- (void)modelEncodeWithCoder:(NSCoder *)aCoder;

- (id)modelInitWithCoder:(NSCoder *)aCoder;

- (NSUInteger)modelHash;

- (BOOL)modelIsEqual:(id)model;

- (NSString *)modelDescription;

@end

/**
 *  NSArray model
 */
@interface NSArray (YLModel)

+ (nullable NSArray *)modelArrayWithClass:(Class)cls json:(id)json;

@end

@protocol YLModel <NSObject>

@optional
+ (nullable NSDictionary<NSString *, id> *)modelCustomPropertyMapper;
+ (nullable NSDictionary<NSString *, id> *)modelContainerPropertyGenericClass;
+ (nullable Class)modelCustomClassForDictionary:(NSDictionary *)dictionary;
+ (nullable NSArray<NSString *> *)modelPropertyBlacklist;
+ (nullable NSArray<NSString *> *)modelPropertyWhitelist;

- (NSDictionary *)modelCustomWillTransformFromDictionary:(NSDictionary *)dictionary;
- (BOOL)modelCustomTransformFromDictionary:(NSDictionary *)dictionary;
- (BOOL)modelCustomTransformToDictionary:(NSMutableDictionary *)dictionary;



@end

NS_ASSUME_NONNULL_END
