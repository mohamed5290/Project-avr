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
test_pwm.lss \

FLASH_IMAGE += \
test_pwm.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: test_pwm.elf secondary-outputs

# Tool invocations
test_pwm.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,test_pwm.map -mmcu=atmega32 -o "test_pwm.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

test_pwm.lss: test_pwm.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S test_pwm.elf  >"test_pwm.lss"
	@echo 'Finished building: $@'
	@echo ' '

test_pwm.hex: test_pwm.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex test_pwm.elf  "test_pwm.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: test_pwm.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 test_pwm.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) test_pwm.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
