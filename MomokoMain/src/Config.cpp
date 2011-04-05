#include "../include/Config.h"
#include "../include/LogManager.h"
#include "../include/Vector2.h"

using namespace std;

Config* Config::instance = NULL;

Config::Config(int argc, char **argv)
    : m_pinfos(&m_infos),
      mConfigFile(m_pinfos),
      mLaunchOpt(argc, argv)
{
    instance = this;
    setupDefaultValues();
}

Config::~Config()
{
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
Config::getInfos()
{
    return instance->m_infos;
}


std::string
Config::getCaption()
{
    return instance->m_infos.progname;
}


