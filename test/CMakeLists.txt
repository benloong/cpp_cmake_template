if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/catch.h)
    message("downloading catch2")
    file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.8.0/catch.hpp ${CMAKE_CURRENT_SOURCE_DIR}/catch.h SHOW_PROGRESS)
endif()
file(GLOB FilesTestSource ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(Test ${FilesTestSource} )
target_link_libraries(Test Core)
ENABLE_CXX17(Test)

set_target_properties(Test PROPERTIES LINKER_LANGUAGE CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/render)
 