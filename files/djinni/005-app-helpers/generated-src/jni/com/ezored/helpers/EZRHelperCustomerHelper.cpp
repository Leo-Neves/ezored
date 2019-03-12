// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#include "com/ezored/helpers/EZRHelperCustomerHelper.hpp"  // my header
#include "Marshal.hpp"
#include "com/ezored/domain/EZRDomainCustomer.hpp"

namespace djinni_generated {

EZRHelperCustomerHelper::EZRHelperCustomerHelper() : ::djinni::JniInterface<::ezored::helpers::CustomerHelper, EZRHelperCustomerHelper>("com/ezored/helpers/CustomerHelper$CppProxy") {}

EZRHelperCustomerHelper::~EZRHelperCustomerHelper() = default;


CJNIEXPORT void JNICALL Java_com_ezored_helpers_CustomerHelper_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ezored::helpers::CustomerHelper>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_com_ezored_helpers_CustomerHelper_00024CppProxy_isLogged(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::helpers::CustomerHelper::isLogged();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_ezored_helpers_CustomerHelper_00024CppProxy_getToken(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::helpers::CustomerHelper::getToken();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT ::djinni_generated::EZRDomainCustomer::JniType JNICALL Java_com_ezored_helpers_CustomerHelper_00024CppProxy_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::helpers::CustomerHelper::create();
        return ::djinni::release(::djinni_generated::EZRDomainCustomer::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_ezored_helpers_CustomerHelper_00024CppProxy_onCustomerLogin(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::EZRDomainCustomer::JniType j_customer)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::ezored::helpers::CustomerHelper::onCustomerLogin(::djinni_generated::EZRDomainCustomer::toCpp(jniEnv, j_customer));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
