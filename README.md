# CIU32F003 Firmware Project

This project contains firmware for the CIU32F003 microcontroller (STM32-based) using CMake build system and STM32CubeMX configuration.

## Project Structure

- [`CMakeLists.txt`](CMakeLists.txt:1)
  Main build configuration file using CMake
- [`Core/`](Core/)
  Application code and hardware abstraction layer
  - `Inc/` - Header files ([`main.h`](Core/Inc/main.h:1), [`common.h`](Core/Inc/common.h:1))
  - `Src/` - Source files ([`main.c`](Core/Src/main.c:1), [`common.c`](Core/Src/common.c:1), [`syscalls.c`](Core/Src/syscalls.c:1))
- [`Drivers/`](Drivers/)
  Hardware-specific drivers
  - `CIU32F003_Lib/` - Custom peripheral drivers ([ADC](Drivers/CIU32F003_Lib/Include/ciu32f003_std_adc.h:1), [UART](Drivers/CIU32F003_Lib/Include/ciu32f003_std_uart.h:1), [GPIO](Drivers/CIU32F003_Lib/Include/ciu32f003_std_gpio.h:1), etc.)
  - `CMSIS/` - ARM Cortex-M core support
  - `startup/` - Startup files and linker scripts ([`ciu32f003x5.ld`](Drivers/startup/ciu32f003x5.ld:1))
- [`cmake/`](cmake/)
  Build system configuration
  - `gcc-arm-none-eabi.cmake` - Toolchain configuration
  - `ciu32cubemx/` - CubeMX-generated code integration

## Build Requirements

- ARM GCC toolchain (`arm-none-eabi-gcc`)
- CMake (3.22+)
- Make or Ninja build system
- PyOCD (for debugging, see [`pyocd.yaml`](pyocd.yaml:1))

## Building the Project

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

This will generate:
- ELF executable
- [`ciu32f003_cmake.hex`](ciu32f003_cmake.hex:71)
- [`ciu32f003_cmake.bin`](ciu32f003_cmake.bin:72)

## Flashing

Using PyOCD:
```bash
pyocd flash -t ciu32f003 build/ciu32f003_cmake.hex
```

## Configuration

- Build type can be set via `-DCMAKE_BUILD_TYPE` (Debug/Release)
- CubeMX configuration is integrated through [`cmake/ciu32cubemx/CMakeLists.txt`](cmake/ciu32cubemx/CMakeLists.txt:1)
- Device support pack: [`HED.CIU32F003_DFP.1.0.0.pack`](HED.CIU32F003_DFP.1.0.0.pack:1)

## Notes

- The project uses C11 standard with compiler extensions enabled
- Compile commands are exported for IDE indexing (`compile_commands.json`)
- Startup files are provided for multiple toolchains (ARMCC, GCC, IAR)