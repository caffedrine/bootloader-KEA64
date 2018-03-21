################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/startup/startup.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/targets/MKS22F25612/src/startup/system_MKS22F25612.c 

S_UPPER_SRCS += \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/startup/crt0_gcc.S \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/targets/MKS22F25612/src/startup/gcc/startup_MKS22F25612.S 

OBJS += \
./src/startup/crt0_gcc.o \
./src/startup/startup.o \
./src/startup/startup_MKS22F25612.o \
./src/startup/system_MKS22F25612.o 

C_DEPS += \
./src/startup/startup.d \
./src/startup/system_MKS22F25612.d 

S_UPPER_DEPS += \
./src/startup/crt0_gcc.d \
./src/startup/startup_MKS22F25612.d 


# Each subdirectory must supply rules for building sources it contributes
src/startup/crt0_gcc.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/startup/crt0_gcc.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w  -g -x assembler-with-cpp -DNDEBUG -I../../../../../src/include -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mapcs  -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/startup/startup.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/startup/startup.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w  -g -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/startup/startup_MKS22F25612.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/targets/MKS22F25612/src/startup/gcc/startup_MKS22F25612.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w  -g -x assembler-with-cpp -DNDEBUG -I../../../../../src/include -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mapcs  -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/startup/system_MKS22F25612.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/targets/MKS22F25612/src/startup/system_MKS22F25612.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w  -g -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


