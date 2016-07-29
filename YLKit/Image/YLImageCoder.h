//
//  YLImageCoder.h
//  YLKit
//
//  Created by 张晓岚 on 16/7/29.
//  Copyright © 2016年 ThinkMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YYImageType) {
    YYImageTypeUnknown = 0, ///< unknown
    YYImageTypeJPEG,        ///< jpeg, jpg
    YYImageTypeJPEG2000,    ///< jp2
    YYImageTypeTIFF,        ///< tiff, tif
    YYImageTypeBMP,         ///< bmp
    YYImageTypeICO,         ///< ico
    YYImageTypeICNS,        ///< icns
    YYImageTypeGIF,         ///< gif
    YYImageTypePNG,         ///< png
    YYImageTypeWebP,        ///< webp
    YYImageTypeOther,       ///< other image format
};

typedef NS_ENUM(NSUInteger, YYImageDisposeMethod) {
    YYImageDisposeNone = 0,
    YYImageDisposeBackground,
    YYImageDisposePrevious,
};

typedef NS_ENUM(NSUInteger, YYImageBlendOperation) {
    YYImageBlendNone = 0,
    YYImageBlendOver,
};

/**
 An image frame object.
 */
@interface YLImageFrame : NSObject <NSCopying>
@property (nonatomic) NSUInteger index;    ///< Frame index (zero based)
@property (nonatomic) NSUInteger width;    ///< Frame width
@property (nonatomic) NSUInteger height;   ///< Frame height
@property (nonatomic) NSUInteger offsetX;  ///< Frame origin.x in canvas (left-bottom based)
@property (nonatomic) NSUInteger offsetY;  ///< Frame origin.y in canvas (left-bottom based)
@property (nonatomic) NSTimeInterval duration;          ///< Frame duration in seconds
@property (nonatomic) YYImageDisposeMethod dispose;     ///< Frame dispose method.
@property (nonatomic) YYImageBlendOperation blend;      ///< Frame blend operation.
@property (nullable, nonatomic, strong) UIImage *image; ///< The image.
+ (instancetype)frameWithImage:(UIImage *)image;
@end

#pragma mark - Decoder

@interface YLImageDecoder : NSObject

@property (nullable, nonatomic, readonly) NSData *data;    ///< Image data.
@property (nonatomic, readonly) YYImageType type;          ///< Image data type.
@property (nonatomic, readonly) CGFloat scale;             ///< Image scale.
@property (nonatomic, readonly) NSUInteger frameCount;     ///< Image frame count.
@property (nonatomic, readonly) NSUInteger loopCount;      ///< Image loop count, 0 means infinite.
@property (nonatomic, readonly) NSUInteger width;          ///< Image canvas width.
@property (nonatomic, readonly) NSUInteger height;         ///< Image canvas height.
@property (nonatomic, readonly, getter=isFinalized) BOOL finalized;

- (instancetype)initWithScale:(CGFloat)scale NS_DESIGNATED_INITIALIZER;
- (BOOL)updateData:(nullable NSData *)data final:(BOOL)final;
+ (nullable instancetype)decoderWithData:(NSData *)data scale:(CGFloat)scale;
- (nullable YLImageFrame *)frameAtIndex:(NSUInteger)index decodeForDisplay:(BOOL)decodeForDisplay;
- (NSTimeInterval)frameDurationAtIndex:(NSUInteger)index;
- (nullable NSDictionary *)framePropertiesAtIndex:(NSUInteger)index;
- (nullable NSDictionary *)imageProperties;

@end

#pragma mark - Encoder

@interface YLImageEncoder : NSObject

@property (nonatomic, readonly) YYImageType type; ///< Image type.
@property (nonatomic) NSUInteger loopCount;       ///< Loop count, 0 means infinit, only available for GIF/APNG/WebP.
@property (nonatomic) BOOL lossless;              ///< Lossless, only available for WebP.
@property (nonatomic) CGFloat quality;            ///< Compress quality, 0.0~1.0, only available for JPG/JP2/WebP.

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (nullable instancetype)initWithType:(YYImageType)type NS_DESIGNATED_INITIALIZER;
- (void)addImage:(UIImage *)image duration:(NSTimeInterval)duration;
- (void)addImageWithData:(NSData *)data duration:(NSTimeInterval)duration;
- (void)addImageWithFile:(NSString *)path duration:(NSTimeInterval)duration;
- (nullable NSData *)encode;
- (BOOL)encodeToFile:(NSString *)path;
+ (nullable NSData *)encodeImage:(UIImage *)image type:(YYImageType)type quality:(CGFloat)quality;
+ (nullable NSData *)encodeImageWithDecoder:(YLImageDecoder *)decoder type:(YYImageType)type quality:(CGFloat)quality;

