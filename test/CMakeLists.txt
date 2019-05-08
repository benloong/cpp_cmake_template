if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/utest.h)
    message("downloading utest.h")
    file(DOWNLOAD https://raw.githubusercontent.com/sheredom/utest.h/master/utest.h ${CMAKE_CURRENT_SOURCE_DIR}/utest.h SHOW_PROGRESS)
endif()
file(GLOB FilesTestSource ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(Test ${FilesTestSource} )
target_link_libraries(Test Core)
ENABLE_CXX17(Test)

set_target_properties(Test PROPERTIES LINKER_LANGUAGE CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/render)
 