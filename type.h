#pragma once
#include <memory>
#include "llvm/IR/Type.h"

class CPrimaryType;
class CPointType;
class CArrayType;

class TypeVisitor {
public:
    virtual ~TypeVisitor() {}
    virtual llvm::Type * VisitPrimaryType(CPrimaryType *ty) = 0;
    virtual llvm::Type * VisitPointType(CPointType *ty) = 0;
    virtual llvm::Type * VisitArrayType(CArrayType*ty) = 0;
};

class CType {
public:
    enum Kind {
        TY_Int,
        TY_Point,
        TY_Array
    };
private:
    Kind kind;
    int size;       /// 字节数
    int align;      /// 对齐数
public:
    CType(Kind kind, int size, int align):kind(kind), size(size), align(align) {}
    virtual ~CType() {}
    const Kind GetKind() const {return kind;}
    const int GetSize() const {return size;}
    const int GetAlign() const {return align;}
    virtual llvm::Type * Accept(TypeVisitor *v) {return nullptr;}

    static std::shared_ptr<CType> IntType;
};

class CPrimaryType : public CType {
public:
    CPrimaryType(Kind kind, int size, int align):CType(kind, size, align) {}
    
    llvm::Type * Accept(TypeVisitor *v) override {
        return v->VisitPrimaryType(this);
    }
    
    static bool classof(const CType *ty) {
        return ty->GetKind() == TY_Int;
    }
};

class CPointType : public CType{
private:
    std::shared_ptr<CType> baseType;
public:
    CPointType(std::shared_ptr<CType> baseType):CType(Kind::TY_Point, 8, 8), baseType(baseType) {}
    
    std::shared_ptr<CType> GetBaseType() {
        return baseType;
    }

    llvm::Type * Accept(TypeVisitor *v) override {
        return v->VisitPointType(this);
    }

    static bool classof(const CType *ty) {
        return ty->GetKind() == TY_Point;
    }
};

class CArrayType : public CType {
    private:
    std::shared_ptr<CType> elementType;
    int elementCount;
    public:
    CArrayType(std::shared_ptr<CType> elementType, int elementCount)
        : CType(Kind::TY_Array, elementCount * elementType->GetSize(), elementType->GetAlign()), elementType(elementType), elementCount(elementCount) {}
    
    std::shared_ptr<CType> GetElementType() {
        return elementType;
    }

    const int GetElement() const {
        return elementCount;
    }

    llvm::Type* Accept(TypeVisitor* v) override {
        return v->VisitArrayType(this);
    }

    static bool classof(const CType* ty) {
        return ty->GetKind() == TY_Array;
    }

};