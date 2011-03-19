#include <stdlib.h>
#include <getopt.h> // GNU only

#include "Config.h"

using namespace std;

Config* Config::instance = NULL;

Config::Config(int argc, char **argv)
{
    instance = this;
    m_argc = argc;
    m_argv = argv;
    setOptions();
}

void
Config::setOptions(void)
{
    instance->m_progname      = m_argv[0];
    instance->m_fullscreen    = false;
    instance->m_screenWidth   = 640;
    instance->m_screenHeight  = 480;

    int c;
    instance->m_verbose_flag = 0;
    instance->m_version_flag = 0;

    while (1) {
        int option_index = 0;

        static struct option long_options[] = {
            /* flag set */
            {"verbose",     no_argument,    &m_verbose_flag, 1},
            {"version",     no_argument,    &m_version_flag, 1},
            /* no flag */
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
                instance->m_fullscreen   = true;
                instance->m_screenWidth  = 1680;
                instance->m_screenHeight = 1050;
                break;

           case 's':
                try {
                    parseScreenSize(optarg, instance->m_screenWidth, 
                            instance->m_screenHeight);
                } catch (const string &err) {
                    cerr << err << endl;
                }
                break;

           case 'v':
                instance->m_verbose_flag = 1;
                break;

           case 'V':
                instance->m_version_flag = 1;
                break;

           case '?':
           case 'h':
                showUsage();
                break;

            default:
                cout << "?? getopt returned character code 0" << c << "??\n";
        }
    }

    if(instance->m_version_flag)
        showVersion();

    if(instance->m_verbose_flag)
    {
        if(instance->m_fullscreen)
            cout << "Set fullscreen" << endl;
        else
            cout << "Set windowed mode" << endl;
        cout << "Screen size = " << instance->m_screenWidth << "x" 
            << instance->m_screenHeight << endl;
    }
}

void
Config::showUsage(void)
{
    cout << "Usage: " << instance->m_progname << " [ options ... ]\n"
            "\t-h, --help\t\t\tShow this page\n"
            "\t-f, --fullscreen\t\tSet fullscreen\n"
            "\t-s SIZE, --size=SIZE\t\tSet window size. "
            "Example : " << instance->m_progname << " --size=1024x768\n"
            "\t-v, --verbose\t\t\tSet verbose mode\n"
            "\t-V, --version\t\t\tShow program version\n"
            ;
    exit(1);
}

void
Config::showVersion(void)
{
    cout << instance->m_progname + " " << _VERSION << endl;
    exit(1);
}


int
Config::getScreenWidth(void) const
{
    return instance->m_screenWidth;
}

int
Config::getScreenHeight(void) const
{
    return instance->m_screenHeight;
}

std::string 
Config::getCaption(void)
{
    return instance->m_progname;
}

bool
Config::isFullscreen(void) const
{
    return instance->m_fullscreen;
}

void
Config::parseScreenSize(const char* _raw_size, int &_w, int &_h)
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
    _w = atoi(raw_size.substr(0, i).c_str());
    _h = atoi(raw_size.substr(i+1, raw_size.size()-1).c_str());
}

