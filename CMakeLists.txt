project(Momoko)
cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(BUILD_SIMPLE_TEST OFF CACHE BOOL "Build 'Simple' test")


# if(WIN32)
# endif(WIN32)

# if (APPLE)
# endif(APPLE)

# if ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
# endif("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")

if ( CMAKE_COMPILER_IS_GNUCC )
	add_definitions(-W -Wall -g)
endif ( CMAKE_COMPILER_IS_GNUCC )


# SDL
find_package(SDL REQUIRED)

if ( NOT SDL_FOUND )
	message(FATAL_ERROR "SDL not found !")
endif ( NOT SDL_FOUND )


# DevIL
find_package(DevIL REQUIRED)

if ( NOT IL_FOUND )
	message(FATAL_ERROR "DevIL not found !")
endif ( NOT IL_FOUND )


# OpenGL
find_package(OpenGL REQUIRED)

if ( NOT OPENGL_FOUND )
	message(FATAL_ERROR "OpenGL not found !")
endif ( NOT OPENGL_FOUND )

if ( NOT OPENGL_GLU_FOUND )
	message(FATAL_ERROR "OpenGLu not found !")
endif ( NOT OPENGL_GLU_FOUND)

# Include dirs
include_directories(${SDL_INCLUDE_DIR})
include_directories(${IL_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})

set(DEVIL_LINK ${IL_LIBRARIES} ${ILU_LIBRARIES} ${ILUT_LIBRARIES})


add_subdirectory(MomokoMain)
add_subdirectory(tests)

