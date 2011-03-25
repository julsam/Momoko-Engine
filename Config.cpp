#include "Config.h"
#include "LogManager.h"
#include "Vector2.h"

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

std::string 
Config::getCaption()
{
    return instance->m_infos.progname;
}


