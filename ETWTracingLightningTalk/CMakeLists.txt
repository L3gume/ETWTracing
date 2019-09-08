# CMakeList.txt : CMake project for ETWTracingLightningTalk, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE FILES_DIR
	"*.h"
	"*.cpp"
)
# Add source to this project's executable.
add_executable (ETWTracingLightningTalk ${FILES_DIR})

# TODO: Add tests and install targets if needed.
