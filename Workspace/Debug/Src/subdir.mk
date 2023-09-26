################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/EXTI.c \
../Src/GPIO.c \
../Src/LED.c \
../Src/NVIC_Program.c \
../Src/PushButton.c \
../Src/RCC_program.c \
../Src/STK_program.c \
../Src/Seg-5161BS.c \
../Src/keypad.c \
../Src/lcd.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/EXTI.o \
./Src/GPIO.o \
./Src/LED.o \
./Src/NVIC_Program.o \
./Src/PushButton.o \
./Src/RCC_program.o \
./Src/STK_program.o \
./Src/Seg-5161BS.o \
./Src/keypad.o \
./Src/lcd.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/EXTI.d \
./Src/GPIO.d \
./Src/LED.d \
./Src/NVIC_Program.d \
./Src/PushButton.d \
./Src/RCC_program.d \
./Src/STK_program.d \
./Src/Seg-5161BS.d \
./Src/keypad.d \
./Src/lcd.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/EXTI.cyclo ./Src/EXTI.d ./Src/EXTI.o ./Src/EXTI.su ./Src/GPIO.cyclo ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/LED.cyclo ./Src/LED.d ./Src/LED.o ./Src/LED.su ./Src/NVIC_Program.cyclo ./Src/NVIC_Program.d ./Src/NVIC_Program.o ./Src/NVIC_Program.su ./Src/PushButton.cyclo ./Src/PushButton.d ./Src/PushButton.o ./Src/PushButton.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/STK_program.cyclo ./Src/STK_program.d ./Src/STK_program.o ./Src/STK_program.su ./Src/Seg-5161BS.cyclo ./Src/Seg-5161BS.d ./Src/Seg-5161BS.o ./Src/Seg-5161BS.su ./Src/keypad.cyclo ./Src/keypad.d ./Src/keypad.o ./Src/keypad.su ./Src/lcd.cyclo ./Src/lcd.d ./Src/lcd.o ./Src/lcd.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

