cmake_minimum_required(VERSION 3.10)
project(LiveDoodleOnCamera 
        VERSION 1.0.0
        DESCRIPTION "Real-Time Computer Vision Drawing Application"
        LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build options
option(BUILD_ADVANCED "Build advanced version" ON)
option(BUILD_BASIC "Build basic version" OFF)
option(ENABLE_TESTING "Enable testing" OFF)
option(BUILD_DOCS "Build documentation" OFF)
option(ENABLE_WARNINGS "Enable compiler warnings" ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Compiler warnings
if(ENABLE_WARNINGS)
    if(MSVC)
        add_compile_options(/W4 /WX)
    else()
        add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    endif()
endif()

# Find required packages
find_package(OpenCV 4 REQUIRED)

if(OpenCV_FOUND)
    message(STATUS "OpenCV ${OpenCV_VERSION} found")
    message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
    message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "OpenCV not found. Please install OpenCV 4.x")
endif()

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Source files
set(BASIC_SOURCES main.cpp)
set(ADVANCED_SOURCES main_advanced.cpp)

# Build advanced version (default)
if(BUILD_ADVANCED)
    add_executable(live_doodle_advanced ${ADVANCED_SOURCES})
    target_link_libraries(live_doodle_advanced ${OpenCV_LIBS})
    
    # Set output name
    set_target_properties(live_doodle_advanced PROPERTIES
        OUTPUT_NAME "live_doodle"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
    
    # Platform-specific settings
    if(WIN32)
        # Windows-specific settings
        set_target_properties(live_doodle_advanced PROPERTIES
            WIN32_EXECUTABLE TRUE
        )
    elseif(APPLE)
        # macOS-specific settings
        set_target_properties(live_doodle_advanced PROPERTIES
            MACOSX_BUNDLE TRUE
        )
    endif()
    
    message(STATUS "Building advanced version: live_doodle_advanced")
endif()

# Build basic version (optional)
if(BUILD_BASIC)
    add_executable(live_doodle_basic ${BASIC_SOURCES})
    target_link_libraries(live_doodle_basic ${OpenCV_LIBS})
    
    set_target_properties(live_doodle_basic PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
    
    message(STATUS "Building basic version: live_doodle_basic")
endif()

# Installation
if(BUILD_ADVANCED)
    install(TARGETS live_doodle_advanced
            RUNTIME DESTINATION bin
            COMPONENT runtime)
endif()

if(BUILD_BASIC)
    install(TARGETS live_doodle_basic
            RUNTIME DESTINATION bin
            COMPONENT runtime)
endif()

# Install configuration file
install(FILES config.json
        DESTINATION etc/live-doodle
        COMPONENT config)

# Install documentation
install(FILES README.md LICENSE
        DESTINATION share/doc/live-doodle
        COMPONENT documentation)

# Testing (optional)
if(ENABLE_TESTING)
    enable_testing()
    # Add tests here
    message(STATUS "Testing enabled")
endif()

# Documentation (optional)
if(BUILD_DOCS)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
        set(DOXYGEN_GENERATE_HTML YES)
        set(DOXYGEN_GENERATE_MAN NO)
        
        doxygen_add_docs(docs
            ${CMAKE_SOURCE_DIR}
            COMMENT "Generating API documentation"
        )
        
        message(STATUS "Documentation build enabled")
    else()
        message(WARNING "Doxygen not found. Documentation will not be built.")
    endif()
endif()

# CPack configuration for packaging
set(CPACK_PACKAGE_NAME "LiveDoodleOnCamera")
set(CPACK_PACKAGE_VENDOR "Chethana G")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Real-Time Drawing Application")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")

if(WIN32)
    set(CPACK_GENERATOR "ZIP;NSIS")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop")
else()
    set(CPACK_GENERATOR "TGZ;DEB")
endif()

include(CPack)

# Display build information
message(STATUS "")
message(STATUS "========================================")
message(STATUS "  Live Doodle on Camera ${PROJECT_VERSION}")
message(STATUS "========================================")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "========================================")
message(STATUS "")
