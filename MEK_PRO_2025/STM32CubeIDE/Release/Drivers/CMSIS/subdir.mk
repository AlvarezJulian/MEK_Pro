################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Julian/git/MEK_Pro/MEK_PRO_2025/Core/Src/system_stm32f7xx.c 

C_DEPS += \
./Drivers/CMSIS/system_stm32f7xx.d 

OBJS += \
./Drivers/CMSIS/system_stm32f7xx.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f7xx.o: C:/Users/Julian/git/MEK_Pro/MEK_PRO_2025/Core/Src/system_stm32f7xx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../../Core/Inc -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../TouchGFX/target -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/Vendor/Driver -I../../Drivers/Vendor/DEVICE -I../../Drivers/Vendor/Board/SE21070/Config -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Drivers/Vendor/Device -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32f7xx.cyclo ./Drivers/CMSIS/system_stm32f7xx.d ./Drivers/CMSIS/system_stm32f7xx.o ./Drivers/CMSIS/system_stm32f7xx.su

.PHONY: clean-Drivers-2f-CMSIS

