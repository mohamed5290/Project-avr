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
spi_test1.lss \

FLASH_IMAGE += \
spi_test1.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: spi_test1.elf secondary-outputs

# Tool invocations
spi_test1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,spi_test1.map -mmcu=atmega32 -o "spi_test1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

spi_test1.lss: spi_test1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S spi_test1.elf  >"spi_test1.lss"
	@echo 'Finished building: $@'
	@echo ' '

spi_test1.hex: spi_test1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex spi_test1.elf  "spi_test1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: spi_test1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 spi_test1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) spi_test1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
