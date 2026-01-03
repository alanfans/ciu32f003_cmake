cmake_minimum_required(VERSION 3.22)

project(ciu32cubemx)
add_library(ciu32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(ciu32cubemx INTERFACE 
#	USE_HAL_DRIVER 
#	STM32F103x6 
#	STM32_THREAD_SAFE_STRATEGY=2
    $<$<CONFIG:Debug>:DEBUG>
#    USE_STDPERIPH_DRIVER
)

target_include_directories(ciu32cubemx INTERFACE
    ../../Core/Inc
    ../../Drivers/CIU32F003_Lib/Include
    ../../Drivers/CMSIS/Core
    ../../Drivers/CMSIS/Device    
)

target_sources(ciu32cubemx INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/common.c
    
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_adc.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_crc.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_comp.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_exti.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_flash.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_gpio.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_i2c.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_lptim.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_pmu.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_rcc.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_spi.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_tim.c
    ../../Drivers/CIU32F003_Lib/Source/ciu32f003_std_uart.c
    
    ../../Drivers/CMSIS/Device/system_ciu32f003.c
    ../../Drivers/startup/startup_ciu32f003.S
)

target_link_directories(ciu32cubemx INTERFACE
)

target_link_libraries(ciu32cubemx INTERFACE
)

# Validate that ciu32cubemx code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


