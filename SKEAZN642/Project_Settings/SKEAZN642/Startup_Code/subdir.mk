################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Settings/SKEAZN642/Startup_Code/system_SKEAZN642.c 

S_UPPER_SRCS += \
../Project_Settings/SKEAZN642/Startup_Code/startup_SKEAZN642.S 

OBJS += \
./Project_Settings/SKEAZN642/Startup_Code/startup_SKEAZN642.o \
./Project_Settings/SKEAZN642/Startup_Code/system_SKEAZN642.o 

C_DEPS += \
./Project_Settings/SKEAZN642/Startup_Code/system_SKEAZN642.d 

S_UPPER_DEPS += \
./Project_Settings/SKEAZN642/Startup_Code/startup_SKEAZN642.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/SKEAZN642/Startup_Code/%.o: ../Project_Settings/SKEAZN642/Startup_Code/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/SKEAZN642/Startup_Code/%.o: ../Project_Settings/SKEAZN642/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -D"SKEAZN642" -I"../Sources" -I"../Sources/inc" -I"../Sources/drivers" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


