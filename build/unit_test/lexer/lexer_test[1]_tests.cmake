add_test( LexerTest.NextToken /home/ace/llvm-project/project/build/unit_test/lexer/bin/lexer_test [==[--gtest_filter=LexerTest.NextToken]==] --gtest_also_run_disabled_tests)
set_tests_properties( LexerTest.NextToken PROPERTIES WORKING_DIRECTORY /home/ace/llvm-project/project/build/unit_test/lexer SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( lexer_test_TESTS LexerTest.NextToken)
