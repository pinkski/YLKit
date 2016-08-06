
//
//  YLSentinel.m
//  YLKit
//
//  Created by 张晓岚 on 16/8/4.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import "YLSentinel.h"
#import <libkern/OSAtomic.h>

@implementation YLSentinel {
    int32_t _value;
}

- (int32_t)value {
    return _value;
}

- (int32_t)increase {
    return OSAtomicIncrement32(&_value);
}

@end
