; ModuleID = 'expr'
source_filename = "expr"

@0 = private unnamed_addr constant [14 x i8] c"expr val: %d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32 1, ptr %a, align 4
  %b = alloca i32, align 4
  store i32 0, ptr %b, align 4
  %a1 = alloca i32, align 4
  store i32 2, ptr %a1, align 4
  %b2 = load i32, ptr %b, align 4
  %a3 = load i32, ptr %a, align 4
  store i32 %a3, ptr %b, align 4
  %b4 = load i32, ptr %b, align 4
  %0 = call i32 (ptr, ...) @printf(ptr @0, i32 %b4)
  ret i32 %b4
}
