cmake_minimum_required(VERSION 3.15)
project(AlgoritmoTrab C)

set(CMAKE_C_STANDARD 99)
include_directories(iup/include)
link_directories(iup)

add_executable(AlgoritmoTrab main.c MenuScreen.h MenuScreen.c MainScreen.c MainScreen.h Structs.h MonitorSize.h NewFile.c NewFile.h UserRegister.c UserRegister.h MonitorSize.c UserLogin.c UserLogin.h)
target_link_libraries(AlgoritmoTrab iup gdi32 comdlg32 comctl32 uuid oleaut32 ole32)