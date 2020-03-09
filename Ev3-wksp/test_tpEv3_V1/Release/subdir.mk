################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bal.c \
../mdd.c \
../mdd_gen.c \
../test_bal.c \
../test_mdd.c \
../test_mdd_gen.c 

O_SRCS += \
../bal.o \
../main.o \
../mdd.o 

OBJS += \
./bal.o \
./mdd.o \
./mdd_gen.o \
./test_bal.o \
./test_mdd.o \
./test_mdd_gen.o 

C_DEPS += \
./bal.d \
./mdd.d \
./mdd_gen.d \
./test_bal.d \
./test_mdd.d \
./test_mdd_gen.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


