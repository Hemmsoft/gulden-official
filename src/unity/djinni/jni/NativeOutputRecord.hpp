// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#pragma once

#include "djinni_support.hpp"
#include "output_record.hpp"

namespace djinni_generated {

class NativeOutputRecord final {
public:
    using CppType = ::OutputRecord;
    using JniType = jobject;

    using Boxed = NativeOutputRecord;

    ~NativeOutputRecord();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeOutputRecord();
    friend ::djinni::JniClass<NativeOutputRecord>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/gulden/jniunifiedbackend/OutputRecord") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V") };
    const jfieldID field_mAmount { ::djinni::jniGetFieldID(clazz.get(), "mAmount", "J") };
    const jfieldID field_mAddress { ::djinni::jniGetFieldID(clazz.get(), "mAddress", "Ljava/lang/String;") };
    const jfieldID field_mLabel { ::djinni::jniGetFieldID(clazz.get(), "mLabel", "Ljava/lang/String;") };
    const jfieldID field_mDescription { ::djinni::jniGetFieldID(clazz.get(), "mDescription", "Ljava/lang/String;") };
    const jfieldID field_mIsMine { ::djinni::jniGetFieldID(clazz.get(), "mIsMine", "Z") };
};

}  // namespace djinni_generated
