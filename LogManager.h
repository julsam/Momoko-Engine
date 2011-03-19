#ifndef _LOGMANAGER_H
#define _LOGMANAGER_H

#include <iostream>
#include <string.h>
#include <fstream>

#include "Vector2.h"
#include "Config.h"
#include "Utils.h"

class LogManager
{
public:
    enum
    {
        INFO = 0,
        ERROR,
        DEBUG
    };

public:
    LogManager();
    void init();
    static LogManager* getSingleton();

    // TODO: add type of message
    static void logMessage(const bool _bool);
    static void logMessage(const char* _char);
    static void logMessage(const int _num);
    static void logMessage(const long _num);
    static void logMessage(const float _num);
    static void logMessage(const double _num);
    static void logMessage(const Vector2 _vec);
    static void logMessage(const std::string& _msg); 

private:
    void output(const std::string& log);
    void writeToFile(const std::string& log);

private:
    static LogManager* instance;
    std::ofstream m_logFile;
    std::string const m_filename;
    bool m_fileError;
};

#endif // _LOGMANAGER_H
