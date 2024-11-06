#/bin/zsh

cd build
make -j4
cd ..
./bin/lexer_test
./bin/parser_test
./bin/codegen_test