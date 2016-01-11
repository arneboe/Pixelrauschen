//
// Created by arne on 1/10/16.
//

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "IEffect.h"

class QPluginLoader;
namespace plokid 
{
  class PluginLoader
  {
  public:
    PluginLoader(const std::string& pluginFolder);
    
    const std::vector<plokid::IEffect*>& getEffects() const;
    
  private:
    /**We need to retain instances of all the plugin loaders because
    * the loaded plugins will be destroyed if the loaders are destroyed*/
    std::vector<std::shared_ptr<QPluginLoader>> pluginLoaders;
    
    /**The memory is managed by the correspondig plugin loaders. Therefore no auto pointer is needed*/
    std::vector<plokid::IEffect*> effects;
    
  };
}



