//
//  YLWebImageManager.h
//  YLKit
//
//  Created by 张晓岚 on 16/8/1.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <UIKit/UIKit.h>

#if __has_include(<YLKit/YLKit.h>)
#import <YLKit/YLImageCache.h>
#else
#import "YLImageCache.h"
#endif

@class YLWebImageOperation;

NS_ASSUME_NONNULL_BEGIN

/// The options to control image operation.
typedef NS_OPTIONS(NSUInteger, YYWebImageOptions) {
    
    /// Show network activity on status bar when download image.
    YYWebImageOptionShowNetworkActivity = 1 << 0,
    
    /// Display progressive/interlaced/baseline image during download (same as web browser).
    YYWebImageOptionProgressive = 1 << 1,
    
    /// Display blurred progressive JPEG or interlaced PNG image during download.
    /// This will ignore baseline image for better user experience.
    YYWebImageOptionProgressiveBlur = 1 << 2,
    
    /// Use NSURLCache instead of YYImageCache.
    YYWebImageOptionUseNSURLCache = 1 << 3,
    
    /// Allows untrusted SSL ceriticates.
    YYWebImageOptionAllowInvalidSSLCertificates = 1 << 4,
    
    /// Allows background task to download image when app is in background.
    YYWebImageOptionAllowBackgroundTask = 1 << 5,
    
    /// Handles cookies stored in NSHTTPCookieStore.
    YYWebImageOptionHandleCookies = 1 << 6,
    
    /// Load the image from remote and refresh the image cache.
    YYWebImageOptionRefreshImageCache = 1 << 7,
    
    /// Do not load image from/to disk cache.
    YYWebImageOptionIgnoreDiskCache = 1 << 8,
    
    /// Do not change the view's image before set a new URL to it.
    YYWebImageOptionIgnorePlaceHolder = 1 << 9,
    
    /// Ignore image decoding.
    /// This may used for image downloading without display.
    YYWebImageOptionIgnoreImageDecoding = 1 << 10,
    
    /// Ignore multi-frame image decoding.
    /// This will handle the GIF/APNG/WebP/ICO image as single frame image.
    YYWebImageOptionIgnoreAnimatedImage = 1 << 11,
    
    /// Set the image to view with a fade animation.
    /// This will add a "fade" animation on image view's layer for better user experience.
    YYWebImageOptionSetImageWithFadeAnimation = 1 << 12,
    
    /// Do not set the image to the view when image fetch complete.
    /// You may set the image manually.
    YYWebImageOptionAvoidSetImage = 1 << 13,
    
    /// This flag will add the URL to a blacklist (in memory) when the URL fail to be downloaded,
    /// so the library won't keep trying.
    YYWebImageOptionIgnoreFailedURL = 1 << 14,
};

/// Indicated where the image came from.
typedef NS_ENUM(NSUInteger, YYWebImageFromType) {
    
    /// No value.
    YYWebImageFromNone = 0,
    
    /// Fetched from memory cache immediately.
    /// If you called "setImageWithURL:..." and the image is already in memory,
    /// then you will get this value at the same call.
    YYWebImageFromMemoryCacheFast,
    
    /// Fetched from memory cache.
    YYWebImageFromMemoryCache,
    
    /// Fetched from disk cache.
    YYWebImageFromDiskCache,
    
    /// Fetched from remote (web or file path).
    YYWebImageFromRemote,
};

/// Indicated image fetch complete stage.
typedef NS_ENUM(NSInteger, YYWebImageStage) {
    
    /// Incomplete, progressive image.
    YYWebImageStageProgress  = -1,
    
    /// Cancelled.
    YYWebImageStageCancelled = 0,
    
    /// Finished (succeed or failed).
    YYWebImageStageFinished  = 1,
};


typedef void(^YYWebImageProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);

typedef UIImage * _Nullable (^YYWebImageTransformBlock)(UIImage *image, NSURL *url);

typedef void (^YYWebImageCompletionBlock)(UIImage * _Nullable image,
                                          NSURL *url,
                                          YYWebImageFromType from,
                                          YYWebImageStage stage,
                                          NSError * _Nullable error);



@interface YLWebImageManager : NSObject

+ (instancetype)sharedManager;

- (instancetype)initWithCache:(nullable YLImageCache *)cache
                        queue:(nullable NSOperationQueue *)queue NS_DESIGNATED_INITIALIZER;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (nullable YLWebImageOperation *)requestImageWithURL:(NSURL *)url
                                              options:(YYWebImageOptions)options
                                             progress:(nullable YYWebImageProgressBlock)progress
                                            transform:(nullable YYWebImageTransformBlock)transform
                                           completion:(nullable YYWebImageCompletionBlock)completion;


@property (nullable, nonatomic, strong) YLImageCache *cache;
@property (nullable, nonatomic, strong) NSOperationQueue *queue;
@property (nullable, nonatomic, copy) YYWebImageTransformBlock sharedTransformBlock;
@property (nonatomic) NSTimeInterval timeout;
@property (nullable, nonatomic, copy) NSString *username;
@property (nullable, nonatomic, copy) NSString *password;
@property (nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *headers;
@property (nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *(^headersFilter)(NSURL *url, NSDictionary<NSString *, NSString *> * _Nullable header);
@property (nullable, nonatomic, copy) NSString *(^cacheKeyFilter)(NSURL *url);
- (nullable NSDictionary<NSString *, NSString *> *)headersForURL:(NSURL *)url;
- (NSString *)cacheKeyForURL:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
