// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include <string>

namespace ezored { namespace util {

class LoggerPlatformService {
public:
    virtual ~LoggerPlatformService() {}

    virtual void v(const std::string & message) = 0;

    virtual void d(const std::string & message) = 0;

    virtual void i(const std::string & message) = 0;

    virtual void w(const std::string & message) = 0;

    virtual void e(const std::string & message) = 0;

    virtual void f(const std::string & message) = 0;

    virtual void setGroup(const std::string & group) = 0;
};

} }  // namespace ezored::util
