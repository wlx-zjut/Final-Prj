################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccs1110/ccs/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./ICETEK-VC5509-EDU.obj" \
"./aic23.obj" \
"./i2c.obj" \
"./key.obj" \
"./lcddisplay.obj" \
"./main.obj" \
"./sdram_init.obj" \
"./util.obj" \
"./vectors.obj" \
"./55x_src/abias.obj" \
"./55x_src/add.obj" \
"./55x_src/araw.obj" \
"./55x_src/arct2.obj" \
"./55x_src/atan16.obj" \
"./55x_src/aubias.obj" \
"./55x_src/bexp.obj" \
"./55x_src/cbias.obj" \
"./55x_src/cbrev.obj" \
"./55x_src/cbrev32.obj" \
"./55x_src/cfft32_noscale.obj" \
"./55x_src/cfft32_scale.obj" \
"./55x_src/cfft_noscale.obj" \
"./55x_src/cfft_scale.obj" \
"./55x_src/ldiv16.obj" \
"./55x_src/log_10.obj" \
"./55x_src/log_2.obj" \
"./55x_src/logn.obj" \
"./55x_src/sqrtv.obj" \
"./55x_src/sub.obj" \
"./55x_src/unpack.obj" \
"./55x_src/unpack32.obj" \
"./55x_src/unpacki.obj" \
"./55x_src/unpacki32.obj" \
"./twiddle/twiddle.obj" \
"../lcd.cmd" \
"../lib/55xdspx.lib" \
"../lib/rts55x.lib" \
$(GEN_CMDS__FLAG) \
-l"C:/Users/WLX/Desktop/Final Prj/lib/55xdspx.lib" \
-l"C:/Users/WLX/Desktop/Final Prj/lib/55xdspx.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include 55x_src/subdir_vars.mk
-include lib/subdir_vars.mk
-include twiddle/subdir_vars.mk
-include subdir_rules.mk
-include 55x_src/subdir_rules.mk
-include lib/subdir_rules.mk
-include twiddle/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Final\ Prj.out \

EXE_OUTPUTS__QUOTED += \
"Final Prj.out" \

BIN_OUTPUTS += \
Final\ Prj.hex \

BIN_OUTPUTS__QUOTED += \
"Final Prj.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Final Prj.out"

# Tool invocations
Final\ Prj.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C5500 Linker'
	"D:/ti/ccs1110/ccs/tools/compiler/c5500_4.4.1/bin/cl55" -v5509A --memory_model=large -g --define=c5509a --display_error_number --diag_warning=225 --ptrdiff_size=32 -z -m"Final Prj.map" --stack_size=0x200 --heap_size=0x400 -i"D:/ti/ccs1110/ccs/tools/compiler/c5500_4.4.1/lib" -i"C:/Users/WLX/Desktop/Final Prj/lib" -i"D:/ti/ccs1110/ccs/tools/compiler/c5500_4.4.1/include" --reread_libs --display_error_number --warn_sections --xml_link_info="Final Prj_linkInfo.xml" --rom_model --sys_stacksize=0x200 -o "Final Prj.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

Final\ Prj.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: C5500 Hex Utility'
	"D:/ti/ccs1110/ccs/tools/compiler/c5500_4.4.1/bin/hex55"  -o "Final Prj.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "ICETEK-VC5509-EDU.obj" "aic23.obj" "i2c.obj" "key.obj" "lcddisplay.obj" "main.obj" "sdram_init.obj" "util.obj" "vectors.obj" "55x_src\abias.obj" "55x_src\add.obj" "55x_src\araw.obj" "55x_src\arct2.obj" "55x_src\atan16.obj" "55x_src\aubias.obj" "55x_src\bexp.obj" "55x_src\cbias.obj" "55x_src\cbrev.obj" "55x_src\cbrev32.obj" "55x_src\cfft32_noscale.obj" "55x_src\cfft32_scale.obj" "55x_src\cfft_noscale.obj" "55x_src\cfft_scale.obj" "55x_src\ldiv16.obj" "55x_src\log_10.obj" "55x_src\log_2.obj" "55x_src\logn.obj" "55x_src\sqrtv.obj" "55x_src\sub.obj" "55x_src\unpack.obj" "55x_src\unpack32.obj" "55x_src\unpacki.obj" "55x_src\unpacki32.obj" "twiddle\twiddle.obj" 
	-$(RM) "ICETEK-VC5509-EDU.d" "aic23.d" "i2c.d" "key.d" "lcddisplay.d" "main.d" "sdram_init.d" "util.d" 
	-$(RM) "vectors.d" "55x_src\abias.d" "55x_src\add.d" "55x_src\araw.d" "55x_src\arct2.d" "55x_src\atan16.d" "55x_src\aubias.d" "55x_src\bexp.d" "55x_src\cbias.d" "55x_src\cbrev.d" "55x_src\cbrev32.d" "55x_src\cfft32_noscale.d" "55x_src\cfft32_scale.d" "55x_src\cfft_noscale.d" "55x_src\cfft_scale.d" "55x_src\ldiv16.d" "55x_src\log_10.d" "55x_src\log_2.d" "55x_src\logn.d" "55x_src\sqrtv.d" "55x_src\sub.d" "55x_src\unpack.d" "55x_src\unpack32.d" "55x_src\unpacki.d" "55x_src\unpacki32.d" "twiddle\twiddle.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

