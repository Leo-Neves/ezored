// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace ezored { namespace domain {

struct Customer final {
    int64_t id;
    std::string name;
    std::string token;

    Customer(int64_t id_,
             std::string name_,
             std::string token_)
    : id(std::move(id_))
    , name(std::move(name_))
    , token(std::move(token_))
    {}
};

} }  // namespace ezored::domain
