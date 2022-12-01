# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

include(FetchContent)

FetchContent_Declare(
    mcux_sdk
    GIT_REPOSITORY https://github.com/NXPmicro/mcux-sdk
    GIT_TAG MCUX_2.12.0_UPDATE
    GIT_SHALLOW TRUE
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

FetchContent_Declare(
    usb_middleware
    GIT_REPOSITORY https://github.com/NXPmicro/mcux-sdk-middleware-usb
    GIT_TAG MCUX_2.12.0
    GIT_SHALLOW TRUE
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

FetchContent_MakeAvailable(mcux_sdk usb_middleware)
FetchContent_GetProperties(mcux_sdk SOURCE_DIR SDK_SOURCE_DIR)
FetchContent_GetProperties(usb_middleware SOURCE_DIR MIDDLEWARE_SRC_DIR)
list(APPEND CMAKE_MODULE_PATH ${MIDDLEWARE_SRC_DIR}/)

set(MCUX_DEVICE MIMXRT1011)
include(${SDK_SOURCE_DIR}/all_devices.cmake)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

project(dev_hid_mouse_bm)

set(MCUX_SDK_PROJECT_NAME xinput_controller.elf)

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/src/xinput.c"
"${ProjDirPath}/src/usb_device_descriptor.c"
"${ProjDirPath}/src/board.c"
"${ProjDirPath}/src/clock_config.c"
"${ProjDirPath}/src/pin_mux.c"
"${ProjDirPath}/src/usb_device_ch9.c"
"${ProjDirPath}/src/usb_device_class.c"
"${ProjDirPath}/src/usb_device_xinput.c"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${ProjDirPath}/include
)


# include modules
include(middleware_usb_device_stack_external)

include(component_pit_adapter)

include(driver_cache_armv7_m7)

include(utility_debug_console_lite)

include(driver_clock)

include(device_CMSIS)

include(device_startup)

include(driver_igpio)

include(driver_xip_device)

include(device_system)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE m)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE c)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE gcc)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE nosys)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)
