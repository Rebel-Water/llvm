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
include CMakeFiles/expr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/expr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/expr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/expr.dir/flags.make

CMakeFiles/expr.dir/main.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/main.cc.o: ../main.cc
CMakeFiles/expr.dir/main.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/expr.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/main.cc.o -MF CMakeFiles/expr.dir/main.cc.o.d -o CMakeFiles/expr.dir/main.cc.o -c /home/ace/llvm_project_1706/subc/main.cc

CMakeFiles/expr.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/main.cc > CMakeFiles/expr.dir/main.cc.i

CMakeFiles/expr.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/main.cc -o CMakeFiles/expr.dir/main.cc.s

CMakeFiles/expr.dir/lexer.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/lexer.cc.o: ../lexer.cc
CMakeFiles/expr.dir/lexer.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/expr.dir/lexer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/lexer.cc.o -MF CMakeFiles/expr.dir/lexer.cc.o.d -o CMakeFiles/expr.dir/lexer.cc.o -c /home/ace/llvm_project_1706/subc/lexer.cc

CMakeFiles/expr.dir/lexer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/lexer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/lexer.cc > CMakeFiles/expr.dir/lexer.cc.i

CMakeFiles/expr.dir/lexer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/lexer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/lexer.cc -o CMakeFiles/expr.dir/lexer.cc.s

CMakeFiles/expr.dir/parser.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/parser.cc.o: ../parser.cc
CMakeFiles/expr.dir/parser.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/expr.dir/parser.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/parser.cc.o -MF CMakeFiles/expr.dir/parser.cc.o.d -o CMakeFiles/expr.dir/parser.cc.o -c /home/ace/llvm_project_1706/subc/parser.cc

CMakeFiles/expr.dir/parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/parser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/parser.cc > CMakeFiles/expr.dir/parser.cc.i

CMakeFiles/expr.dir/parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/parser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/parser.cc -o CMakeFiles/expr.dir/parser.cc.s

CMakeFiles/expr.dir/printVisitor.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/printVisitor.cc.o: ../printVisitor.cc
CMakeFiles/expr.dir/printVisitor.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/expr.dir/printVisitor.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/printVisitor.cc.o -MF CMakeFiles/expr.dir/printVisitor.cc.o.d -o CMakeFiles/expr.dir/printVisitor.cc.o -c /home/ace/llvm_project_1706/subc/printVisitor.cc

CMakeFiles/expr.dir/printVisitor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/printVisitor.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/printVisitor.cc > CMakeFiles/expr.dir/printVisitor.cc.i

CMakeFiles/expr.dir/printVisitor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/printVisitor.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/printVisitor.cc -o CMakeFiles/expr.dir/printVisitor.cc.s

CMakeFiles/expr.dir/type.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/type.cc.o: ../type.cc
CMakeFiles/expr.dir/type.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/expr.dir/type.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/type.cc.o -MF CMakeFiles/expr.dir/type.cc.o.d -o CMakeFiles/expr.dir/type.cc.o -c /home/ace/llvm_project_1706/subc/type.cc

CMakeFiles/expr.dir/type.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/type.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/type.cc > CMakeFiles/expr.dir/type.cc.i

CMakeFiles/expr.dir/type.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/type.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/type.cc -o CMakeFiles/expr.dir/type.cc.s

CMakeFiles/expr.dir/scope.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/scope.cc.o: ../scope.cc
CMakeFiles/expr.dir/scope.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/expr.dir/scope.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/scope.cc.o -MF CMakeFiles/expr.dir/scope.cc.o.d -o CMakeFiles/expr.dir/scope.cc.o -c /home/ace/llvm_project_1706/subc/scope.cc

CMakeFiles/expr.dir/scope.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/scope.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/scope.cc > CMakeFiles/expr.dir/scope.cc.i

CMakeFiles/expr.dir/scope.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/scope.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/scope.cc -o CMakeFiles/expr.dir/scope.cc.s

CMakeFiles/expr.dir/sema.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/sema.cc.o: ../sema.cc
CMakeFiles/expr.dir/sema.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/expr.dir/sema.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/sema.cc.o -MF CMakeFiles/expr.dir/sema.cc.o.d -o CMakeFiles/expr.dir/sema.cc.o -c /home/ace/llvm_project_1706/subc/sema.cc

