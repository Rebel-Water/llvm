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
CMAKE_SOURCE_DIR = /home/ace/llvm-project/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/llvm-project/project/build

# Include any dependencies generated for this target.
include unit_test/lexer/CMakeFiles/lexer_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include unit_test/lexer/CMakeFiles/lexer_test.dir/compiler_depend.make

# Include the progress variables for this target.
include unit_test/lexer/CMakeFiles/lexer_test.dir/progress.make

# Include the compile flags for this target's objects.
include unit_test/lexer/CMakeFiles/lexer_test.dir/flags.make

unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/flags.make
unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.o: ../unit_test/lexer/lexer_test.cpp
unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm-project/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.o"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.o -MF CMakeFiles/lexer_test.dir/lexer_test.cpp.o.d -o CMakeFiles/lexer_test.dir/lexer_test.cpp.o -c /home/ace/llvm-project/project/unit_test/lexer/lexer_test.cpp

unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexer_test.dir/lexer_test.cpp.i"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm-project/project/unit_test/lexer/lexer_test.cpp > CMakeFiles/lexer_test.dir/lexer_test.cpp.i

unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexer_test.dir/lexer_test.cpp.s"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm-project/project/unit_test/lexer/lexer_test.cpp -o CMakeFiles/lexer_test.dir/lexer_test.cpp.s

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/flags.make
unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o: ../lexer.cpp
unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm-project/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o -MF CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o.d -o CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o -c /home/ace/llvm-project/project/lexer.cpp

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexer_test.dir/__/__/lexer.cpp.i"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm-project/project/lexer.cpp > CMakeFiles/lexer_test.dir/__/__/lexer.cpp.i

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexer_test.dir/__/__/lexer.cpp.s"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm-project/project/lexer.cpp -o CMakeFiles/lexer_test.dir/__/__/lexer.cpp.s

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/flags.make
unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.o: ../type.cpp
unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm-project/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.o"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.o -MF CMakeFiles/lexer_test.dir/__/__/type.cpp.o.d -o CMakeFiles/lexer_test.dir/__/__/type.cpp.o -c /home/ace/llvm-project/project/type.cpp

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexer_test.dir/__/__/type.cpp.i"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm-project/project/type.cpp > CMakeFiles/lexer_test.dir/__/__/type.cpp.i

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexer_test.dir/__/__/type.cpp.s"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm-project/project/type.cpp -o CMakeFiles/lexer_test.dir/__/__/type.cpp.s

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/flags.make
unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o: ../diag_engine.cpp
unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o: unit_test/lexer/CMakeFiles/lexer_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/llvm-project/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o -MF CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o.d -o CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o -c /home/ace/llvm-project/project/diag_engine.cpp

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.i"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/llvm-project/project/diag_engine.cpp > CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.i

unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.s"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/llvm-project/project/diag_engine.cpp -o CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.s

# Object files for target lexer_test
lexer_test_OBJECTS = \
"CMakeFiles/lexer_test.dir/lexer_test.cpp.o" \
"CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o" \
"CMakeFiles/lexer_test.dir/__/__/type.cpp.o" \
"CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o"

# External object files for target lexer_test
lexer_test_EXTERNAL_OBJECTS =

