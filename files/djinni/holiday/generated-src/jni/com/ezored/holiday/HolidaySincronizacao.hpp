// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include "djinni_support.hpp"
#include "ezored/holiday/Sincronizacao.hpp"

namespace djinni_generated {

class HolidaySincronizacao final : ::djinni::JniInterface<::ezored::holiday::Sincronizacao, HolidaySincronizacao> {
public:
    using CppType = std::shared_ptr<::ezored::holiday::Sincronizacao>;
    using CppOptType = std::shared_ptr<::ezored::holiday::Sincronizacao>;
    using JniType = jobject;

    using Boxed = HolidaySincronizacao;

    ~HolidaySincronizacao();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<HolidaySincronizacao>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<HolidaySincronizacao>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    HolidaySincronizacao();
    friend ::djinni::JniClass<HolidaySincronizacao>;
    friend ::djinni::JniInterface<::ezored::holiday::Sincronizacao, HolidaySincronizacao>;

};

}  // namespace djinni_generated
