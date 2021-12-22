/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "SampleTurboCxxModule.h"

#include <ReactCommon/TurboModuleUtils.h>

using namespace facebook;

namespace facebook {
namespace react {

SampleTurboCxxModule::SampleTurboCxxModule(
    std::shared_ptr<CallInvoker> jsInvoker)
    : NativeSampleTurboCxxModuleSpecJSI(jsInvoker) {}

jsi::String SampleTurboCxxModule::getString(
    jsi::Runtime &rt,
    const jsi::String &arg) {
  return jsi::String::createFromUtf8(rt, arg.utf8(rt));
}

jsi::Object SampleTurboCxxModule::getConstants(jsi::Runtime &rt) {
  // Note: return type isn't type-safe.
  jsi::Object result(rt);
  result.setProperty(rt, "const1", jsi::Value(true));
  result.setProperty(rt, "const2", jsi::Value(375));
  result.setProperty(
      rt, "const3", jsi::String::createFromUtf8(rt, "something"));
  return result;
}

} // namespace react
} // namespace facebook
