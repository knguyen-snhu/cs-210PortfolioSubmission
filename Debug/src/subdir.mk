################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BankCalculator.cpp \
../src/Kevin_Nguyen_Airgead_Bank_App.cpp 

OBJS += \
./src/BankCalculator.o \
./src/Kevin_Nguyen_Airgead_Bank_App.o 

CPP_DEPS += \
./src/BankCalculator.d \
./src/Kevin_Nguyen_Airgead_Bank_App.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


