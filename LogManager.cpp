#include "LogManager.h"

using namespace std;

LogManager* LogManager::instance = NULL;

LogManager::LogManager() : m_filename("game.log"), m_fileError(false)
{
    instance = this;
}

void
LogManager::init()
{
    if(!Utils::clearFileContent(m_filename))
    {
        LogManager::logMessage("Could not find/modifie the log file : " + m_filename);
        LogManager::logMessage("A new one will be create");
    }
}

LogManager*
LogManager::getSingleton()
{
    return instance;
}

void
LogManager::logMessage(const bool _bool)
{
    string msg = string(_bool ? "true" : "false");
    instance->writeToFile(msg);
}

void
LogManager::logMessage(const char* _char)
{
    string msg = string(_char);
    instance->writeToFile(msg);
}

void
LogManager::logMessage(const int _num)
{
    string msg = string((char*)_num);
    instance->writeToFile(msg);
}

void
LogManager::logMessage(const long _num)
{
    string msg = string((char*)_num);
    instance->writeToFile(msg);
}

void
LogManager::logMessage(const float _num)
{
    string msg = string((char*)int(_num));
    instance->writeToFile(msg);
}

void
LogManager::logMessage(const double _num)
{
    string msg = string((char*)int(_num));
    instance->writeToFile(msg);
}

void
LogManager::logMessage(const Vector2 _vec)
{
    string msg = string("(") + string((char*)int(_vec.x)) + string(", ") 
        + string((char*)int(_vec.y)) + string(")");
    instance->writeToFile(msg);
}

void
LogManager::logMessage(const std::string& _msg)
{
    string msg = string(_msg);
    instance->writeToFile(msg);
}

void
LogManager::output(const std::string& log)
{
    cout << log << endl;
}

void
LogManager::writeToFile(const std::string& log)
{
    // display if in verbose mode
    if(Config::isVerboseEnabled())
        instance->output(log);

    // if no error write to the file
    if(!instance->m_fileError)
    {
        if(!Utils::writeEndFile(instance->m_filename, log))
        {
            instance->m_fileError = true;
            LogManager::logMessage("Couldn't open log file.");
        }
    }
}
