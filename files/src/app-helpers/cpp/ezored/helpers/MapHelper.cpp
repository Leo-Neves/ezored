#include "MapHelper.hpp"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using std::string;
using std::unordered_map;
using rapidjson::StringBuffer;
using rapidjson::Writer;
using rapidjson::SizeType;
using rapidjson::Document;

namespace ezored
{
namespace helpers
{

Document MapHelper::toJson(const string &data){
    Document json;
    json.Parse(data.c_str());
    return json;
}

string MapHelper::toString(const Document &json){
    StringBuffer buffer;
    buffer.Clear();
    Writer<StringBuffer> writer(buffer);
    json.Accept(writer);
    return string(buffer.GetString());
}

string MapHelper::toJsonString(const unordered_map<string, string> &data)
{
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();

    for (auto &kv : data)
    {
        writer.Key(kv.first.c_str());
        writer.String(kv.second.c_str());
    }

    writer.EndObject();

    return s.GetString();
}

unordered_map<string, string> MapHelper::fromJsonString(const string &data)
{
    auto map = unordered_map<string, string>{};

    Document json;
    json.Parse(data.c_str());

    if (json.IsObject())
    {
        for (rapidjson::Value::ConstMemberIterator itr = json.MemberBegin(); itr != json.MemberEnd(); ++itr)
        {
            map[itr->name.GetString()] = itr->value.GetString();
        }
    }

    return map;
}

string MapHelper::getValue(const string &key, const unordered_map<string, string> &data, const string &defaultValue)
{
    auto it = data.find(key);

    if (it == data.end())
    {
        return defaultValue;
    }

    return it->second;
}

string MapHelper::getString(const string key, const Document &data)
{
    char cstr[key.size() + 1];
	strcpy(cstr, key.c_str());
    if (data.IsObject())
        if (data.GetObject()[cstr].IsString())
            return string(data.GetObject()[cstr].GetString());
	return "";
}

int MapHelper::getInt(const string &key, const Document &data)
{
    char cstr[key.size() + 1];
	strcpy(cstr, key.c_str());
    if (data.IsObject())
        if (data.GetObject()[cstr].IsInt())
            return data.GetObject()[cstr].GetInt();
	return 0;
}

bool MapHelper::getBool(const string &key, const Document &data)
{
    char cstr[key.size() + 1];
	strcpy(cstr, key.c_str());
    if (data.IsObject())
        if (data.GetObject()[cstr].IsBool())
            return data.GetObject()[cstr].GetBool();
	return false;
}

double MapHelper::getDouble(const string &key, const Document &data)
{
    char cstr[key.size() + 1];
	strcpy(cstr, key.c_str());
    if (data.IsObject())
        if (data.GetObject()[cstr].IsDouble())
            return data.GetObject()[cstr].GetDouble();
	return 0;
}

} // namespace helpers
} // namespace ezored

