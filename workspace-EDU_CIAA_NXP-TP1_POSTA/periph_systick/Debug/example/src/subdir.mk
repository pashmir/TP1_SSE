################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cr_startup_lpc43xx.c \
../example/src/sysinit.c \
../example/src/systick.c 

OBJS += \
./example/src/cr_startup_lpc43xx.o \
./example/src/sysinit.o \
./example/src/systick.o 

C_DEPS += \
./example/src/cr_startup_lpc43xx.d \
./example/src/sysinit.d \
./example/src/systick.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__REDLIB__ -DCORE_M4 -I"/home/lautaro/embebidos/TP1_SSE/workspace-EDU_CIAA_NXP-TP1_POSTA/lpc_chip_43xx/inc" -I"/home/lautaro/embebidos/TP1_SSE/workspace-EDU_CIAA_NXP-TP1_POSTA/lpc_board_nxp_lpcxpresso_4337/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


