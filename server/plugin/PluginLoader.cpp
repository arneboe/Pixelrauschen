//
// Created by arne on 1/10/16.
//

#include "PluginLoader.h"
#include <QString>
#include <QDir>
#include <iostream>
#include <QPluginLoader>

#include <server/Logging.h>

using namespace plokid;

PluginLoader::PluginLoader(const std::string& pluginFolder)
{
  const QString path(pluginFolder.c_str());
  const QDir dir(path);
  const QStringList files = dir.entryList(QDir::Files);

  for(const QString file : files)
  {
    if(file.endsWith(".so") || file.endsWith(".dll"))
    {
      LOG_INFO << "Loading plugin: " << dir.absoluteFilePath(file).toStdString() << std::endl;
      pluginLoaders.emplace_back(new QPluginLoader(dir.absoluteFilePath(file)));
      QObject* plugin = pluginLoaders.back()->instance();

      if(plugin != nullptr)
      {
        IEffect* effect = qobject_cast<IEffect*>(plugin);

        if(nullptr != effect)
        {
          effects.push_back(effect);
          LOG_INFO << "Loaded effect plugin: " << dir.absoluteFilePath(file).toStdString() << std::endl;
        }
        else
        {
          LOG_ERROR << "Failed to load plugin: " << dir.absoluteFilePath(file).toStdString() << std::endl;
          pluginLoaders.pop_back();
        }
      }
      else
      {
        LOG_ERROR << "Failed to load plugin: " << dir.absoluteFilePath(file).toStdString() << std::endl;
        pluginLoaders.pop_back();
      }
    }
  }
}

const std::vector<IEffect*>& PluginLoader::getEffects() const
{
  return effects;
}

