/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

@class ALAssetsLibrary;
@class RCTBridge;

typedef void (^RCTImageLoaderProgressBlock)(int64_t written, int64_t total);
typedef void (^RCTImageLoaderCompletionBlock)(NSError *error, id /* UIImage or CAAnimation */);
typedef void (^RCTImageLoaderCancellationBlock)(void);

@interface RCTImageLoader : NSObject

/**
 * The shared asset library instance.
 */
+ (ALAssetsLibrary *)assetsLibrary;

/**
 * Can be called from any thread.
 * Will always call callback on main thread.
 */
+ (RCTImageLoaderCancellationBlock)loadImageWithTag:(NSString *)imageTag
                                             bridge:(RCTBridge *)bridge
                                           callback:(RCTImageLoaderCompletionBlock)callback;

/**
 * As above, but includes target size, scale and resizeMode, which are used to
 * select the optimal dimensions for the loaded image.
 */
+ (RCTImageLoaderCancellationBlock)loadImageWithTag:(NSString *)imageTag
                                               size:(CGSize)size
                                              scale:(CGFloat)scale
                                         resizeMode:(UIViewContentMode)resizeMode
                                             bridge:(RCTBridge *)bridge
                                      progressBlock:(RCTImageLoaderProgressBlock)progress
                                    completionBlock:(RCTImageLoaderCompletionBlock)completion;

/**
 * Is the specified image tag an asset library image?
 */
+ (BOOL)isAssetLibraryImage:(NSString *)imageTag;

/**
 * Is the specified image tag a remote image?
 */
+ (BOOL)isRemoteImage:(NSString *)imageTag;

@end
