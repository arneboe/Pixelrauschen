//
// Created by arne on 1/11/16.
//

#include "ExamplePlugin.h"
#include <iostream>
ExamplePlugin::ExamplePlugin(): QObject(), plokid::IEffect()
{
  std::cout << "TestPlugin created" << std::endl;
}

void ExamplePlugin::apply(const uint32_t timeSinceLastCall, plokid::ArrayXXb& pixels)
{

}
