#ifndef _LAUNCHOPT_H
#define _LAUNCHOPT_H

#include "Vector2.h"
#include <iostream>
#include "Tools.h"

class LaunchOpt
{
public:
    LaunchOpt(int argc, char** argv);
    void setOptions(Config_Info& _infos);
    void showUsage(void);
    void showVersion(void);

private:
    void parseScreenSize(const char* _raw_size, Vector2& _screenSize);

protected:
    int         m_version_flag;
    std::string m_progname;

    int     m_argc;
    char**  m_argv;
};

#endif // _LAUNCHOPT_H