unit_test/lexer/bin/lexer_test: unit_test/lexer/CMakeFiles/lexer_test.dir/lexer_test.cpp.o
unit_test/lexer/bin/lexer_test: unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/lexer.cpp.o
unit_test/lexer/bin/lexer_test: unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/type.cpp.o
unit_test/lexer/bin/lexer_test: unit_test/lexer/CMakeFiles/lexer_test.dir/__/__/diag_engine.cpp.o
unit_test/lexer/bin/lexer_test: unit_test/lexer/CMakeFiles/lexer_test.dir/build.make
unit_test/lexer/bin/lexer_test: lib/libgtest_main.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64CodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64AsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64Desc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64Disassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64Info.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64Utils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUUtils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMUtils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAVRCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAVRAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAVRDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAVRDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAVRInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBPFCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBPFAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBPFDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBPFDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBPFInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMHexagonCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMHexagonAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMHexagonDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMHexagonDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMHexagonInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLanaiCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLanaiAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLanaiDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLanaiDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLanaiInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMipsCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMipsAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMipsDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMipsDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMipsInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMSP430CodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMSP430AsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMSP430Desc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMSP430Disassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMSP430Info.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMNVPTXCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMNVPTXDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMNVPTXInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMPowerPCCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMPowerPCAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMPowerPCDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMPowerPCDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMPowerPCInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRISCVCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRISCVAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRISCVDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRISCVDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRISCVInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSparcCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSparcAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSparcDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSparcDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSparcInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSystemZCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSystemZAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSystemZDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSystemZDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSystemZInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMVECodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMVEAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMVEDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMVEDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMVEInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyUtils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMX86CodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMX86AsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMX86Desc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMX86Disassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMX86Info.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMXCoreCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMXCoreDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMXCoreDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMXCoreInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSupport.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMCore.a
unit_test/lexer/bin/lexer_test: lib/libgtest.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64Desc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64Info.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAArch64Utils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMPasses.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMCoroutines.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMObjCARCOpts.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMIRParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAMDGPUUtils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMARMUtils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMHexagonDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMHexagonInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLanaiDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLanaiInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMipo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMFrontendOpenMP.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMIRReader.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAsmParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMLinker.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMVectorize.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRISCVDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRISCVInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSystemZDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSystemZInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMWebAssemblyUtils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMCFGuard.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMInstrumentation.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAsmPrinter.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMDebugInfoMSF.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMGlobalISel.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSelectionDAG.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMCodeGen.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMScalarOpts.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAggressiveInstCombine.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMInstCombine.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBitWriter.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMTarget.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMTransformUtils.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMAnalysis.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMProfileData.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMDebugInfoDWARF.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMObject.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBitReader.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMCore.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMRemarks.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBitstreamReader.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMTextAPI.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMCParser.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kDesc.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMM68kInfo.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMCDisassembler.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMMC.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMBinaryFormat.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMDebugInfoCodeView.a
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMSupport.a
unit_test/lexer/bin/lexer_test: /usr/lib/x86_64-linux-gnu/libz.so
unit_test/lexer/bin/lexer_test: /usr/lib/x86_64-linux-gnu/libtinfo.so
unit_test/lexer/bin/lexer_test: /usr/lib/llvm-14/lib/libLLVMDemangle.a
unit_test/lexer/bin/lexer_test: unit_test/lexer/CMakeFiles/lexer_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/llvm-project/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin/lexer_test"
	cd /home/ace/llvm-project/project/build/unit_test/lexer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lexer_test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/ace/llvm-project/project/build/unit_test/lexer && /usr/bin/cmake -D TEST_TARGET=lexer_test -D TEST_EXECUTABLE=/home/ace/llvm-project/project/build/unit_test/lexer/bin/lexer_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/ace/llvm-project/project/build/unit_test/lexer -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=lexer_test_TESTS -D CTEST_FILE=/home/ace/llvm-project/project/build/unit_test/lexer/lexer_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
unit_test/lexer/CMakeFiles/lexer_test.dir/build: unit_test/lexer/bin/lexer_test
.PHONY : unit_test/lexer/CMakeFiles/lexer_test.dir/build

unit_test/lexer/CMakeFiles/lexer_test.dir/clean:
	cd /home/ace/llvm-project/project/build/unit_test/lexer && $(CMAKE_COMMAND) -P CMakeFiles/lexer_test.dir/cmake_clean.cmake
.PHONY : unit_test/lexer/CMakeFiles/lexer_test.dir/clean

unit_test/lexer/CMakeFiles/lexer_test.dir/depend:
	cd /home/ace/llvm-project/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/llvm-project/project /home/ace/llvm-project/project/unit_test/lexer /home/ace/llvm-project/project/build /home/ace/llvm-project/project/build/unit_test/lexer /home/ace/llvm-project/project/build/unit_test/lexer/CMakeFiles/lexer_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unit_test/lexer/CMakeFiles/lexer_test.dir/depend
