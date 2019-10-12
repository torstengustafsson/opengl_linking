# Opengl Linking
Since linking is usually a pain in the ass, especially if you want to work cross-platform,
an example project has been added here, showing how it is supposed to be done (according to
me at least, open to convincing alternatives).

This repo demonstrates linking of mainly GLFW, GLEW and GLM with a CMake project.
It takes the official github repos of these projects as submodules, to allow simple version updating.
It is intended to work out of the box on linux, windows mac, etc. with whatever compiler you fancy
(as long as it is supported by CMAKE).

Requirements: A CMake-supported compiler, any GPU with OpenGL support, and CMake 3.?? installed.
