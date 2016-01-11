//
// Created by arne on 1/11/16.
//

#pragma once
#include <QObject>
#include <server/plugin/IEffect.h>

class ExamplePlugin : public QObject, public plokid::IEffect
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "de.rnae.plokid.IEffect.v1")
  Q_INTERFACES(plokid::IEffect)
  
public:
  ExamplePlugin();
  
  virtual void apply(const uint32_t timeSinceLastCall, plokid::ArrayXXb &pixels);
  
};



