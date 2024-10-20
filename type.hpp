#pragma once

enum class TypeKind {
    INT,
};

class CType {
    private:
        TypeKind type;
        int size;
        int align;
    public:
        CType(TypeKind type, int size, int align) : type(type), size(size), align(align) {}
        static CType* GetIntTy();


};