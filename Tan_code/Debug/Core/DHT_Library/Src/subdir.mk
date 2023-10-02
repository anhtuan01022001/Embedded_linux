################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DHT_Library/Src/DHT11.c 

OBJS += \
./Core/DHT_Library/Src/DHT11.o 

C_DEPS += \
./Core/DHT_Library/Src/DHT11.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DHT_Library/Src/%.o Core/DHT_Library/Src/%.su: ../Core/DHT_Library/Src/%.c Core/DHT_Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/lib/Inc -I../Core/DHT_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-DHT_Library-2f-Src

clean-Core-2f-DHT_Library-2f-Src:
	-$(RM) ./Core/DHT_Library/Src/DHT11.d ./Core/DHT_Library/Src/DHT11.o ./Core/DHT_Library/Src/DHT11.su

.PHONY: clean-Core-2f-DHT_Library-2f-Src

