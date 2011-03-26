#include "AbstractXml.h"
#include "LogManager.h"
#include "Vector2.h"
#include "Utils.h"
#include <vector>
#include <fstream>

using namespace std;

AbstractXml::AbstractXml()
    : m_filename("config.xml"), m_rootNode("root")
{
}

AbstractXml::AbstractXml(const std::string& _filename)
    : m_filename(_filename), m_rootNode("root")
{
}

AbstractXml::~AbstractXml()
{
}

void
AbstractXml::setRootNode(const std::string& _nodeName)
{
    m_rootNode = _nodeName;
}

void
AbstractXml::checkFile()
{
    if(!Utils::fileExists(m_filename.c_str()))
    {
        LogManager::getSingleton()->logMessage("Couldn't load file '"+ m_filename +"' : the file doesn't exist !");
        // create a config file
        createDefaultFile();
    }
}

void
AbstractXml::checkFile(const string& _filename)
{
    if(!Utils::fileExists(_filename.c_str()))
    {
        LogManager::getSingleton()->logMessage("Couldn't load file '"+ _filename +"' : the file doesn't exist !");
        LogManager::getSingleton()->logMessage("Will try to load default file instead.");
        // load default file instead
        checkFile();
    }
}

void
AbstractXml::readFile(const string& _filename)
{
    LogManager::getSingleton()->logMessage( "Reading file "+ _filename);

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
}

void
AbstractXml::parse(const string& _input_xml)
{
    LogManager::getSingleton()->logMessage( "Parsing XML." );

    vector<char> xml_copy(_input_xml.begin(), _input_xml.end());
    xml_copy.push_back('\0');

    rapidxml::xml_document<> XMLDoc;
    XMLDoc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&xml_copy[0]);

    rapidxml::xml_node<>* XMLRoot = XMLDoc.first_node(m_rootNode.c_str());

    if( getAttrib(XMLRoot, "formatVersion", "") == "")
    {
        LogManager::getSingleton()->logMessage("Error: Invalid file.", LogManager::LML_CRITICAL);
        return;
    }

    processFile(XMLRoot);
}

string
AbstractXml::getAttrib(rapidxml::xml_node<>* XMLNode, const string &attrib, const string &defaultValue)
{
    if(XMLNode->first_attribute(attrib.c_str()))
        return XMLNode->first_attribute(attrib.c_str())->value();
    else
        return defaultValue;
}

