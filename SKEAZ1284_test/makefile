################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include test/subdir.mk
-include Sources/drivers/UART/subdir.mk
-include Sources/drivers/DbgConsole/subdir.mk
-include Sources/subdir.mk
-include Project_Settings/SKEAZ1284/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
KEA64_UART_Bootloader.bin \


# All Target
all: KEA64_UART_Bootloader.elf secondary-outputs

# Tool invocations
KEA64_UART_Bootloader.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM GNU C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T "SKEAZ64xxx4_flash.ld" -Xlinker --gc-sections -L"C:/Workspaces/KDS/BL_Alpha/Project_Settings/SKEAZ1284/Linker_Files" -Wl,-Map,"KEA64_UART_Bootloader.map" -specs=nano.specs -specs=nosys.specs -o "KEA64_UART_Bootloader.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KEA64_UART_Bootloader.bin: KEA64_UART_Bootloader.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary "KEA64_UART_Bootloader.elf"  "KEA64_UART_Bootloader.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(CC_DEPS)$(SECONDARY_FLASH)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS)$(S_UPPER_DEPS) KEA64_UART_Bootloader.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
