################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
implimntation_dio.lss \

FLASH_IMAGE += \
implimntation_dio.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: implimntation_dio.elf secondary-outputs

# Tool invocations
implimntation_dio.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,implimntation_dio.map -mmcu=atmega32 -o "implimntation_dio.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

implimntation_dio.lss: implimntation_dio.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S implimntation_dio.elf  >"implimntation_dio.lss"
	@echo 'Finished building: $@'
	@echo ' '

implimntation_dio.hex: implimntation_dio.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex implimntation_dio.elf  "implimntation_dio.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: implimntation_dio.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 implimntation_dio.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) implimntation_dio.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
