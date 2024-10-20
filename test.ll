; ModuleID = 'variable'
source_filename = "variable"

@0 = private unnamed_addr constant [14 x i8] c"expr val: %d\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32 3, i32* %a, align 4
  %b = alloca i32, align 4
  store i32 4, i32* %b, align 4
  %a1 = load i32, i32* %a, align 4
  %b2 = load i32, i32* %b, align 4
  %0 = mul nsw i32 %b2, 4
  %1 = add nsw i32 %a1, %0
  %2 = add nsw i32 %1, 5
  %3 = call i32 (i8*, ...) @printf([14 x i8]* @0, i32 %2)
  ret i32 0
}
