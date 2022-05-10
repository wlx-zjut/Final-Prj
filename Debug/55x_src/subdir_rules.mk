################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
55x_src/%.obj: ../55x_src/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccs1110/ccs/tools/compiler/c5500_4.4.1/bin/cl55" -v5509A --memory_model=large -g --include_path="C:/Users/WLX/Desktop/Final Prj" --include_path="C:/Users/WLX/Desktop/Final Prj" --include_path="C:/Users/WLX/Desktop/Final Prj/include" --include_path="D:/ti/ccs1110/ccs/tools/compiler/c5500_4.4.1/include" --define=c5509a --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="55x_src/$(basename $(<F)).d_raw" --obj_directory="55x_src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


