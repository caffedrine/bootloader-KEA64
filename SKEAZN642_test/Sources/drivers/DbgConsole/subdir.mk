################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/drivers/DbgConsole/DbgConsole.c 

OBJS += \
./Sources/drivers/DbgConsole/DbgConsole.o 

C_DEPS += \
./Sources/drivers/DbgConsole/DbgConsole.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/drivers/DbgConsole/%.o: ../Sources/drivers/DbgConsole/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -D"SKEAZN642" -I"../Sources" -I"../test" -I"../Sources/inc" -I"../Sources/drivers" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


