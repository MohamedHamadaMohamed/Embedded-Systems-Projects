################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_Motor.c \
../GPIO.c \
../I2C.c \
../LCD.c \
../Timer.c \
../UART.c \
../external_EEPROM.c \
../main.c 

OBJS += \
./DC_Motor.o \
./GPIO.o \
./I2C.o \
./LCD.o \
./Timer.o \
./UART.o \
./external_EEPROM.o \
./main.o 

C_DEPS += \
./DC_Motor.d \
./GPIO.d \
./I2C.d \
./LCD.d \
./Timer.d \
./UART.d \
./external_EEPROM.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


