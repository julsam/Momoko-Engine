#ifndef _UTILS_H
#define _UTILS_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

#include "Vector2.h"

class Utils
{
public:
    static bool clearFileContent(const std::string& _filename);
    static bool writeEndFile(const std::string& _filename, const std::string& _content);
    static std::string num2str(const int _num);
    static std::string num2str(const long _num);
    static std::string num2str(const float _num);
    static std::string num2str(const double _num);
    static std::string vec2str(const Vector2 _num);
};

#endif // _UTILS_H
