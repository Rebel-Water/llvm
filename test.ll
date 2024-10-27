; ModuleID = 'variable'
source_filename = "variable"

@0 = private unnamed_addr constant [14 x i8] c"expr val: %d\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %aa = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 3, i32* %b, align 4
  %b1 = load i32, i32* %b, align 4
  store i32 0, i32* %aa, align 4
  %aa2 = load i32, i32* %aa, align 4
  store i32 4, i32* %b, align 4
  %b3 = load i32, i32* %b, align 4
  store i32 %b3, i32* %aa, align 4
  %aa4 = load i32, i32* %aa, align 4
  br label %cond

cond:                                             ; preds = %entry
  br i1 false, label %then, label %else

then:                                             ; preds = %cond
  store i32 29, i32* %aa, align 4
  %aa5 = load i32, i32* %aa, align 4
  br label %last

else:                                             ; preds = %cond
  store i32 0, i32* %aa, align 4
  %aa6 = load i32, i32* %aa, align 4
  br label %last

last:                                             ; preds = %else, %then
  %aa7 = load i32, i32* %aa, align 4
  %b8 = load i32, i32* %b, align 4
  %0 = mul nsw i32 %b8, 3
  %1 = add nsw i32 %aa7, %0
  %2 = add nsw i32 %1, 5
  %3 = call i32 (i8*, ...) @printf([14 x i8]* @0, i32 %2)
  ret i32 0
}
