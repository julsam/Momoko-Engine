#ifndef _CONFIG_H
#define _CONFIG_H

#include "LogManager.h"
#include "Vector2.h"
#include "ConfigFile.h"
#include "LaunchOpt.h"

#include <iostream>
#include <string.h>

class Config: public ConfigFile, public LaunchOpt
{
public:
    Config(int argc, char **argv);
    bool init();

    static Config_Info getInfo();
    static Vector2 getScreenSize();
    static std::string getCaption();
    static bool isFullscreen();
    static bool isVerboseEnabled();

private:

private:
    static Config* instance;
};

#endif // _CONFIG_H
