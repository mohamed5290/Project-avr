################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_programe.c \
../GINT_program.c \
../KPD_program.c \
../LCD_program.c \
../TMR_program.c \
../main.c 

OBJS += \
./DIO_programe.o \
./GINT_program.o \
./KPD_program.o \
./LCD_program.o \
./TMR_program.o \
./main.o 

C_DEPS += \
./DIO_programe.d \
./GINT_program.d \
./KPD_program.d \
./LCD_program.d \
./TMR_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


