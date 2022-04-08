1. Install following plugins in Visual Studio Code:
	- C/C++ IntelliSense, debugging, and code browsing: https://code.visualstudio.com/docs/languages/cpp
	- CMake langage support for Visual Studio Code: https://cmake.org/
	- CMake Tools: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
2. Download mingw, gcc, gdb:
	- https://www.msys2.org/
	- follow the instructions from the web-site to install the components
3. Download Ninja:
	- https://github.com/ninja-build/ninja/releases
	- put ninja.exe in path where gcc.exe is located
4. Setup Enviroment variable "Path->Edit->New"
	- put the path where ninja.exe and gcc.exe are located
5. Project in VS Code
	- make empty folder
!!! Node: It's important the Path to that folder to not include Bulgarian folder names.
	- create main.cpp file with content of "Hello World" program
	- Make CmakeList.txt file with the following basic content:
	```
		cmake_minimum_required(VERSION 3.0.0)
		#project(example VERSION 0.1.0)

		set(This Test)
		project(${This} C CXX)

		set(CMAKE_C_STANDARD 99)
		set(CMAKE_CXX_STANDARD 11)
		set(CMAKE_POSITION_INDEPENDENT_CODE ON)

		add_executable(mainTest helloWorld.cpp)
	```
	- Ctr+Shift+P -> Cmake:Config -> chose GCC (you must see it on the path where it already istalled)
	- CMake:Build -> must create build folder with the folowing content:
	```
		.cmake/      
		.ninja_log   
		cmake_install.cmake  
		CMakeFiles/            
		mainTest.exe*
        	.ninja_deps  
		build.ninja  
		CMakeCache.txt       
		compile_commands.json
	```
	- CMake:Debug -> to enable debugging of the project
