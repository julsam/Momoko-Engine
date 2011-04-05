#include "../include/LaunchOpt.h"
#include "../include/Tools.h"
#include "../include/LogManager.h"
#include <stdlib.h>
#include <getopt.h> // GNU only

using namespace std;

LaunchOpt::LaunchOpt(int argc, char** argv)
{
    m_argc = argc;
    m_argv = argv;
}

void
LaunchOpt::setOptions(Config_Info& _infos)
{
    m_progname      = m_argv[0];
    _infos.progname = m_argv[0];
    m_version_flag  = 0;
    int c;

    LogManager::getSingleton()->logMessage( "[LaunchOpt] Setting up command line options." );

    while (1) {
        int option_index = 0;

        static struct option long_options[] = {
            /* flag set */
            {"version",     no_argument,    &m_version_flag, 1},
            /* no flag */
            {"verbose",     no_argument,            0, 'v'},
            {"fullscreen",  no_argument,            0, 'f'},
            {"size",        required_argument,      0, 's'},
            {"help",        no_argument,            0, 'h'},
            {0, 0, 0, 0}
        };

        c = getopt_long(m_argc, m_argv, "fs:hvV", long_options, &option_index);

        if (c == -1)
            break;

        switch (c) {
            case 0:
            case 1:
            case 2:
                break;

           case 'f':
                _infos.fullscreen   = true;
                _infos.windowSize.x = 1680;// TODO change this
                _infos.windowSize.y = 1050;
                break;

           case 's':
                try {
                    parseScreenSize(optarg, _infos.windowSize);
                } catch (const string &err) {
                    cerr << err << endl;
                }
                break;

           case 'v':
                _infos.verbose = 1;
                break;

           case 'V':
                m_version_flag = 1;
                break;

           case '?':
           case 'h':
                showUsage();
                break;

            default:
                cout << "?? getopt returned character code 0" << c << "??\n";
        }
    }

    if(m_version_flag)
        showVersion();

    if(_infos.verbose)
    {
        if(_infos.fullscreen)
            LogManager::getSingleton()->logMessage("[LaunchOpt] Set fullscreen.");
        else
            LogManager::getSingleton()->logMessage("[LaunchOpt] Set windowed mode.");

        LogManager::getSingleton()->logMessage("[LaunchOpt] Screen size = " 
                +  to_str<Vector2>(_infos.windowSize));
    }

    LogManager::getSingleton()->logMessage( "[LaunchOpt] Setup is done." );
}

void
LaunchOpt::showUsage(void)
{
    cout << "Usage: " << m_progname << " [ options ... ]\n"
            "\t-h, --help\t\t\tShow this page\n"
            "\t-f, --fullscreen\t\tSet fullscreen\n"
            "\t-s SIZE, --size=SIZE\t\tSet window size. "
            "Example : " << m_progname << " --size=1024x768\n"
            "\t-v, --verbose\t\t\tSet verbose mode\n"
            "\t-V, --version\t\t\tShow program version\n"
            ;
    exit(1);
}

void
LaunchOpt::showVersion(void)
{
    cout << m_progname + " " << _VERSION << endl;
    exit(1);
}

void
LaunchOpt::parseScreenSize(const char* _raw_size, Vector2& _screenSize)
{
    string raw_size(_raw_size);
    unsigned int i = 0;
    unsigned int max = 4;
    // 48 = 0, 57 = 9 in ASCII
    // maybe not the right way to do that
    while((int)raw_size[i] >= 48 && (int)raw_size[i] <= 57
            && i < raw_size.size() && i <= max)
        i++;
    if(i >= raw_size.size() || i == 0 || i > max)
    {
        throw string("Outranged or uncorrect screen size. Set values to default.");
        return;
    }
    _screenSize.x = atoi(raw_size.substr(0, i).c_str());
    _screenSize.y = atoi(raw_size.substr(i+1, raw_size.size()-1).c_str());
}

