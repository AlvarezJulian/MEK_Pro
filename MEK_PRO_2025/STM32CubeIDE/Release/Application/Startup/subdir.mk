################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Application/Startup/startup_stm32f750n8hx.s 

C_SRCS += \
../Application/Startup/syscalls.c \
../Application/Startup/sysmem.c 

S_DEPS += \
./Application/Startup/startup_stm32f750n8hx.d 

C_DEPS += \
./Application/Startup/syscalls.d \
./Application/Startup/sysmem.d 

OBJS += \
./Application/Startup/startup_stm32f750n8hx.o \
./Application/Startup/syscalls.o \
./Application/Startup/sysmem.o 


# Each subdirectory must supply rules for building sources it contributes
Application/Startup/%.o: ../Application/Startup/%.s Application/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Application/Startup/%.o Application/Startup/%.su Application/Startup/%.cyclo: ../Application/Startup/%.c Application/Startup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../../Core/Inc -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../TouchGFX/target -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/Vendor/Driver -I../../Drivers/Vendor/DEVICE -I../../Drivers/Vendor/Board/SE21070/Config -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Drivers/Vendor/Device -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Startup

clean-Application-2f-Startup:
	-$(RM) ./Application/Startup/startup_stm32f750n8hx.d ./Application/Startup/startup_stm32f750n8hx.o ./Application/Startup/syscalls.cyclo ./Application/Startup/syscalls.d ./Application/Startup/syscalls.o ./Application/Startup/syscalls.su ./Application/Startup/sysmem.cyclo ./Application/Startup/sysmem.d ./Application/Startup/sysmem.o ./Application/Startup/sysmem.su

.PHONY: clean-Application-2f-Startup

