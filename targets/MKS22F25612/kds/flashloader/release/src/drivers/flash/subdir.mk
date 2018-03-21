################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_cache_clear.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_command_sequence.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_densities_k_series.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_erase.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_erase_all.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_erase_all_unsecure.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_get_property.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_get_security_state.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_init.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_is_execute_only.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_is_protected.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_program.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_program_once.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_read_once.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_read_resource.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_security_bypass.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_verify_erase.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_verify_erase_all.c \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_verify_program.c 

OBJS += \
./src/drivers/flash/flash_cache_clear.o \
./src/drivers/flash/flash_command_sequence.o \
./src/drivers/flash/flash_densities_k_series.o \
./src/drivers/flash/flash_erase.o \
./src/drivers/flash/flash_erase_all.o \
./src/drivers/flash/flash_erase_all_unsecure.o \
./src/drivers/flash/flash_get_property.o \
./src/drivers/flash/flash_get_security_state.o \
./src/drivers/flash/flash_init.o \
./src/drivers/flash/flash_is_execute_only.o \
./src/drivers/flash/flash_is_protected.o \
./src/drivers/flash/flash_program.o \
./src/drivers/flash/flash_program_once.o \
./src/drivers/flash/flash_read_once.o \
./src/drivers/flash/flash_read_resource.o \
./src/drivers/flash/flash_security_bypass.o \
./src/drivers/flash/flash_verify_erase.o \
./src/drivers/flash/flash_verify_erase_all.o \
./src/drivers/flash/flash_verify_program.o 

C_DEPS += \
./src/drivers/flash/flash_cache_clear.d \
./src/drivers/flash/flash_command_sequence.d \
./src/drivers/flash/flash_densities_k_series.d \
./src/drivers/flash/flash_erase.d \
./src/drivers/flash/flash_erase_all.d \
./src/drivers/flash/flash_erase_all_unsecure.d \
./src/drivers/flash/flash_get_property.d \
./src/drivers/flash/flash_get_security_state.d \
./src/drivers/flash/flash_init.d \
./src/drivers/flash/flash_is_execute_only.d \
./src/drivers/flash/flash_is_protected.d \
./src/drivers/flash/flash_program.d \
./src/drivers/flash/flash_program_once.d \
./src/drivers/flash/flash_read_once.d \
./src/drivers/flash/flash_read_resource.d \
./src/drivers/flash/flash_security_bypass.d \
./src/drivers/flash/flash_verify_erase.d \
./src/drivers/flash/flash_verify_erase_all.d \
./src/drivers/flash/flash_verify_program.d 


# Each subdirectory must supply rules for building sources it contributes
src/drivers/flash/flash_cache_clear.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_cache_clear.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_command_sequence.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_command_sequence.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_densities_k_series.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_densities_k_series.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_erase.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_erase.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_erase_all.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_erase_all.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_erase_all_unsecure.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_erase_all_unsecure.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_get_property.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_get_property.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_get_security_state.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_get_security_state.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_init.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_is_execute_only.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_is_execute_only.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_is_protected.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_is_protected.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_program.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_program_once.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_program_once.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_read_once.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_read_once.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_read_resource.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_read_resource.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_security_bypass.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_security_bypass.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_verify_erase.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_verify_erase.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_verify_erase_all.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_verify_erase_all.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/drivers/flash/flash_verify_program.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/flash/src/flash_verify_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


