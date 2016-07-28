//
//  YLMemoryCache.m
//  YLKit
//
//  Created by 张晓岚 on 16/7/28.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import "YLMemoryCache.h"

#if __has_include("YYDispatchQueuePool.h")
#import "YYDispatchQueuePool.h"
#endif

#ifdef YYDispatchQueuePool_h
static inline dispatch_queue_t YYMemoryCacheGetReleaseQueue() {
    return YYDispatchQueueGetForQOS(NSQualityOfServiceUtility);
}
#else
static inline dispatch_queue_t YYMemoryCacheGetReleaseQueue() {
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0);
}
#endif


@interface _YLLinkedMapNode : NSObject {
    @package
    __unsafe_unretained _YLLinkedMapNode *_prev;
    __unsafe_unretained _YLLinkedMapNode *_next;
    id _key;
    id _value;
    NSUInteger _cost;
    NSTimeInterval _time;
}
@end

@implementation _YLLinkedMapNode
@end

@interface _YLLinkedMap : NSObject {
    @package
    CFMutableDictionaryRef _dic; // do not set object directly
    NSUInteger _totalCost;
    NSUInteger _totalCount;
    _YLLinkedMapNode *_head; // MRU, do not change it directly
    _YLLinkedMapNode *_tail; // LRU, do not change it directly
    BOOL _releaseOnMainThread;
    BOOL _releaseAsynchronously;
}

- (void)insertNodeAtHead:(_YLLinkedMapNode *)node;

- (void)bringNodeToHead:(_YLLinkedMapNode *)node;

- (void)removeNode:(_YLLinkedMapNode *)node;

- (_YLLinkedMapNode *)removeTailNode;

- (void)removeAll;

@end

@implementation _YLLinkedMap

- (instancetype)init {
    self = [super init];
    _dic = CFDictionaryCreateMutable(CFAllocatorGetDefault(), 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    _releaseOnMainThread = NO;
    _releaseAsynchronously = YES;
    return self;
}

- (void)dealloc {
    CFRelease(_dic);
}

- (void)insertNodeAtHead:(_YLLinkedMapNode *)node {
    
}

@end

@implementation YLMemoryCache

@end
