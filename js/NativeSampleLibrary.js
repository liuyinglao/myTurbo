// @flow
'use strict';

import type {TurboModule} from 'react-native/Libraries/TurboModule/RCTExport';
import {TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
  +getConstants: () => {||};

  // your module methods go here, for example:
  getString(id: string): Promise<string>;
}

const NativeModule = (TurboModuleRegistry.getEnforcing<Spec>('NativeSampleLibrary'): ?Spec);

export function getString(id: string): Promise<string> {
  return NativeModule.getString(id);
}

export default NativeModule;
