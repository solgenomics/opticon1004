# Target file name, defines the name of the output file, without the extention.
TARGET = XPA30925

# List C source files here that are part of your project.
# C dependencies are automatically generated.
CSRC = demo.c database.c input.c menu.c

# Project directories
OUT = obj
SRC = Sources
EXTRAINCDIRS = Sources\Inc

# --------------------------------------------------------------------------------------------------------------------------------------------------
# --------------------------------------------------------------------------------------------------------------------------------------------------
# ----------------------------------------------- No user serviceable parts below ------------------------------------------------------------------
# --------------------------------------------------------------------------------------------------------------------------------------------------
# --------------------------------------------------------------------------------------------------------------------------------------------------

# Compiler flags.
CFLAGS = -mcpu=arm7tdmi -mthumb-interwork
CFLAGS += -Os
CFLAGS += -funsigned-char -funsigned-bitfields -fshort-enums -mlong-calls
CFLAGS += -Wall -Wstrict-prototypes	-Wno-main
CFLAGS += -Wa,-adhlns=$(@:%.o=%.lst)
CFLAGS += -I. $(patsubst %,-I%,$(EXTRAINCDIRS))
CFLAGS += -std=gnu99 
CFLAGS += -MMD
CFLAGS += -DOPH1004

# Linker flags.
LDFLAGS = -nostartfiles -nostdlib -Wl,-Map=$(TARGET).map,--cref -Tlinker.ld -L. -lc -lm -lgcc

# Define programs and commands.
CC = arm-elf-gcc
LD = arm-elf-ld
OBJCOPY = arm-elf-objcopy
OBJDUMP = arm-elf-objdump
NM = arm-elf-nm

# Define Messages
# English
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_FLASH = Creating load file for Flash:
MSG_EXTENDED_LISTING = Creating Extended Listing:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = Linking:
MSG_COMPILING = Compiling:
MSG_CLEANING = Cleaning project:

# Define all object files.
OBJ = $(CSRC:%.c=$(OUT)/%.o)		

# Define all listing files.
LST = $(CSRC:%.c=$(OUT)/%.lst)

# Default target.
all: begin elf hex lss sym end


elf: $(TARGET).elf
hex: $(TARGET).hex
lss: $(TARGET).lss 
sym: $(TARGET).sym

# Eye candy.
begin:
	@echo
	@echo $(MSG_BEGIN)
	@if [ "$(OUT)" = "" ]; then \
		echo "The OUT directive is NOT set. Please set this to either a sub directory, or to . (A single dot character)" ;\
		exit 1;\
	fi
	@if [ "$(SRC)" = "" ]; then \
		echo "The SRC directive is NOT set. Please set this to either a sub directory, or to . (A single dot character)" ;\
		exit 1;\
	fi
	@if [ ! -d $(OUT) ]; then mkdir $(OUT); fi

end:
	@echo $(MSG_END)
	@echo


# Create final output files (.hex, .eep) from ELF output file.
%.hex: %.elf
	@echo
	@echo $(MSG_FLASH) $@
	$(OBJCOPY) -O ihex $< $@

# Create extended listing file from ELF output file.
%.lss: %.elf
	@echo
	@echo $(MSG_EXTENDED_LISTING) $@
	$(OBJDUMP) -h -S $< > $@

# Create a symbol table from ELF output file.
%.sym: %.elf
	@echo
	@echo $(MSG_SYMBOL_TABLE) $@
	$(NM) -n $< > $@

# Link: create ELF output file from object files.
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(OBJ)
%.elf: $(OBJ) makefile linker.ld
	@echo $(MSG_LINKING) $@
	$(CC) -mthumb $(CFLAGS) $(OBJ) startup.o --output $@ $(LDFLAGS)

# Compile: create object files from C source files. 
$(OBJ) : $(OUT)/%.o : $(SRC)/%.c
	@echo
	@echo $(MSG_COMPILING) $<
	$(CC) -c -mthumb $(CFLAGS) $< -o $@

# Target: clean project.
clean: begin clean_list end

clean_list :
	@echo $(MSG_CLEANING)
	rm -f $(TARGET).*
	rm -f -R ./$(OUT)
	rm -f appload.ini

# Include the dependency files.
-include $(OBJ:%.o=%.d) 
