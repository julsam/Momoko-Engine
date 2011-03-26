#include "Config.h"
#include "LogManager.h"
#include "Vector2.h"

using namespace std;

Config* Config::instance = NULL;

Config::Config(int argc, char **argv)
    : mConfigFile(), mLaunchOpt(argc, argv)
{
    instance = this;
}

Config*
Config::getSingleton()
{
    return instance;
}

bool
Config::init()
{
    LogManager::getSingleton()->logMessage( "[Config] Init" );

    setupDefaultValues();
    mConfigFile.loadConfig();
    mLaunchOpt.setOptions(instance->m_infos);
    return true;
}

void
Config::setupDefaultValues()
{
    // Video
    instance->m_infos.fullscreen        = false;
    instance->m_infos.windowSize        = Vector2(640, 480);
    instance->m_infos.windowPosition    = Vector2();
    instance->m_infos.windowCentered    = true;
    instance->m_infos.windowResizable   = true;
    instance->m_infos.colorDepth        = 32;
    instance->m_infos.vSync             = false;
    // misc
    instance->m_infos.verbose           = true;
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


