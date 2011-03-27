#ifndef _CONFIG_H
#define _CONFIG_H

#include "ConfigFile.h"
#include "LaunchOpt.h"

#include <iostream>
#include <string.h>

class Config
{
public:
    Config(int argc, char **argv);
    ~Config();
    bool init();
    void setupDefaultValues();

    static Config* getSingleton();
    static std::string getCaption();
    static Config_Info* getInfos();

private:
    static Config* instance;
    Config_Info* m_infos;
    ConfigFile mConfigFile;
    LaunchOpt mLaunchOpt;
};

#endif // _CONFIG_H
