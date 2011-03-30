#include "ConfigFile.h"
#include "Config.h"
#include "LogManager.h"
#include "Vector2.h"
#include "Utils.h"
#include <vector>

using namespace std;

ConfigFile::ConfigFile(Config_Info* _infos)
    : AbstractXml()
{
    m_pinfos = _infos;
}

ConfigFile::ConfigFile(const string& _filename, Config_Info* _infos)
    : AbstractXml(_filename)
{
    m_pinfos = _infos;
}

ConfigFile::~ConfigFile()
{
}

void
ConfigFile::loadConfig(const string& _filename)
{
    if (!defaultFileExists())
    {
        createDefaultFile();
    }
    else
    {
        setRootNode("config");
        if (_filename == "")
            readFile("config.xml");
        else
            readFile(_filename);
    }
}

void
ConfigFile::processFile(rapidxml::xml_node<>* XMLRoot)
{
    string message = "[ConfigFile] Processing config.";
    LogManager::getSingleton()->logMessage(message);

    rapidxml::xml_node<>* pElement;

    // Video
    pElement = XMLRoot->first_node("video");
    if(pElement)
        processVideo(pElement);

    // Video
    pElement = XMLRoot->first_node("misc");
    if(pElement)
        processMisc(pElement);
}

void
ConfigFile::processVideo(rapidxml::xml_node<>* XMLNode)
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Processing video options." );

    m_pinfos->fullscreen = XMLBool(XMLNode, "fullscreen");
    m_pinfos->windowSize.x = XMLInt(XMLNode, "windowWidth");
    m_pinfos->windowSize.y = XMLInt(XMLNode, "windowHeight");
    m_pinfos->windowCentered = XMLBool(XMLNode, "windowCentered");
    m_pinfos->windowResizable = XMLBool(XMLNode, "windowResizable");
    m_pinfos->colorDepth = XMLInt(XMLNode, "colorDepth");
    m_pinfos->vSync = XMLBool(XMLNode, "vSync");

    LogManager::getSingleton()->logMessage( "[ConfigFile] Done with video options." );
}


void
ConfigFile::processMisc(rapidxml::xml_node<>* XMLNode)
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Processing misc. options." );

    m_pinfos->verbose = XMLBool(XMLNode, "verbose");

    LogManager::getSingleton()->logMessage( "[ConfigFile] Done with misc. options." );
}



bool
ConfigFile::createDefaultFile()
{
    LogManager::getSingleton()->logMessage("Creating a new config file. (not yet implemented)");
    
    //LogManager::getSingleton()->logMessage("[ConfigFile] Error: Could not create a new config file.", LogManager::LML_CRITICAL);
    return true;
}