@end

#pragma mark - UIImage

@interface UIImage (YLImageCoder)

- (instancetype)imageByDecoded;

@property (nonatomic) BOOL isDecodedForDisplay;

- (void)saveToAlbumWithCompletionBlock:(nullable void(^)(NSURL * _Nullable assetURL, NSError * _Nullable error))completionBlock;
- (nullable NSData *)imageDataRepresentation;

@end



#pragma mark - Helper

/// Detect a data's image type by reading the data's header 16 bytes (very fast).
CG_EXTERN YYImageType YYImageDetectType(CFDataRef data);
/// Convert YYImageType to UTI (such as kUTTypeJPEG).
CG_EXTERN CFStringRef _Nullable YYImageTypeToUTType(YYImageType type);
/// Convert UTI (such as kUTTypeJPEG) to YYImageType.
CG_EXTERN YYImageType YYImageTypeFromUTType(CFStringRef uti);
/// Get image type's file extension (such as @"jpg").
CG_EXTERN NSString *_Nullable YYImageTypeGetExtension(YYImageType type);
/// Returns the shared DeviceRGB color space.
CG_EXTERN CGColorSpaceRef YYCGColorSpaceGetDeviceRGB();
/// Returns the shared DeviceGray color space.
CG_EXTERN CGColorSpaceRef YYCGColorSpaceGetDeviceGray();
/// Returns whether a color space is DeviceRGB.
CG_EXTERN BOOL YYCGColorSpaceIsDeviceRGB(CGColorSpaceRef space);
/// Returns whether a color space is DeviceGray.
CG_EXTERN BOOL YYCGColorSpaceIsDeviceGray(CGColorSpaceRef space);
/// Convert EXIF orientation value to UIImageOrientation.
CG_EXTERN UIImageOrientation YYUIImageOrientationFromEXIFValue(NSInteger value);
/// Convert UIImageOrientation to EXIF orientation value.
CG_EXTERN NSInteger YYUIImageOrientationToEXIFValue(UIImageOrientation orientation);
CG_EXTERN CGImageRef _Nullable YYCGImageCreateDecodedCopy(CGImageRef imageRef, BOOL decodeForDisplay);
CG_EXTERN CGImageRef _Nullable YYCGImageCreateCopyWithOrientation(CGImageRef imageRef,
                                                                  UIImageOrientation orientation,
                                                                  CGBitmapInfo destBitmapInfo);
CG_EXTERN CGImageRef _Nullable YYCGImageCreateAffineTransformCopy(CGImageRef imageRef,
                                                                  CGAffineTransform transform,
                                                                  CGSize destSize,
                                                                  CGBitmapInfo destBitmapInfo);
CG_EXTERN CFDataRef _Nullable YYCGImageCreateEncodedData(CGImageRef imageRef, YYImageType type, CGFloat quality);

/**
 Whether WebP is available in YYImage.
 */
CG_EXTERN BOOL YYImageWebPAvailable();

/**
 Get a webp image frame count;
 
 @param webpData WebP data.
 @return Image frame count, or 0 if an error occurs.
 */
CG_EXTERN NSUInteger YYImageGetWebPFrameCount(CFDataRef webpData);
CG_EXTERN CGImageRef _Nullable YYCGImageCreateWithWebPData(CFDataRef webpData,
                                                           BOOL decodeForDisplay,
                                                           BOOL useThreads,
                                                           BOOL bypassFiltering,
                                                           BOOL noFancyUpsampling);

typedef NS_ENUM(NSUInteger, YYImagePreset) {
    YYImagePresetDefault = 0,  ///< default preset.
    YYImagePresetPicture,      ///< digital picture, like portrait, inner shot
    YYImagePresetPhoto,        ///< outdoor photograph, with natural lighting
    YYImagePresetDrawing,      ///< hand or line drawing, with high-contrast details
    YYImagePresetIcon,         ///< small-sized colorful images
    YYImagePresetText          ///< text-like
};

CG_EXTERN CFDataRef _Nullable YYCGImageCreateEncodedWebPData(CGImageRef imageRef,
                                                             BOOL lossless,
                                                             CGFloat quality,
                                                             int compressLevel,
                                                             YYImagePreset preset);


NS_ASSUME_NONNULL_END
