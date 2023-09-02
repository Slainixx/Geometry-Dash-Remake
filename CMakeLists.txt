cmake_minimum_required(VERSION 3.6)

project(GeometryDash)

# Set the CMake build type to Release (or Debug if needed)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set the Cocos2d-x root directory (change this to your Cocos2d-x installation path)
set(COCOS2DX_ROOT_PATH "cocos2d/cocos-headers/cocos2dx")

# Set the source files and headers for your project
set(SOURCES
    main.cpp
    ButtonSprite.cpp
    DialogObject.cpp
    EffectGameObject.cpp
    GJAccountManager.cpp
    GJBaseGameLayer.cpp
    GJChallengeItem.cpp
    GJComment.cpp
    GJDropDownLayer.cpp
    GJGameLevel.cpp
    GJRewardObject.cpp
    GJRewardsItem.cpp
    LevelPage.cpp
    LevelSelectLayer.cpp
    MultilineBitmapFont.cpp
    OBB2D.cpp
    ObjectToolbox.cpp
    SetIDLayer.cpp
)

set(HEADERS
    # Add header files here
)

# Include Cocos2d-x CMake scripts
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules)
include(CocosBuildSet)

# Add Cocos2d-x libraries
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos)

# Set include directories
include_directories(
    ${COCOS2DX_ROOT_PATH}/cocos
    ${COCOS2DX_ROOT_PATH}/external
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    cocos2d
    cocos2d/cocos-headers/cocos2dx
    headers
    submodules
)

# Set the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
