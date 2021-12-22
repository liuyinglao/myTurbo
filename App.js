/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React from 'react';
import type {Node} from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
} from 'react-native';

import {
  Colors,
  DebugInstructions,
  Header,
  LearnMoreLinks,
  ReloadInstructions,
} from 'react-native/Libraries/NewAppScreen';
import Button from "react-native/Libraries/Components/Button";
import SampleLibrary from '/Users/yinglao/myTurbo2/js/NativeSampleLibrary'
import SampleTurboCxxModule from '/Users/yinglao/myTurbo2/js/SampleTurboCxxModule'
const App: () => Node = () => {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  const testFunc = async () => {
    const s = await SampleLibrary.getString('hello world ');
    const ob = await SampleTurboCxxModule.getConstants();
    console.log(ob)
    console.log(s)
  }

  return (
    <SafeAreaView style={backgroundStyle}>
      <Button
        onPress={testFunc}
        title="Test"
        color="#841584"
        accessibilityLabel="click to test turbo module"
      />
    </SafeAreaView>
  );
};

export default App;
