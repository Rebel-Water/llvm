#/bin/zsh

cd build
make -j4
cd ..
/home/ace/llvm_project_1706/subc/build/test/lexer/bin/lexer_test
/home/ace/llvm_project_1706/subc/build/test/parser/bin/parser_test
/home/ace/llvm_project_1706/subc/build/test/codegen/bin/codegen_test