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

    rapidxml::xml_node<>* pElement;
    pElement = XMLNode->first_node();

    while(pElement != 0)
    {
        string name(pElement->name());
        string value(pElement->value());

        // fullscreen
        if (name == "fullscreen")
        {
            Config::getSingleton()->m_infos.fullscreen = (value == "true" ? true:false);
        }
        // windowWidth
        else if (name == "windowWidth")
        {
            Config::getSingleton()->m_infos.windowSize.x = atoi(value.c_str());
        }
        // windowHeight
        else if (name == "windowHeight")
        {
            Config::getSingleton()->m_infos.windowSize.y = atoi(value.c_str());
        }
        // windowCentered
        else if (name == "windowCentered")
        {
            Config::getSingleton()->m_infos.windowCentered = (value == "true" ? true:false);
        }
        // windowResizable
        else if (name == "windowResizable")
        {
            Config::getSingleton()->m_infos.windowResizable = (value == "true" ? true:false);
        }
        // colorDepth
        else if (name == "colorDepth")
        {
            Config::getSingleton()->m_infos.colorDepth = atoi(value.c_str());
        }
        // vSync
        else if (name == "vSync")
        {
            Config::getSingleton()->m_infos.vSync = (value == "true" ? true:false);
        }

        pElement = pElement->next_sibling();
    }
    LogManager::getSingleton()->logMessage( "[ConfigFile] Done with video options." );
}


void
ConfigFile::processMisc(rapidxml::xml_node<>* XMLNode)
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Processing misc. options." );

    rapidxml::xml_node<>* pElement;
    pElement = XMLNode->first_node();

    while(pElement != 0)
    {
        string name(pElement->name());
        string value(pElement->value());

        // verbose
        if (name == "verbose")
        {
            Config::getSingleton()->m_infos.verbose = (value == "true" ? true:false);
        }

        pElement = pElement->next_sibling();
    }
    LogManager::getSingleton()->logMessage( "[ConfigFile] Done with misc. options." );
}



bool
ConfigFile::createDefaultFile()
{
    LogManager::getSingleton()->logMessage("Creating a new config file. (not yet implemented)");
    
    //LogManager::getSingleton()->logMessage("[ConfigFile] Error: Could not create a new config file.", LogManager::LML_CRITICAL);
    return true;
}
