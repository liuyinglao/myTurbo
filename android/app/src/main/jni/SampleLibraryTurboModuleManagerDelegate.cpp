/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "SampleLibraryTurboModuleManagerDelegate.h"

#include "SampleLibraryModuleProvider.h"
#include "SampleTurboCxxModule.h"

namespace facebook {
namespace react {

jni::local_ref<SampleLibraryTurboModuleManagerDelegate::jhybriddata>
SampleLibraryTurboModuleManagerDelegate::initHybrid(jni::alias_ref<jhybridobject>) {
  return makeCxxInstance();
}

void SampleLibraryTurboModuleManagerDelegate::registerNatives() {
  registerHybrid({
      makeNativeMethod(
          "initHybrid", SampleLibraryTurboModuleManagerDelegate::initHybrid),
      makeNativeMethod(
          "canCreateTurboModule",
          SampleLibraryTurboModuleManagerDelegate::canCreateTurboModule),
  });
}

std::shared_ptr<TurboModule> SampleLibraryTurboModuleManagerDelegate::getTurboModule(
    const std::string name,
    const std::shared_ptr<CallInvoker> jsInvoker) {
  if (name == "SampleTurboCxxModule") { return std::make_shared<SampleTurboCxxModule>(jsInvoker); }
  return nullptr;
}

std::shared_ptr<TurboModule> SampleLibraryTurboModuleManagerDelegate::getTurboModule(
    const std::string name,
    const JavaTurboModule::InitParams &params) {
  return SampleLibraryModuleProvider(name, params);
}

bool SampleLibraryTurboModuleManagerDelegate::canCreateTurboModule(
    std::string name) {
  return getTurboModule(name, nullptr) != nullptr ||
      getTurboModule(name, {.moduleName = name}) != nullptr;
}

} // namespace react
} // namespace facebook
