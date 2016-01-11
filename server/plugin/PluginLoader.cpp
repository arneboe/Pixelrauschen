//
// Created by arne on 1/10/16.
//

#include "PluginLoader.h"
#include <QString>
#include <QDir>
#include <iostream>
#include <QPluginLoader>

PluginLoader::PluginLoader(const std::string& pluginFolder)
{
  const QString path(pluginFolder.c_str());
  const QDir dir(path);
  const QStringList files = dir.entryList(QDir::Files);
  for(const QString file : files)
  {
    pluginLoaders.emplace_back(new QPluginLoader(dir.absoluteFilePath(file)));
    QObject* plugin = pluginLoaders.back()->instance();
    if(plugin != nullptr)
    {
      std::cout << "LOADED" << std::endl;
    }
    else
    {
      pluginLoaders.pop_back();
    }
  }
}
