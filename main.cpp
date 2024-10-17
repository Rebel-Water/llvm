#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Constants.h"

int main() {
    llvm::LLVMContext context;
    llvm::Module m("hello_world", context);
    llvm::IRBuilder irBuilder(context);

    // Declare the puts function (int puts(char *str))
    llvm::FunctionType* putsFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), {irBuilder.getInt8PtrTy()}, false);
    llvm::Function* putsFunc = llvm::Function::Create(putsFuncType, llvm::GlobalValue::ExternalLinkage, "puts", m);

    // Create a global constant string "hello, world"
    llvm::Constant* helloWorldStr = llvm::ConstantDataArray::getString(context, "hello, world");
    llvm::GlobalVariable* gvarStr = new llvm::GlobalVariable(
        m, helloWorldStr->getType(), true, llvm::GlobalValue::PrivateLinkage, helloWorldStr, "hello_world_str"
    );

    // Define the main function
    llvm::FunctionType* mainFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), false);
    llvm::Function* mainFunc = llvm::Function::Create(mainFuncType, llvm::GlobalValue::ExternalLinkage, "main", m);

    // Create an entry basic block for main
    llvm::BasicBlock* entryBB = llvm::BasicBlock::Create(context, "entry", mainFunc);
    irBuilder.SetInsertPoint(entryBB);

    // Get the pointer to the string "hello, world"
    llvm::Value* gep = irBuilder.CreateGEP(
        gvarStr->getValueType(), gvarStr, {irBuilder.getInt32(0), irBuilder.getInt32(0)}
    );

    // Call puts function with the string pointer
    irBuilder.CreateCall(putsFunc, {gep}, "call_puts");
    irBuilder.CreateRet(irBuilder.getInt32(0));

    // Verify the function and module
    llvm::verifyFunction(*mainFunc, &llvm::errs());
    llvm::verifyModule(m, &llvm::errs());

    // Print the generated LLVM IR
    m.print(llvm::outs(), nullptr);
    return 0;
}
