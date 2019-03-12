// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#include "ezored/dataservices/TodoDataService.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class EZRDataServiceTodoDataService;

namespace djinni_generated {

class TodoDataService
{
public:
    using CppType = std::shared_ptr<::ezored::dataservices::TodoDataService>;
    using CppOptType = std::shared_ptr<::ezored::dataservices::TodoDataService>;
    using ObjcType = EZRDataServiceTodoDataService*;

    using Boxed = TodoDataService;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

