#include "ConfigFile.h"
#include "Config.h"
#include "LogManager.h"
#include "Vector2.h"
#include "Utils.h"
#include <vector>

using namespace std;

ConfigFile::ConfigFile()
    : AbstractXml()
{
}

ConfigFile::ConfigFile(const string& _filename)
    : AbstractXml(_filename)
{

}

void
ConfigFile::loadConfig(const string& _filename)
{
    checkFile();
    setRootNode("config");
    if (_filename == "")
        readFile("config.xml");
    else
        readFile(_filename);
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
    LogManager::getSingleton()->logMessage( "[ConfigFile] Processing Video options." );

    Config::getSingleton()->m_infos.fullscreen = XMLBool(XMLNode, "fullscreen");
    Config::getSingleton()->m_infos.windowSize.x = XMLInt(XMLNode, "windowWidth");
    Config::getSingleton()->m_infos.windowSize.y = XMLInt(XMLNode, "windowHeight");
    Config::getSingleton()->m_infos.windowCentered = XMLBool(XMLNode, "windowCentered");
    Config::getSingleton()->m_infos.windowResizable = XMLBool(XMLNode, "windowResizable");
    Config::getSingleton()->m_infos.colorDepth = XMLInt(XMLNode, "colorDepth");
    Config::getSingleton()->m_infos.vSync = XMLBool(XMLNode, "vSync");

    LogManager::getSingleton()->logMessage( "[ConfigFile] Done with video options." );
}


void
ConfigFile::processMisc(rapidxml::xml_node<>* XMLNode)
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Processing misc. options." );

    Config::getSingleton()->m_infos.vSync = XMLBool(XMLNode, "verbose");

    LogManager::getSingleton()->logMessage( "[ConfigFile] Done with misc. options." );
}



bool
ConfigFile::createDefaultFile()
{
    LogManager::getSingleton()->logMessage("Creating a new config file. (not yet implemented)");
    
    //LogManager::getSingleton()->logMessage("[ConfigFile] Error: Could not create a new config file.", LogManager::LML_CRITICAL);
    return true;
}
