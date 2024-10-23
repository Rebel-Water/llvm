; ModuleID = 'variable'
source_filename = "variable"

@0 = private unnamed_addr constant [14 x i8] c"expr val: %d\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 4, i32* %b, align 4
  %b1 = load i32, i32* %b, align 4
  store i32 5, i32* %b, align 4
  %b2 = load i32, i32* %b, align 4
  store i32 %b2, i32* %a, align 4
  %a3 = load i32, i32* %a, align 4
  %a4 = load i32, i32* %a, align 4
  %b5 = load i32, i32* %b, align 4
  %0 = mul nsw i32 %b5, 9
  %1 = add nsw i32 %a4, %0
  %2 = call i32 (i8*, ...) @printf([14 x i8]* @0, i32 %1)
  ret i32 0
}
