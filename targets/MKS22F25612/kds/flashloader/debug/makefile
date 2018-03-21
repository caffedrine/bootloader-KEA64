################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/utilities/src/subdir.mk
-include src/usb_stack/usb_core/hal/subdir.mk
-include src/usb_stack/usb_core/device/sources/controller/khci/subdir.mk
-include src/usb_stack/usb_core/device/sources/controller/ehci/subdir.mk
-include src/usb_stack/usb_core/device/sources/controller/subdir.mk
-include src/usb_stack/usb_core/device/sources/classes/hid/subdir.mk
-include src/usb_stack/usb_core/device/sources/classes/common/subdir.mk
-include src/usb_stack/usb_core/device/sources/bsp/mks22f25612/subdir.mk
-include src/usb_stack/platform/soc/mks22f25612/subdir.mk
-include src/usb_stack/platform/arch/cortex_m/subdir.mk
-include src/usb_stack/os/bm/subdir.mk
-include src/usb_stack/hid_device/subdir.mk
-include src/usb_stack/adapter/sources/bm/subdir.mk
-include src/startup/subdir.mk
-include src/sbloader/src/subdir.mk
-include src/property/src/subdir.mk
-include src/packet/src/subdir.mk
-include src/memory/src/subdir.mk
-include src/drivers/uart/subdir.mk
-include src/drivers/smc/subdir.mk
-include src/drivers/microseconds/src/subdir.mk
-include src/drivers/lpi2c/src/subdir.mk
-include src/drivers/lpi2c/hal/subdir.mk
-include src/drivers/flexcan/src/subdir.mk
-include src/drivers/flexcan/hal/subdir.mk
-include src/drivers/flash/subdir.mk
-include src/drivers/dspi/src/subdir.mk
-include src/drivers/dspi/hal/subdir.mk
-include src/drivers/crc/src/subdir.mk
-include src/drivers/crc/hal/subdir.mk
-include src/crc/src/subdir.mk
-include src/bootloader/src/subdir.mk
-include src/autobaud/src/subdir.mk
-include MKS22F25612/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: flashloader.elf secondary-outputs

# Tool invocations
flashloader.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w  -g -T ../../../../common/linker/kds/MKS22F25612/MKS22FN256xxx12_ram_flashloader.ld -Xlinker --gc-sections -Wl,-Map,"flashloader.map" -Xlinker -z  -Xlinker muldefs   --specs=nano.specs          -Wall  -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mapcs  -Xlinker -static  -Xlinker --defsym=__ram_vector_table__=1 -o "flashloader.elf" -Xlinker --start-group $(OBJS) $(USER_OBJS) $(LIBS) -Xlinker --end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(S_UPPER_DEPS) flashloader.elf
	-@echo ' '

post-build:
	-C:\Workspaces\KDS\bootloader-S9KEAZN64AMLH\targets\MKS22F25612\kds\flashloader\debug\..\..\..\..\..\bin\create_flashloader_image_kds.bat C:\Workspaces\KDS\bootloader-S9KEAZN64AMLH\targets\MKS22F25612\kds\flashloader\debug '..'
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
