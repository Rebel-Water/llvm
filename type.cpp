#include "type.hpp"

CType *CType::GetIntTy()
{
    static CType type(TypeKind::INT, 4, 4);
    return &type;
}