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
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
tpev3.hex \

SECONDARY_SIZE += \
tpev3.siz \


# All Target
all: tpev3.elf secondary-outputs

# Tool invocations
tpev3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
	arm-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -Xlinker --gc-sections -L/media/francois/24f21175-3164-433d-a50f-ba04f2ba892d/francois/Documents/ENSMA/Travail_A3/SETR/TP/Posix/ev3dev-c/lib -Wl,-Map,"tpev3.map" -o "tpev3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

tpev3.hex: tpev3.elf
	@echo 'Invoking: GNU ARM Cross Create Flash Image'
	arm-linux-gnueabi-objcopy -O ihex "tpev3.elf"  "tpev3.hex"
	@echo 'Finished building: $@'
	@echo ' '

tpev3.siz: tpev3.elf
	@echo 'Invoking: GNU ARM Cross Print Size'
	arm-linux-gnueabi-size --format=berkeley "tpev3.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) tpev3.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
