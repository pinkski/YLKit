//
//  YLKVStorage.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/28.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YLKVStorageItem : NSObject

@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) NSString *value;
@property (nullable, nonatomic, strong) NSString *filename;
@property (nonatomic) int size;
@property (nonatomic) int modTime;
@property (nonatomic) int accessTime;
@property (nullable, nonatomic, strong) NSData *extendedData;

@end

typedef NS_ENUM(NSUInteger, YYKVStorageType) {
    
    /// The `value` is stored as a file in file system.
    YYKVStorageTypeFile = 0,
    
    /// The `value` is stored in sqlite with blob type.
    YYKVStorageTypeSQLite = 1,
    
    /// The `value` is stored in file system or sqlite based on your choice.
    YYKVStorageTypeMixed = 2,
};



@interface YLKVStorage : NSObject

#pragma mark - Attribute

@property (nonatomic, readonly) NSString *path;
@property (nonatomic, readonly) YYKVStorageType type;
@property (nonatomic) BOOL errorLogsEnabled;

#pragma mark - Initializer

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (nullable instancetype)initWithPath:(NSString *)path type:(YYKVStorageType)type NS_DESIGNATED_INITIALIZER;

#pragma mark - Save Items

- (BOOL)savaItem:(YLKVStorageItem *)item;

- (BOOL)savaItemWithKey:(NSString *)key value:(NSData *)value;

- (BOOL)savaItemWithKey:(NSString *)key
                  value:(NSData *)value
               filename:(nullable NSString *)filename
           extendedData:(NSData *)extendedData;


#pragma mark - Remove Items

- (BOOL)removeItemForKey:(NSString *)key;

- (BOOL)removeItemForKeys:(NSArray<NSString *> *)keys;

- (BOOL)removeItemsLargerThanSize:(int)size;

- (BOOL)removeItemsEalierThanTime:(int)time;

- (BOOL)removeItemsToFitSize:(int)maxSize;

- (BOOL)removeItemsToFitCount:(int)maxCount;

- (BOOL)removeAllItems;

- (BOOL)removeAllItemsWithProgressBlock:(nullable void(^)(int removeCount, int totalCount))progress
                               endBlock:(nullable void(^)(BOOL error))end;


#pragma mark - Get Items

- (nullable YLKVStorageItem *)getItemForKey:(NSString *)key;

- (nullable YLKVStorageItem *)getItemInfoForKey:(NSString *)key;

- (nullable NSData *)getItemValueForKey:(NSString *)key;

- (nullable NSArray<YLKVStorageItem *> *)getItemForKeys:(NSArray<NSString *> *)keys;

- (nullable NSArray<YLKVStorageItem *> *)getItemInfoForKeys:(NSArray<NSString *> *)keys;

- (nullable NSDictionary<NSString *, NSData *> *)getItemValueForKeys:(NSArray<NSString *> *)keys;


#pragma mark - Get Storage Status

- (BOOL)itemExistsForKey:(NSString *)key;

- (int)getItemsCount;

- (int)getItemsSize;


@end

NS_ASSUME_NONNULL_END
