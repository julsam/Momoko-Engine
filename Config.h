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
    static Config* getSingleton();
    bool init();
    void setupDefaultValues();

    static Config_Info getInfo();
    static std::string getCaption();

public:
    Config_Info m_infos;

private:
    static Config* instance;
    ConfigFile mConfigFile;
    LaunchOpt mLaunchOpt;
};

#endif // _CONFIG_H
