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
ASS_intrrupt.lss \

FLASH_IMAGE += \
ASS_intrrupt.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ASS_intrrupt.elf secondary-outputs

# Tool invocations
ASS_intrrupt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ASS_intrrupt.map -mmcu=atmega32 -o "ASS_intrrupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ASS_intrrupt.lss: ASS_intrrupt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ASS_intrrupt.elf  >"ASS_intrrupt.lss"
	@echo 'Finished building: $@'
	@echo ' '

ASS_intrrupt.hex: ASS_intrrupt.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ASS_intrrupt.elf  "ASS_intrrupt.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ASS_intrrupt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ASS_intrrupt.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ASS_intrrupt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
