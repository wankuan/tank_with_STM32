set(LIB_NAME TencentOS)


file(GLOB sources_core kernel/core/*.c)
set_property(SOURCE arch/arm/arm-v7m/cortex-m4/gcc/port_s.S PROPERTY LANGUAGE C)
set(sources
    arch/arm/arm-v7m/cortex-m4/gcc/port_c.c
    arch/arm/arm-v7m/common/tos_cpu.c
    arch/arm/arm-v7m/common/tos_fault.c
    arch/arm/arm-v7m/cortex-m4/gcc/port_s.S
    osal/cmsis_os/cmsis_os.c
    ${sources_core}
)

add_library(${LIB_NAME} ${sources})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/target/lib)           #设置库文件的输出目录
target_include_directories(${LIB_NAME} PUBLIC arch/arm/arm-v7m/cortex-m4/gcc)
target_include_directories(${LIB_NAME} PUBLIC kernel/core/include)
target_include_directories(${LIB_NAME} PUBLIC osal/cmsis_os)
target_include_directories(${LIB_NAME} PUBLIC arch/arm/arm-v7m/common/include)
target_include_directories(${LIB_NAME} PUBLIC kernel/pm/include)

target_include_directories(${LIB_NAME} PUBLIC ./)
# target_compile_definitions(${LIB_NAME} PUBLIC STM32F429xx)
# target_compile_definitions(${LIB_NAME} PUBLIC USE_HAL_DRIVER)
# target_compile_definitions(${LIB_NAME} PUBLIC HSE_VALUE=${HSE_VALUE})

# # additional compiler options: use size-optimized version of library in release build, use -O0 in debug build
if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(additional_flags -O0)
else()
  set(additional_flags -Os)
endif()

target_compile_options(${LIB_NAME} PRIVATE ${additional_flags})
