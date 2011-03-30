#ifndef _CONFIGFILE_H
#define _CONFIGFILE_H

#include "AbstractXml.h"
#include "Tools.h"

class ConfigFile : private AbstractXml
{
public:
    ConfigFile(Config_Info *_infos);
    ConfigFile(const std::string& _filename, Config_Info *_infos);
    ~ConfigFile();
    void loadConfig(const std::string& _filename="");
    bool createDefaultFile(); //TODO

private:
    void processFile(rapidxml::xml_node<>* XMLRoot);
    void processVideo(rapidxml::xml_node<>* XMLNode);
    void processMisc(rapidxml::xml_node<>* XMLNode);

private:
    Config_Info*  m_pinfos; // pointer to Config::m_pinfos
};

#endif // _CONFIGFILE_H
