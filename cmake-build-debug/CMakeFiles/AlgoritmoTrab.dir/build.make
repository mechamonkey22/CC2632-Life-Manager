# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AlgoritmoTrab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgoritmoTrab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgoritmoTrab.dir/flags.make

CMakeFiles/AlgoritmoTrab.dir/main.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/main.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AlgoritmoTrab.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\main.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\main.c

CMakeFiles/AlgoritmoTrab.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\main.c > CMakeFiles\AlgoritmoTrab.dir\main.c.i

CMakeFiles/AlgoritmoTrab.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\main.c -o CMakeFiles\AlgoritmoTrab.dir\main.c.s

CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.obj: ../MenuScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\MenuScreen.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MenuScreen.c

CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MenuScreen.c > CMakeFiles\AlgoritmoTrab.dir\MenuScreen.c.i

CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MenuScreen.c -o CMakeFiles\AlgoritmoTrab.dir\MenuScreen.c.s

CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.obj: ../MainScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\MainScreen.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MainScreen.c

CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MainScreen.c > CMakeFiles\AlgoritmoTrab.dir\MainScreen.c.i

CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MainScreen.c -o CMakeFiles\AlgoritmoTrab.dir\MainScreen.c.s

CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.obj: ../UserRegister.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\UserRegister.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserRegister.c

CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserRegister.c > CMakeFiles\AlgoritmoTrab.dir\UserRegister.c.i

CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserRegister.c -o CMakeFiles\AlgoritmoTrab.dir\UserRegister.c.s

CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.obj: ../MonitorSize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\MonitorSize.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MonitorSize.c

CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MonitorSize.c > CMakeFiles\AlgoritmoTrab.dir\MonitorSize.c.i

CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\MonitorSize.c -o CMakeFiles\AlgoritmoTrab.dir\MonitorSize.c.s

CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.obj: ../UserLogin.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\UserLogin.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserLogin.c

CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserLogin.c > CMakeFiles\AlgoritmoTrab.dir\UserLogin.c.i

CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserLogin.c -o CMakeFiles\AlgoritmoTrab.dir\UserLogin.c.s

CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.obj: ../ViewRegistry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\ViewRegistry.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\ViewRegistry.c

CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\ViewRegistry.c > CMakeFiles\AlgoritmoTrab.dir\ViewRegistry.c.i

CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\ViewRegistry.c -o CMakeFiles\AlgoritmoTrab.dir\ViewRegistry.c.s

CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.obj: ../UserRecipeScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\UserRecipeScreen.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserRecipeScreen.c

CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserRecipeScreen.c > CMakeFiles\AlgoritmoTrab.dir\UserRecipeScreen.c.i

CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\UserRecipeScreen.c -o CMakeFiles\AlgoritmoTrab.dir\UserRecipeScreen.c.s

CMakeFiles/AlgoritmoTrab.dir/Functions.c.obj: CMakeFiles/AlgoritmoTrab.dir/flags.make
CMakeFiles/AlgoritmoTrab.dir/Functions.c.obj: CMakeFiles/AlgoritmoTrab.dir/includes_C.rsp
CMakeFiles/AlgoritmoTrab.dir/Functions.c.obj: ../Functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/AlgoritmoTrab.dir/Functions.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AlgoritmoTrab.dir\Functions.c.obj   -c C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\Functions.c

CMakeFiles/AlgoritmoTrab.dir/Functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AlgoritmoTrab.dir/Functions.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\Functions.c > CMakeFiles\AlgoritmoTrab.dir\Functions.c.i

CMakeFiles/AlgoritmoTrab.dir/Functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AlgoritmoTrab.dir/Functions.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\Functions.c -o CMakeFiles\AlgoritmoTrab.dir\Functions.c.s

# Object files for target AlgoritmoTrab
AlgoritmoTrab_OBJECTS = \
"CMakeFiles/AlgoritmoTrab.dir/main.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.obj" \
"CMakeFiles/AlgoritmoTrab.dir/Functions.c.obj"

# External object files for target AlgoritmoTrab
AlgoritmoTrab_EXTERNAL_OBJECTS =

AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/main.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/MenuScreen.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/MainScreen.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/UserRegister.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/MonitorSize.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/UserLogin.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/ViewRegistry.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/UserRecipeScreen.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/Functions.c.obj
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/build.make
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/linklibs.rsp
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/objects1.rsp
AlgoritmoTrab.exe: CMakeFiles/AlgoritmoTrab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable AlgoritmoTrab.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AlgoritmoTrab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlgoritmoTrab.dir/build: AlgoritmoTrab.exe

.PHONY : CMakeFiles/AlgoritmoTrab.dir/build

CMakeFiles/AlgoritmoTrab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AlgoritmoTrab.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AlgoritmoTrab.dir/clean

CMakeFiles/AlgoritmoTrab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug C:\Users\joao_vitor\CLionProjects\AlgoritmoTrab\cmake-build-debug\CMakeFiles\AlgoritmoTrab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AlgoritmoTrab.dir/depend

