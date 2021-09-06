################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/informe.c \
../src/main.c \
../src/pNacionalidad.c \
../src/pProducto.c \
../src/pTipo.c \
../src/utn.c 

OBJS += \
./src/informe.o \
./src/main.o \
./src/pNacionalidad.o \
./src/pProducto.o \
./src/pTipo.o \
./src/utn.o 

C_DEPS += \
./src/informe.d \
./src/main.d \
./src/pNacionalidad.d \
./src/pProducto.d \
./src/pTipo.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


