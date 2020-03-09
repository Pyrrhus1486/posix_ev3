################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../communication.c \
../main.c \
../mdd.c \
../myev3.c \
../time_util.c \
../workers.c 

OBJS += \
./communication.o \
./main.o \
./mdd.o \
./myev3.o \
./time_util.o \
./workers.o 

C_DEPS += \
./communication.d \
./main.d \
./mdd.d \
./myev3.d \
./time_util.d \
./workers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-linux-gnueabi-gcc -mcpu=arm926ej-s -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -D__ARM_ARCH_4T__=1 -I/media/francois/24f21175-3164-433d-a50f-ba04f2ba892d/francois/Documents/ENSMA/Travail_A3/SETR/TP/Posix/ev3dev-c/source/ev3 -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


