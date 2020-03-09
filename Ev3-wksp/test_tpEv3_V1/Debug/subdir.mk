################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bal.c \
../main.c \
../mdd.c \
../mdd_gen.c 

OBJS += \
./bal.o \
./main.o \
./mdd.o \
./mdd_gen.o 

C_DEPS += \
./bal.d \
./main.d \
./mdd.d \
./mdd_gen.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


