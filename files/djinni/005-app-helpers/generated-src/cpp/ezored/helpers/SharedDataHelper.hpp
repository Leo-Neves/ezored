// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include "ezored/domain/Customer.hpp"

namespace ezored { namespace helpers {

class SharedDataHelper {
public:
    virtual ~SharedDataHelper() {}

    static void setCustomer(const ::ezored::domain::Customer & value);

    static ::ezored::domain::Customer getCustomer();

    static void storeCustomer();

    static void setDemoFlag(bool value);

    static bool getDemoFlag();
};

} }  // namespace ezored::helpers
