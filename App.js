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

const App: () => Node = () => {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  const testFunc = async () => {
    console.log('hello world');
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
