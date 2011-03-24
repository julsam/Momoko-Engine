#include "Config.h"

using namespace std;

Config* Config::instance = NULL;

Config::Config(int argc, char **argv)
    : ConfigFile(), LaunchOpt(argc, argv)
{
    instance = this;
}

bool
Config::init()
{
    LogManager::getSingleton()->logMessage( "[Config] Init" );
    load();
    setOptions(m_infos);
    return true;
}


Config_Info
Config::getInfo()
{
    return instance->m_infos;
}


Vector2
Config::getScreenSize()
{
    return instance->m_infos.windowSize;
}

std::string 
Config::getCaption()
{
    return instance->m_progname;
}

bool
Config::isFullscreen()
{
    return instance->m_infos.fullscreen ? true:false;
}


bool 
Config::isVerboseEnabled()
{
    return (instance->m_infos.verbose ? true : false);
}
