#ifndef _CONFIGFILE_H
#define _CONFIGFILE_H

#include <string>
#include "rapidxml/rapidxml.hpp"
#include "Vector2.h"
#include "Tools.h"


class ConfigFile
{
public:
    ConfigFile();
    ConfigFile(const std::string& _filename);
    bool load();
    bool load(const std::string& _filename);
    bool createDefaultFile(); //TODO

private:
    bool readXML(const std::string& _filename);
    void parse(const std::string& _input_xml);
    void processConfig(rapidxml::xml_node<>* XMLRoot);
    void processVideo(rapidxml::xml_node<>* XMLNode);
    std::string getAttrib(rapidxml::xml_node<>* XMLNode, const std::string &attrib, const std::string &defaultValue);

public:
    Config_Info m_infos;

private:
    std::string m_filename;
};

#endif // _CONFIGFILE_H
