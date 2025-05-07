################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lib/Src/LCD_4_Bits.c 

OBJS += \
./Core/lib/Src/LCD_4_Bits.o 

C_DEPS += \
./Core/lib/Src/LCD_4_Bits.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lib/Src/%.o Core/lib/Src/%.su: ../Core/lib/Src/%.c Core/lib/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/lib/Inc -I../Core/DHT_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-lib-2f-Src

clean-Core-2f-lib-2f-Src:
	-$(RM) ./Core/lib/Src/LCD_4_Bits.d ./Core/lib/Src/LCD_4_Bits.o ./Core/lib/Src/LCD_4_Bits.su

.PHONY: clean-Core-2f-lib-2f-Src

