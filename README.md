# Opengl Linking
Since linking is usually a pain in the ass, especially if you want to work cross-platform,
an example project has been added here, showing how it is supposed to be done (according to
me at least, open to convincing alternatives).

This repo demonstrates linking of mainly GLFW, GLEW and GLM with a CMake project.
It takes the official github repos of these projects as submodules, to allow simple version updating.
It is intended to work out of the box on linux, windows mac, etc. with whatever compiler you fancy
(as long as it is supported by CMAKE).

Requirements:
* A CMake-supported compiler
* GPU with OpenGL support
* CMake >=3.0
* make tool for GLEW source code generation. When running Windows Cygwin (https://www.cygwin.com/setup-x86_64.exe) can
  be installed to make them. Just remember to select "make" and "perl" as packages to install at installation window.
  (why is this necessary? I have not found any good sources answering that question. I guess it's because of GLEW:s
  nature of being a wrapper to low level functions on the OS level.)

Instuctions:
1. Navigate to ext/glew/auto directory and run make. (for Windows, use Cygwin. Windows filesystem can be accessed from
   "/cygdrive")
2. Generate the code with CMake in a good place, for example "build/".
