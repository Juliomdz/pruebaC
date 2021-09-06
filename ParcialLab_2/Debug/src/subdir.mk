################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Articulo.c \
../src/ParcialLab_2.c \
../src/PosicionArancelaria.c \
../src/utn.c 

OBJS += \
./src/Articulo.o \
./src/ParcialLab_2.o \
./src/PosicionArancelaria.o \
./src/utn.o 

C_DEPS += \
./src/Articulo.d \
./src/ParcialLab_2.d \
./src/PosicionArancelaria.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


