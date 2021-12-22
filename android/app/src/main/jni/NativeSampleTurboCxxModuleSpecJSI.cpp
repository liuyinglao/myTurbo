/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "NativeSampleTurboCxxModuleSpecJSI.h"

// NOTE: This entire file should be codegen'ed.

namespace facebook {
namespace react {

static jsi::Value __hostFunction_NativeSampleTurboCxxModuleSpecJSI_getString(
    jsi::Runtime &rt,
    TurboModule &turboModule,
    const jsi::Value *args,
    size_t count) {
  return static_cast<NativeSampleTurboCxxModuleSpecJSI *>(&turboModule)
      ->getString(rt, args[0].getString(rt));
}

static jsi::Value __hostFunction_NativeSampleTurboCxxModuleSpecJSI_getConstants(
    jsi::Runtime &rt,
    TurboModule &turboModule,
    const jsi::Value *args,
    size_t count) {
  return static_cast<NativeSampleTurboCxxModuleSpecJSI *>(&turboModule)
      ->getConstants(rt);
}

NativeSampleTurboCxxModuleSpecJSI::NativeSampleTurboCxxModuleSpecJSI(
    std::shared_ptr<CallInvoker> jsInvoker)
    : TurboModule("SampleTurboCxxModule", jsInvoker) {
  methodMap_["getString"] = MethodMetadata{
      1, __hostFunction_NativeSampleTurboCxxModuleSpecJSI_getString};
  methodMap_["getConstants"] = MethodMetadata{
      0, __hostFunction_NativeSampleTurboCxxModuleSpecJSI_getConstants};
}

} // namespace react
} // namespace facebook
