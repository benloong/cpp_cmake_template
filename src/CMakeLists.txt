
# Common files
file(GLOB FilesCoreHeader ${CMAKE_CURRENT_SOURCE_DIR}/core/*.h)
file(GLOB FilesCoreSource ${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp)
file(GLOB FilesRenderHeader ${CMAKE_CURRENT_SOURCE_DIR}/render/*.h)
file(GLOB FilesRenderSource ${CMAKE_CURRENT_SOURCE_DIR}/render/*.cpp)
 
if(WIN32)
    file(GLOB FilesPlatform                 ${CMAKE_CURRENT_SOURCE_DIR}/core/Windows/*.cpp)
elseif(APPLE)
    if(MOBILE_PLATFORM)
        file(GLOB FilesPlatform            ${CMAKE_CURRENT_SOURCE_DIR}/core/iOS/*.cpp)
    else()
        file(GLOB FilesPlatform             ${CMAKE_CURRENT_SOURCE_DIR}/core/macOS/*.cpp)
    endif()
elseif(UNIX)
    file(GLOB FilesPlatform                 ${CMAKE_CURRENT_SOURCE_DIR}/core/Linux/*.cpp)
endif()

add_library(Core STATIC ${FilesCoreHeader} ${FilesCoreSource} ${FilesPlatform})
ENABLE_CXX17(Core)
set_target_properties(Core PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX "_Debug")
 
if(BUILD_STATIC_LIB)
    add_library(Render STATIC ${FilesRenderHeader} ${FilesRenderSource})
else()
    add_library(Render SHARED ${FilesRenderHeader} ${FilesRenderSource})
endif()
ENABLE_CXX17(Render)
set_target_properties(Render PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX "_Debug")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core)