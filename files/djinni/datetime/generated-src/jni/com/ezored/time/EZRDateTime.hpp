// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include "djinni_support.hpp"
#include "ezored/time/DateTime.hpp"

namespace djinni_generated {

class EZRDateTime final : ::djinni::JniInterface<::ezored::time::DateTime, EZRDateTime> {
public:
    using CppType = std::shared_ptr<::ezored::time::DateTime>;
    using CppOptType = std::shared_ptr<::ezored::time::DateTime>;
    using JniType = jobject;

    using Boxed = EZRDateTime;

    ~EZRDateTime();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<EZRDateTime>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<EZRDateTime>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    EZRDateTime();
    friend ::djinni::JniClass<EZRDateTime>;
    friend ::djinni::JniInterface<::ezored::time::DateTime, EZRDateTime>;

};

}  // namespace djinni_generated
