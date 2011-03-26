#ifndef _CONFIGFILE_H
#define _CONFIGFILE_H

#include "AbstractXml.h"

class ConfigFile : public AbstractXml
{
public:
    ConfigFile();
    ConfigFile(const std::string& _filename);
    void loadConfig(const std::string& _filename="");
    bool createDefaultFile(); //TODO

private:
    void processFile(rapidxml::xml_node<>* XMLRoot);
    void processVideo(rapidxml::xml_node<>* XMLNode);
    void processMisc(rapidxml::xml_node<>* XMLNode);

private:
};

#endif // _CONFIGFILE_H
