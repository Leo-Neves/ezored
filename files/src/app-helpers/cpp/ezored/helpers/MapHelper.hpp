#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "rapidjson/document.h"

using std::string;
using std::unordered_map;
using std::vector;
using rapidjson::Document;

namespace ezored
{
namespace helpers
{

class MapHelper
{
public:
    virtual ~MapHelper() {}

    static Document toJson(const string &data);
    static string toString(const Document &json);
    static string toJsonString(const unordered_map<string, string> &data);
    static unordered_map<string, string> fromJsonString(const string &data);
    static string getValue(const string &key, const unordered_map<string, string> &data, const string &defaultValue);
    static string getString(const string key, const Document &data);
    static int getInt(const string &key, const Document &data);
    static double getDouble(const string &key, const Document &data);
    static bool getBool(const string &key, const Document &data);
    static std::chrono::system_clock::time_point getDate(const string &key, const Document &data, const string &dateFormat);
};

} // namespace helpers
} // namespace ezored

