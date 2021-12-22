/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>
#include <string>

#include <ReactCommon/TurboModule.h>

namespace facebook {
namespace react {

// TODO: This definition should be codegen'ed for type-safety purpose.
class JSI_EXPORT NativeSampleTurboCxxModuleSpecJSI : public TurboModule {
 protected:
  NativeSampleTurboCxxModuleSpecJSI(std::shared_ptr<CallInvoker> jsInvoker);

 public:
  virtual jsi::String getString(jsi::Runtime &rt, const jsi::String &arg) = 0;
  virtual jsi::Object getConstants(jsi::Runtime &rt) = 0;
};

} // namespace react
} // namespace facebook
