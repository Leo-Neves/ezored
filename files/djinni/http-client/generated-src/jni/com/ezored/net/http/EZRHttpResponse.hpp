// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include "djinni_support.hpp"
#include "ezored/net/http/HttpResponse.hpp"

namespace djinni_generated {

class EZRHttpResponse final {
public:
    using CppType = ::ezored::net::http::HttpResponse;
    using JniType = jobject;

    using Boxed = EZRHttpResponse;

    ~EZRHttpResponse();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    EZRHttpResponse();
    friend ::djinni::JniClass<EZRHttpResponse>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/ezored/net/http/HttpResponse") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(ILjava/lang/String;Ljava/lang/String;Ljava/util/ArrayList;)V") };
    const jfieldID field_mCode { ::djinni::jniGetFieldID(clazz.get(), "mCode", "I") };
    const jfieldID field_mBody { ::djinni::jniGetFieldID(clazz.get(), "mBody", "Ljava/lang/String;") };
    const jfieldID field_mUrl { ::djinni::jniGetFieldID(clazz.get(), "mUrl", "Ljava/lang/String;") };
    const jfieldID field_mHeaders { ::djinni::jniGetFieldID(clazz.get(), "mHeaders", "Ljava/util/ArrayList;") };
};

}  // namespace djinni_generated
