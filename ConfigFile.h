#ifndef _CONFIGFILE_H
#define _CONFIGFILE_H

#include <string>
#include "rapidxml/rapidxml.hpp"
#include "Tools.h"


class ConfigFile
{
public:
    ConfigFile();
    ConfigFile(const std::string& _filename);
    bool loadFileOptions();
    bool loadFileOptions(const std::string& _filename);
    bool createDefaultFile(); //TODO

private:
    bool readXML(const std::string& _filename);
    void parse(const std::string& _input_xml);
    void processConfig(rapidxml::xml_node<>* XMLRoot);
    void processVideo(rapidxml::xml_node<>* XMLNode);
    void processMisc(rapidxml::xml_node<>* XMLNode);
    std::string getAttrib(rapidxml::xml_node<>* XMLNode, const std::string &attrib, const std::string &defaultValue);

private:
    std::string m_filename;
};

#endif // _CONFIGFILE_H
