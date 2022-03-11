import React from 'react';
import UIPropsExample from './src/UIPropsExample';
import { initializeForFabric } from '../src/reanimated2/core';

export default function App() {
  React.useEffect(() => {
    initializeForFabric();
  }, []);

  return <UIPropsExample />;
}