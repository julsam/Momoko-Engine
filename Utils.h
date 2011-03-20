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
};

#endif // _UTILS_H
