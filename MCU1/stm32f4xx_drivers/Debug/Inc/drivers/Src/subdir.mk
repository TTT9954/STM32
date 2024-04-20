################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/drivers/Src/stm32f407xx_gpio_driver.c 

OBJS += \
./Inc/drivers/Src/stm32f407xx_gpio_driver.o 

C_DEPS += \
./Inc/drivers/Src/stm32f407xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/drivers/Src/%.o Inc/drivers/Src/%.su Inc/drivers/Src/%.cyclo: ../Inc/drivers/Src/%.c Inc/drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-drivers-2f-Src

clean-Inc-2f-drivers-2f-Src:
	-$(RM) ./Inc/drivers/Src/stm32f407xx_gpio_driver.cyclo ./Inc/drivers/Src/stm32f407xx_gpio_driver.d ./Inc/drivers/Src/stm32f407xx_gpio_driver.o ./Inc/drivers/Src/stm32f407xx_gpio_driver.su

.PHONY: clean-Inc-2f-drivers-2f-Src

