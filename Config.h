#ifndef _CONFIG_H
#define _CONFIG_H

// Should rename to Launch.h ?

#include <iostream>
#include <string.h>

#include "LogManager.h"
#include "Vector2.h"
#include "Tools.h"

#define _VERSION "0.0.1"

struct ConfigInfo
{
    bool        fullscreen;
    Vector2     windowSize;
    Vector2     windowPosition;     // only if not fullscreen and not windowCentered
    bool        windowCentered;     // only if not fullscreen
    bool        resizable;
    
    //KeySomething keybind;         // TODO
    //bool        verbose;
};

class Config
{
public:
    Config(int argc, char **argv);
    void loadConfFile(void);
    void setOptions(void);
    void showUsage(void);
    void showVersion(void);

    Vector2 getScreenSize(void) const;
    std::string getCaption(void);
    bool isFullscreen(void) const;
    static bool isVerboseEnabled();

private:
    void parseScreenSize(const char* _raw_size, Vector2& _screenSize);

private:
    static Config* instance;

    bool        m_fullscreen;
    Vector2     m_screenSize;
    int         m_verbose_flag;
    int         m_version_flag;
    std::string m_progname;
    int         m_argc;
    char**      m_argv;
};

#endif // _CONFIG_H
