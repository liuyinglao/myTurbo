/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "NativeSampleLibrary.h"
#import <React/RCTUtils.h>
#import <UIKit/UIKit.h>

using namespace facebook::react;

@implementation NativeSampleLibrary

// Backward-compatible export
RCT_EXPORT_MODULE()

// Backward-compatible queue configuration
+ (BOOL)requiresMainQueueSetup
{
  return YES;
}

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
  return std::make_shared<NativeSampleLibrarySpecJSI>(params);
}

// Backward compatible invalidation
- (void)invalidate
{
  // Actually do nothing here.
  NSLog(@"Invalidating RCTSampleTurboModule...");
}

- (NSDictionary *)getConstants
{
  __block NSDictionary *constants;
  RCTUnsafeExecuteOnMainQueueSync(^{
    UIScreen *mainScreen = UIScreen.mainScreen;
    CGSize screenSize = mainScreen.bounds.size;

    constants = @{
      @"const1" : @YES,
      @"const2" : @(screenSize.width),
      @"const3" : @"something",
    };
  });

  return constants;
}

RCT_EXPORT_SYNCHRONOUS_TYPED_METHOD(void, getString : (NSString *)arg resolve:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject)
{
  resolve(@"ios test string");
}


@end
