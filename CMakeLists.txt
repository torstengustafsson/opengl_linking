cmake_minimum_required(VERSION 3.0)

project(ALinkToTheOpenGLStuff)

# Require the use of a "build" directory or similar for builds to avoid newbies cluttering up their source tree
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

add_executable (MyLinkedProgram "main.cpp")

# make sure the gl context is linked together at compile time
# target_compile_definitions(MyLinkedProgram PRIVATE GLEW_STATIC=1)

# add OpenGL
find_package(OpenGL REQUIRED)

# include headers
target_include_directories (MyLinkedProgram
  PRIVATE ${PROJECT_SOURCE_DIR}/ext/glew/include
  PRIVATE ${PROJECT_SOURCE_DIR}/ext/glfw/include
  PRIVATE ${PROJECT_SOURCE_DIR}/ext/glm
)

# Set up paths so lib files and program is put together. (in this case only bin dir
# is used, add archive and library output dirs for completeness)
set_target_properties (MyLinkedProgram
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

## add glew
# Note: Builds both shared and static libraries. There is sadly no option to only build one or the other
add_subdirectory(ext/glew/build/cmake)

## add glfw
add_subdirectory(ext/glfw)

target_link_libraries(MyLinkedProgram
  PRIVATE glew
  PRIVATE glfw
)
