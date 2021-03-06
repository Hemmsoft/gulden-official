// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBInputRecord+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto InputRecord::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.address),
            ::djinni::String::toCpp(obj.label),
            ::djinni::Bool::toCpp(obj.isMine)};
}

auto InputRecord::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[DBInputRecord alloc] initWithAddress:(::djinni::String::fromCpp(cpp.address))
                                            label:(::djinni::String::fromCpp(cpp.label))
                                           isMine:(::djinni::Bool::fromCpp(cpp.isMine))];
}

}  // namespace djinni_generated
