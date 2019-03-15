// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import "ezored/util/EZRLoggerPlatformService+Private.h"
#import "ezored/util/EZRLoggerPlatformService.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"
#include <stdexcept>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class LoggerPlatformService::ObjcProxy final
: public ::ezored::util::LoggerPlatformService
, private ::djinni::ObjcProxyBase<ObjcType>
{
    friend class ::djinni_generated::LoggerPlatformService;
public:
    using ObjcProxyBase::ObjcProxyBase;
    void v(const std::string & c_message) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() v:(::djinni::String::fromCpp(c_message))];
        }
    }
    void d(const std::string & c_message) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() d:(::djinni::String::fromCpp(c_message))];
        }
    }
    void i(const std::string & c_message) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() i:(::djinni::String::fromCpp(c_message))];
        }
    }
    void w(const std::string & c_message) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() w:(::djinni::String::fromCpp(c_message))];
        }
    }
    void e(const std::string & c_message) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() e:(::djinni::String::fromCpp(c_message))];
        }
    }
    void setGroup(const std::string & c_group) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() setGroup:(::djinni::String::fromCpp(c_group))];
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto LoggerPlatformService::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto LoggerPlatformService::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).djinni_private_get_proxied_objc_object();
}

}  // namespace djinni_generated
