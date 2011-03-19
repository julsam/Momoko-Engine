#ifndef _CONFIG_H
#define _CONFIG_H

#include <iostream>
#include <string.h>

#define _VERSION "0.0.1"

class Config
{
public:
    Config(int argc, char **argv);
    void loadConfFile(void);
    void setOptions(void);
    void showUsage(void);
    void showVersion(void);

    int getScreenWidth(void) const;
    int getScreenHeight(void) const;
    std::string getCaption(void);
    bool isFullscreen(void) const;
    static bool isVerboseEnabled();

private:
    void parseScreenSize(const char* _raw_size, int &_w, int &_h);

private:
    static Config* instance;

    bool        m_fullscreen;
    int         m_screenWidth;
    int         m_screenHeight;
    int         m_verbose_flag;
    int         m_version_flag;
    std::string m_progname;
    int         m_argc;
    char**      m_argv;
};

#endif // _CONFIG_H
