#include "Utils.h"

using namespace std;


/**
 * Clear a file content.
 * @param   _filename   Filename string.
 * @return  True if the file is found and if the content
 *          has been cleared.
 *          False if no file, or file could not be modified.
 */
bool
Utils::clearFileContent(const string& _filename)
{
    // Does file exist?
    fstream f(_filename.c_str(), ios::in);
    if (f)
    {
        f.close();
        // truncate the file in order to clear content
        f.open(_filename.c_str(), ios::out | ios::trunc);
    }

    return(f ? true : false);
}

/**
 * Write content at the end of a file.
 * @param   _filename   Filename string.
 * @param   _content    Content string.
 * @return  False if couldn't write in the file,
 *          else True.
 */
bool
Utils::writeEndFile(const string& _filename, const string& _content)
{
    ofstream f;
    f.open(_filename.c_str(), ios::app);
    if(!f)
        return false;

    f << _content << endl;
    f.close();

    return true;
}


