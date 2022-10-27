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
login_sys1.lss \

FLASH_IMAGE += \
login_sys1.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: login_sys1.elf secondary-outputs

# Tool invocations
login_sys1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,login_sys1.map -mmcu=atmega32 -o "login_sys1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

login_sys1.lss: login_sys1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S login_sys1.elf  >"login_sys1.lss"
	@echo 'Finished building: $@'
	@echo ' '

login_sys1.hex: login_sys1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex login_sys1.elf  "login_sys1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: login_sys1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 login_sys1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) login_sys1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
