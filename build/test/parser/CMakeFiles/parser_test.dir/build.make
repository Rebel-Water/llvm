# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ace/llvm_project_1706/subc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/llvm_project_1706/subc/build

# Include any dependencies generated for this target.
include test/parser/CMakeFiles/parser_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/parser/CMakeFiles/parser_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/parser/CMakeFiles/parser_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/parser/CMakeFiles/parser_test.dir/flags.make

test/parser/CMakeFiles/parser_test.dir/parser_test.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/parser_test.cc.o: ../test/parser/parser_test.cc
test/parser/CMakeFiles/parser_test.dir/parser_test.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/parser/CMakeFiles/parser_test.dir/parser_test.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/parser_test.cc.o -MF CMakeFiles/parser_test.dir/parser_test.cc.o.d -o CMakeFiles/parser_test.dir/parser_test.cc.o -c /home/ace/llvm_project_1706/subc/test/parser/parser_test.cc

test/parser/CMakeFiles/parser_test.dir/parser_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/parser_test.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/test/parser/parser_test.cc > CMakeFiles/parser_test.dir/parser_test.cc.i

test/parser/CMakeFiles/parser_test.dir/parser_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/parser_test.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/test/parser/parser_test.cc -o CMakeFiles/parser_test.dir/parser_test.cc.s

test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.o: ../lexer.cc
test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.o -MF CMakeFiles/parser_test.dir/__/__/lexer.cc.o.d -o CMakeFiles/parser_test.dir/__/__/lexer.cc.o -c /home/ace/llvm_project_1706/subc/lexer.cc

test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/__/__/lexer.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/lexer.cc > CMakeFiles/parser_test.dir/__/__/lexer.cc.i

test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/__/__/lexer.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/lexer.cc -o CMakeFiles/parser_test.dir/__/__/lexer.cc.s

test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.o: ../type.cc
test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.o -MF CMakeFiles/parser_test.dir/__/__/type.cc.o.d -o CMakeFiles/parser_test.dir/__/__/type.cc.o -c /home/ace/llvm_project_1706/subc/type.cc

test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/__/__/type.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/type.cc > CMakeFiles/parser_test.dir/__/__/type.cc.i

test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/__/__/type.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/type.cc -o CMakeFiles/parser_test.dir/__/__/type.cc.s

test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o: ../diag_engine.cc
test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o -MF CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o.d -o CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o -c /home/ace/llvm_project_1706/subc/diag_engine.cc

test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/__/__/diag_engine.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/diag_engine.cc > CMakeFiles/parser_test.dir/__/__/diag_engine.cc.i

test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/__/__/diag_engine.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/diag_engine.cc -o CMakeFiles/parser_test.dir/__/__/diag_engine.cc.s

test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.o: ../parser.cc
test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.o -MF CMakeFiles/parser_test.dir/__/__/parser.cc.o.d -o CMakeFiles/parser_test.dir/__/__/parser.cc.o -c /home/ace/llvm_project_1706/subc/parser.cc

test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/__/__/parser.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/parser.cc > CMakeFiles/parser_test.dir/__/__/parser.cc.i

test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/__/__/parser.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/parser.cc -o CMakeFiles/parser_test.dir/__/__/parser.cc.s

test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o: ../printVisitor.cc
test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o -MF CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o.d -o CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o -c /home/ace/llvm_project_1706/subc/printVisitor.cc

test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/__/__/printVisitor.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/printVisitor.cc > CMakeFiles/parser_test.dir/__/__/printVisitor.cc.i

test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/__/__/printVisitor.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/printVisitor.cc -o CMakeFiles/parser_test.dir/__/__/printVisitor.cc.s

test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.o: ../sema.cc
test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.o -MF CMakeFiles/parser_test.dir/__/__/sema.cc.o.d -o CMakeFiles/parser_test.dir/__/__/sema.cc.o -c /home/ace/llvm_project_1706/subc/sema.cc

test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/__/__/sema.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/sema.cc > CMakeFiles/parser_test.dir/__/__/sema.cc.i

test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/__/__/sema.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/sema.cc -o CMakeFiles/parser_test.dir/__/__/sema.cc.s

test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.o: test/parser/CMakeFiles/parser_test.dir/flags.make
test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.o: ../scope.cc
test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.o: test/parser/CMakeFiles/parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.o"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.o -MF CMakeFiles/parser_test.dir/__/__/scope.cc.o.d -o CMakeFiles/parser_test.dir/__/__/scope.cc.o -c /home/ace/llvm_project_1706/subc/scope.cc

test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_test.dir/__/__/scope.cc.i"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/scope.cc > CMakeFiles/parser_test.dir/__/__/scope.cc.i

test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_test.dir/__/__/scope.cc.s"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/scope.cc -o CMakeFiles/parser_test.dir/__/__/scope.cc.s

# Object files for target parser_test
parser_test_OBJECTS = \
"CMakeFiles/parser_test.dir/parser_test.cc.o" \
"CMakeFiles/parser_test.dir/__/__/lexer.cc.o" \
"CMakeFiles/parser_test.dir/__/__/type.cc.o" \
"CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o" \
"CMakeFiles/parser_test.dir/__/__/parser.cc.o" \
"CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o" \
"CMakeFiles/parser_test.dir/__/__/sema.cc.o" \
"CMakeFiles/parser_test.dir/__/__/scope.cc.o"

# External object files for target parser_test
parser_test_EXTERNAL_OBJECTS =

test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/parser_test.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/__/__/lexer.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/__/__/type.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/__/__/diag_engine.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/__/__/parser.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/__/__/printVisitor.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/__/__/sema.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/__/__/scope.cc.o
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/build.make
test/parser/bin/parser_test: lib/libgtest_main.a
test/parser/bin/parser_test: /home/ace/llvm_project_1706/llvm_install_dir/lib/libLLVMCore.so.17
test/parser/bin/parser_test: lib/libgtest.a
test/parser/bin/parser_test: /home/ace/llvm_project_1706/llvm_install_dir/lib/libLLVMSupport.so.17
test/parser/bin/parser_test: test/parser/CMakeFiles/parser_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable bin/parser_test"
	cd /home/ace/llvm_project_1706/subc/build/test/parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parser_test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/ace/llvm_project_1706/subc/build/test/parser && /usr/bin/cmake -D TEST_TARGET=parser_test -D TEST_EXECUTABLE=/home/ace/llvm_project_1706/subc/build/test/parser/bin/parser_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/ace/llvm_project_1706/subc/build/test/parser -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=parser_test_TESTS -D CTEST_FILE=/home/ace/llvm_project_1706/subc/build/test/parser/parser_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/parser/CMakeFiles/parser_test.dir/build: test/parser/bin/parser_test
.PHONY : test/parser/CMakeFiles/parser_test.dir/build

test/parser/CMakeFiles/parser_test.dir/clean:
	cd /home/ace/llvm_project_1706/subc/build/test/parser && $(CMAKE_COMMAND) -P CMakeFiles/parser_test.dir/cmake_clean.cmake
.PHONY : test/parser/CMakeFiles/parser_test.dir/clean

test/parser/CMakeFiles/parser_test.dir/depend:
	cd /home/ace/llvm_project_1706/subc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/llvm_project_1706/subc /home/ace/llvm_project_1706/subc/test/parser /home/ace/llvm_project_1706/subc/build /home/ace/llvm_project_1706/subc/build/test/parser /home/ace/llvm_project_1706/subc/build/test/parser/CMakeFiles/parser_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/parser/CMakeFiles/parser_test.dir/depend

