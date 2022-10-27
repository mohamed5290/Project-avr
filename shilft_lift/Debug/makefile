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
shilft_lift.lss \

FLASH_IMAGE += \
shilft_lift.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: shilft_lift.elf secondary-outputs

# Tool invocations
shilft_lift.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,shilft_lift.map -mmcu=atmega32 -o "shilft_lift.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

shilft_lift.lss: shilft_lift.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S shilft_lift.elf  >"shilft_lift.lss"
	@echo 'Finished building: $@'
	@echo ' '

shilft_lift.hex: shilft_lift.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex shilft_lift.elf  "shilft_lift.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: shilft_lift.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 shilft_lift.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) shilft_lift.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
