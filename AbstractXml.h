#ifndef _ABSTRACTXML_H
#define _ABSTRACTXML_H

#include "rapidxml/rapidxml.hpp"
#include <string>

class AbstractXml
{
public:
    AbstractXml();
    AbstractXml(const std::string& _filename);
    ~AbstractXml();
    virtual void processFile(rapidxml::xml_node<>* XMLRoot) = 0;
    virtual bool createDefaultFile() = 0;
    virtual void loadConfig(const std::string& _filename="") = 0;
    void checkFile();
    void checkFile(const std::string& _filename);
    void readFile(const std::string& _filename);
    void setRootNode(const std::string& _nodeName);

protected:
    void parse(const std::string& _input_xml);
    std::string getAttrib(rapidxml::xml_node<>* XMLNode, const std::string &attrib, const std::string &defaultValue);

protected:
    std::string m_filename;
    std::string m_rootNode;
};

#endif // _ABSTRACTXML_H
