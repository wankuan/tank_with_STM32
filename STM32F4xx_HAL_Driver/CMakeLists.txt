file(GLOB sources Src/*.c)
add_library(STM32F4_HAL ${sources})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/target/lib)           #设置库文件的输出目录
target_include_directories(STM32F4_HAL PUBLIC Inc)
target_include_directories(STM32F4_HAL PUBLIC Inc/Legacy)

set(HSE_VALUE 25000000)

# set up some defines for the StdPeriph library

target_compile_definitions(STM32F4_HAL PUBLIC STM32F429xx)
target_compile_definitions(STM32F4_HAL PUBLIC USE_HAL_DRIVER)
target_compile_definitions(STM32F4_HAL PUBLIC HSE_VALUE=${HSE_VALUE})

# # additional compiler options: use size-optimized version of library in release build, use -O0 in debug build
if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(additional_flags -O0)
else()
  set(additional_flags -Os)
endif()

target_compile_options(STM32F4_HAL PRIVATE ${additional_flags})
