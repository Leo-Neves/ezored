// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include "djinni_support.hpp"
#include "ezored/net/http/HttpClient.hpp"

namespace djinni_generated {

class EZRHttpClient final : ::djinni::JniInterface<::ezored::net::http::HttpClient, EZRHttpClient> {
public:
    using CppType = std::shared_ptr<::ezored::net::http::HttpClient>;
    using CppOptType = std::shared_ptr<::ezored::net::http::HttpClient>;
    using JniType = jobject;

    using Boxed = EZRHttpClient;

    ~EZRHttpClient();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<EZRHttpClient>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<EZRHttpClient>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    EZRHttpClient();
    friend ::djinni::JniClass<EZRHttpClient>;
    friend ::djinni::JniInterface<::ezored::net::http::HttpClient, EZRHttpClient>;

};

}  // namespace djinni_generated
