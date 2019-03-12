// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include <chrono>
#include <cstdint>
#include <string>

namespace ezored { namespace time {

class DateTime {
public:
    virtual ~DateTime() {}

    static std::chrono::system_clock::time_point getDateTimeFromString(const std::string & value);

    static std::string getStringFromDateTime(const std::chrono::system_clock::time_point & value);

    static std::string getCurrentDateTimeAsString();

    static std::chrono::system_clock::time_point getCurrentDateTime();

    static std::chrono::system_clock::time_point getDateTimeFromSeconds(int64_t value);

    static std::chrono::system_clock::time_point getDateTimeFromMilliseconds(int64_t value);

    static int64_t getTimestampInMillisecondsFromDateTime(const std::chrono::system_clock::time_point & value);

    static int64_t getTimestampInSecondsFromDateTime(const std::chrono::system_clock::time_point & value);
};

} }  // namespace ezored::time
