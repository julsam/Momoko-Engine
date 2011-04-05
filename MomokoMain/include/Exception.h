#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception
{
public:
    const char* what() const throw() { return m_message.c_str(); }

    Exception(const std::string& message="") : m_message(message) { }
    virtual ~Exception() throw() { }

    std::string m_message;
};

#endif // _EXCEPTION_H
