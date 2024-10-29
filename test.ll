; ModuleID = 'variable'
source_filename = "variable"

@0 = private unnamed_addr constant [14 x i8] c"expr val: %d\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %aa = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 4, i32* %b, align 4
  %b1 = load i32, i32* %b, align 4
  store i32 1, i32* %aa, align 4
  %aa2 = load i32, i32* %aa, align 4
  store i32 -2, i32* %b, align 4
  %b3 = load i32, i32* %b, align 4
  store i32 %b3, i32* %aa, align 4
  %aa4 = load i32, i32* %aa, align 4
  br label %cond

cond:                                             ; preds = %entry
  %b5 = load i32, i32* %b, align 4
  %0 = icmp ne i32 %b5, 0
  %1 = sext i1 %0 to i32
  %2 = icmp ne i32 %1, 0
  br i1 %2, label %then, label %else

then:                                             ; preds = %cond
  br label %cond6

else:                                             ; preds = %cond
  store i32 19, i32* %b, align 4
  %b13 = load i32, i32* %b, align 4
  br label %last

last:                                             ; preds = %else, %last9
  %aa14 = load i32, i32* %aa, align 4
  %b15 = load i32, i32* %b, align 4
  %3 = mul nsw i32 %b15, 9
  %4 = add nsw i32 %aa14, %3
  %5 = call i32 (i8*, ...) @printf([14 x i8]* @0, i32 %4)
  ret i32 0

cond6:                                            ; preds = %then
  br i1 false, label %then7, label %else8

then7:                                            ; preds = %cond6
  store i32 9, i32* %b, align 4
  %b10 = load i32, i32* %b, align 4
  store i32 19, i32* %aa, align 4
  %aa11 = load i32, i32* %aa, align 4
  br label %last9

else8:                                            ; preds = %cond6
  store i32 30, i32* %aa, align 4
  %aa12 = load i32, i32* %aa, align 4
  br label %last9

last9:                                            ; preds = %else8, %then7
  br label %last
}
