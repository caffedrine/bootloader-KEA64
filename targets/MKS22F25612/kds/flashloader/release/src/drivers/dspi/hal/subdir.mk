################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/dspi/hal/fsl_dspi_hal.c 

OBJS += \
./src/drivers/dspi/hal/fsl_dspi_hal.o 

C_DEPS += \
./src/drivers/dspi/hal/fsl_dspi_hal.d 


# Each subdirectory must supply rules for building sources it contributes
src/drivers/dspi/hal/fsl_dspi_hal.o: C:/Workspaces/KDS/FSL_Kinetis_Bootloader_1_2_0_KS22_1_0_0/src/drivers/dspi/hal/fsl_dspi_hal.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -w -DNDEBUG -DCPU_MKS22FN256VLL12 -DCPU_IS_ARM_CORTEX_M4=1 -DBL_TARGET_RAM -I../../../src -I../../../../../src/include -I../../../../../src/include/device -I../../../../../src -I../../../../../src/autobaud -I../../../../../src/drivers -I../../../../../src/startup -I../../../../../src/drivers/uart -I../../../../../src/usb_stack/hid_device -I../../../../../src/usb_stack/adapter/sources -I../../../../../src/usb_stack/adapter/sources/bm -I../../../../../src/usb_stack/os/bm -I../../../../../src/usb_stack/platform/arch/cortex_m -I../../../../../src/usb_stack/platform/soc/mks22f25612 -I../../../../../src/usb_stack/platform/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/include -I../../../../../src/usb_stack/usb_core/device/include/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources -I../../../../../src/usb_stack/usb_core/device/sources/bsp/mks22f25612 -I../../../../../src/usb_stack/usb_core/device/sources/classes/common -I../../../../../src/usb_stack/usb_core/device/sources/classes/hid -I../../../../../src/usb_stack/usb_core/device/sources/classes/include -I../../../../../src/usb_stack/usb_core/device/sources/controller -I../../../../../src/usb_stack/usb_core/device/sources/controller/khci -I../../../../../src/usb_stack/usb_core/device/sources/controller/ehci -I../../../../../src/usb_stack/usb_core/hal -I../../../../../src/usb_stack/usb_core/include -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