CMakeFiles/expr.dir/sema.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/sema.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/sema.cc > CMakeFiles/expr.dir/sema.cc.i

CMakeFiles/expr.dir/sema.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/sema.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/sema.cc -o CMakeFiles/expr.dir/sema.cc.s

CMakeFiles/expr.dir/diag_engine.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/diag_engine.cc.o: ../diag_engine.cc
CMakeFiles/expr.dir/diag_engine.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/expr.dir/diag_engine.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/diag_engine.cc.o -MF CMakeFiles/expr.dir/diag_engine.cc.o.d -o CMakeFiles/expr.dir/diag_engine.cc.o -c /home/ace/llvm_project_1706/subc/diag_engine.cc

CMakeFiles/expr.dir/diag_engine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/diag_engine.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/diag_engine.cc > CMakeFiles/expr.dir/diag_engine.cc.i

CMakeFiles/expr.dir/diag_engine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/diag_engine.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/diag_engine.cc -o CMakeFiles/expr.dir/diag_engine.cc.s

CMakeFiles/expr.dir/codegen.cc.o: CMakeFiles/expr.dir/flags.make
CMakeFiles/expr.dir/codegen.cc.o: ../codegen.cc
CMakeFiles/expr.dir/codegen.cc.o: CMakeFiles/expr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/expr.dir/codegen.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expr.dir/codegen.cc.o -MF CMakeFiles/expr.dir/codegen.cc.o.d -o CMakeFiles/expr.dir/codegen.cc.o -c /home/ace/llvm_project_1706/subc/codegen.cc

CMakeFiles/expr.dir/codegen.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/codegen.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm_project_1706/subc/codegen.cc > CMakeFiles/expr.dir/codegen.cc.i

CMakeFiles/expr.dir/codegen.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/codegen.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm_project_1706/subc/codegen.cc -o CMakeFiles/expr.dir/codegen.cc.s

# Object files for target expr
expr_OBJECTS = \
"CMakeFiles/expr.dir/main.cc.o" \
"CMakeFiles/expr.dir/lexer.cc.o" \
"CMakeFiles/expr.dir/parser.cc.o" \
"CMakeFiles/expr.dir/printVisitor.cc.o" \
"CMakeFiles/expr.dir/type.cc.o" \
"CMakeFiles/expr.dir/scope.cc.o" \
"CMakeFiles/expr.dir/sema.cc.o" \
"CMakeFiles/expr.dir/diag_engine.cc.o" \
"CMakeFiles/expr.dir/codegen.cc.o"

# External object files for target expr
expr_EXTERNAL_OBJECTS =

../bin/expr: CMakeFiles/expr.dir/main.cc.o
../bin/expr: CMakeFiles/expr.dir/lexer.cc.o
../bin/expr: CMakeFiles/expr.dir/parser.cc.o
../bin/expr: CMakeFiles/expr.dir/printVisitor.cc.o
../bin/expr: CMakeFiles/expr.dir/type.cc.o
../bin/expr: CMakeFiles/expr.dir/scope.cc.o
../bin/expr: CMakeFiles/expr.dir/sema.cc.o
../bin/expr: CMakeFiles/expr.dir/diag_engine.cc.o
../bin/expr: CMakeFiles/expr.dir/codegen.cc.o
../bin/expr: CMakeFiles/expr.dir/build.make
../bin/expr: /home/ace/llvm_project_1706/llvm_install_dir/lib/libLLVMCore.so.17
../bin/expr: /home/ace/llvm_project_1706/llvm_install_dir/lib/libLLVMSupport.so.17
../bin/expr: CMakeFiles/expr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/llvm_project_1706/subc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../bin/expr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/expr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/expr.dir/build: ../bin/expr
.PHONY : CMakeFiles/expr.dir/build

CMakeFiles/expr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/expr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/expr.dir/clean

CMakeFiles/expr.dir/depend:
	cd /home/ace/llvm_project_1706/subc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/llvm_project_1706/subc /home/ace/llvm_project_1706/subc /home/ace/llvm_project_1706/subc/build /home/ace/llvm_project_1706/subc/build /home/ace/llvm_project_1706/subc/build/CMakeFiles/expr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/expr.dir/depend

