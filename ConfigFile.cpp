#include "ConfigFile.h"
#include "LogManager.h"
#include "Utils.h"
#include "Vector2.h"

#include <vector>
#include <fstream>

using namespace std;

ConfigFile::ConfigFile()
    : m_filename("config.xml")
{
}

ConfigFile::ConfigFile(const string& _filename)
    : m_filename(_filename)
{

}

bool
ConfigFile::load()
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Loading file"+ m_filename);

    if(!Utils::fileExists(m_filename.c_str()))
    {
        LogManager::getSingleton()->logMessage("Couldn't load file : it seems the file doesn't exist.");
        createDefaultFile();
    }
    else
        readXML(m_filename);
    return true;
}

bool
ConfigFile::load(const string& _filename)
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Loading file"+ _filename );

    if(!Utils::fileExists(_filename.c_str()))
    {
        LogManager::getSingleton()->logMessage("Couldn't load file '"+ _filename +"' : the file doesn't exist !");
        LogManager::getSingleton()->logMessage("Couldn't load file : it seems the file doesn't exist.");
        return false;
    }
    // else
    readXML(_filename);
    return true;
}


bool
ConfigFile::readXML(const string& _filename)
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Reading file.");

    string s;
    ifstream f(_filename.c_str());
    while(f)
    {
        string line;
        getline(f, line);
        s += line;
    }

    parse(s);
    f.close();

    return true;
}

void
ConfigFile::parse(const string& _input_xml)
{
    LogManager::getSingleton()->logMessage( "[ConfigFile] Parsing XML." );

    vector<char> xml_copy(_input_xml.begin(), _input_xml.end());
    xml_copy.push_back('\0');

    rapidxml::xml_document<> XMLDoc;
    XMLDoc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&xml_copy[0]);

    rapidxml::xml_node<>* XMLRoot = XMLDoc.first_node("config");

    if( getAttrib(XMLRoot, "formatVersion", "") == "")
    {
        LogManager::getSingleton()->logMessage("[ConfigFile] Error: Invalid .cfg File.");
        return;
    }

    processConfig(XMLRoot);
}

void
ConfigFile::processConfig(rapidxml::xml_node<>* XMLRoot)
{
    string message = "[ConfigFile] Processing config.";
    LogManager::getSingleton()->logMessage(message);

    rapidxml::xml_node<>* pElement;

    // Video
    pElement = XMLRoot->first_node("video");
    if(pElement)
        processVideo(pElement);
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
            m_infos.fullscreen = (value == "true" ? true:false);
        }
        // windowWidth
        else if (name == "windowWidth")
        {
            m_infos.windowSize.x = atoi(value.c_str());
        }
        // windowHeight
        else if (name == "windowHeight")
        {
            m_infos.windowSize.y = atoi(value.c_str());
        }
        // windowCentered
        else if (name == "windowCentered")
        {
            m_infos.windowCentered = (value == "true" ? true:false);
        }

        pElement = pElement->next_sibling();
    }
    LogManager::getSingleton()->logMessage( "[ConfigFile] Done with video options." );
}

string
ConfigFile::getAttrib(rapidxml::xml_node<>* XMLNode, const string &attrib, const string &defaultValue)
{
    if(XMLNode->first_attribute(attrib.c_str()))
        return XMLNode->first_attribute(attrib.c_str())->value();
    else
        return defaultValue;
}


bool
ConfigFile::createDefaultFile()
{
    LogManager::getSingleton()->logMessage("Creating a new config file.");
    return true;
}
