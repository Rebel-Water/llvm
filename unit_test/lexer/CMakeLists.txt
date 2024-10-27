enable_testing()

include_directories(../../)

add_executable(
  lexer_test
  lexer_test.cpp
  ../../lexer.cpp
  ../../type.cpp
  ../../diag_engine.cpp
)


llvm_map_components_to_libnames(llvm_all ${LLVM_TARGETS_TO_BUILD} Support Core)

target_link_libraries(
  lexer_test
  GTest::gtest_main
  ${llvm_all}
)

include(GoogleTest)
gtest_discover_tests(lexer_test)
