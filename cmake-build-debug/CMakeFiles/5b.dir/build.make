# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Programm\5b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Programm\5b\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/5b.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/5b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5b.dir/flags.make

CMakeFiles/5b.dir/main.c.obj: CMakeFiles/5b.dir/flags.make
CMakeFiles/5b.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programm\5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/5b.dir/main.c.obj"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5b.dir\main.c.obj -c F:\Programm\5b\main.c

CMakeFiles/5b.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5b.dir/main.c.i"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Programm\5b\main.c > CMakeFiles\5b.dir\main.c.i

CMakeFiles/5b.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5b.dir/main.c.s"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Programm\5b\main.c -o CMakeFiles\5b.dir\main.c.s

CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.obj: CMakeFiles/5b.dir/flags.make
CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.obj: ../libs/data_structures/vector/vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programm\5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.obj"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5b.dir\libs\data_structures\vector\vector.c.obj -c F:\Programm\5b\libs\data_structures\vector\vector.c

CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.i"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Programm\5b\libs\data_structures\vector\vector.c > CMakeFiles\5b.dir\libs\data_structures\vector\vector.c.i

CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.s"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Programm\5b\libs\data_structures\vector\vector.c -o CMakeFiles\5b.dir\libs\data_structures\vector\vector.c.s

CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.obj: CMakeFiles/5b.dir/flags.make
CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.obj: ../libs/data_structures/matrix/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programm\5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.obj"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5b.dir\libs\data_structures\matrix\matrix.c.obj -c F:\Programm\5b\libs\data_structures\matrix\matrix.c

CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.i"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Programm\5b\libs\data_structures\matrix\matrix.c > CMakeFiles\5b.dir\libs\data_structures\matrix\matrix.c.i

CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.s"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Programm\5b\libs\data_structures\matrix\matrix.c -o CMakeFiles\5b.dir\libs\data_structures\matrix\matrix.c.s

CMakeFiles/5b.dir/string/string_.c.obj: CMakeFiles/5b.dir/flags.make
CMakeFiles/5b.dir/string/string_.c.obj: ../string/string_.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programm\5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/5b.dir/string/string_.c.obj"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5b.dir\string\string_.c.obj -c F:\Programm\5b\string\string_.c

CMakeFiles/5b.dir/string/string_.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5b.dir/string/string_.c.i"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Programm\5b\string\string_.c > CMakeFiles\5b.dir\string\string_.c.i

CMakeFiles/5b.dir/string/string_.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5b.dir/string/string_.c.s"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Programm\5b\string\string_.c -o CMakeFiles\5b.dir\string\string_.c.s

CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.obj: CMakeFiles/5b.dir/flags.make
CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.obj: ../string/tasks/removeNonLetters.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programm\5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.obj"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5b.dir\string\tasks\removeNonLetters.c.obj -c F:\Programm\5b\string\tasks\removeNonLetters.c

CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.i"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Programm\5b\string\tasks\removeNonLetters.c > CMakeFiles\5b.dir\string\tasks\removeNonLetters.c.i

CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.s"
	F:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Programm\5b\string\tasks\removeNonLetters.c -o CMakeFiles\5b.dir\string\tasks\removeNonLetters.c.s

# Object files for target 5b
5b_OBJECTS = \
"CMakeFiles/5b.dir/main.c.obj" \
"CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.obj" \
"CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.obj" \
"CMakeFiles/5b.dir/string/string_.c.obj" \
"CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.obj"

# External object files for target 5b
5b_EXTERNAL_OBJECTS =

5b.exe: CMakeFiles/5b.dir/main.c.obj
5b.exe: CMakeFiles/5b.dir/libs/data_structures/vector/vector.c.obj
5b.exe: CMakeFiles/5b.dir/libs/data_structures/matrix/matrix.c.obj
5b.exe: CMakeFiles/5b.dir/string/string_.c.obj
5b.exe: CMakeFiles/5b.dir/string/tasks/removeNonLetters.c.obj
5b.exe: CMakeFiles/5b.dir/build.make
5b.exe: libstr.a
5b.exe: CMakeFiles/5b.dir/linklibs.rsp
5b.exe: CMakeFiles/5b.dir/objects1.rsp
5b.exe: CMakeFiles/5b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Programm\5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable 5b.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\5b.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5b.dir/build: 5b.exe
.PHONY : CMakeFiles/5b.dir/build

CMakeFiles/5b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\5b.dir\cmake_clean.cmake
.PHONY : CMakeFiles/5b.dir/clean

CMakeFiles/5b.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Programm\5b F:\Programm\5b F:\Programm\5b\cmake-build-debug F:\Programm\5b\cmake-build-debug F:\Programm\5b\cmake-build-debug\CMakeFiles\5b.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5b.dir/depend

