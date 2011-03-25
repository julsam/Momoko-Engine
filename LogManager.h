#ifndef _LOGMANAGER_H
#define _LOGMANAGER_H

#include <iostream>
#include <string.h>
#include <fstream>

#include "Vector2.h"


class LogManager
{
public:
    enum LogMessageLevel
    {
        LML_TRIVIAL = 1,
        LML_NORMAL = 2,
        LML_CRITICAL = 3
    };

public:
    LogManager();
    void init();
    static LogManager* getSingleton();
    static void setTimeStampEnabled(bool b);

    static void logMessage(const bool _bool, const LogMessageLevel lml=LML_NORMAL);
    static void logMessage(const char* _char, const LogMessageLevel lml=LML_NORMAL);
    static void logMessage(const int _num, const LogMessageLevel lml=LML_NORMAL);
    static void logMessage(const long _num, const LogMessageLevel lml=LML_NORMAL);
    static void logMessage(const float _num, const LogMessageLevel lml=LML_NORMAL);
    static void logMessage(const double _num, const LogMessageLevel lml=LML_NORMAL);
    static void logMessage(const Vector2 _vec, const LogMessageLevel lml=LML_NORMAL);
    static void logMessage(const std::string& _msg, const LogMessageLevel lml=LML_NORMAL);

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
