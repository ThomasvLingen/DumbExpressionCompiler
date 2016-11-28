SOURCE = test
ASM_SOURCE = $(SOURCE).asm
OBJ = $(SOURCE).o
EXEC = test

AS = as
LD = ld

all: $(OBJ)
	@echo Linking...
	$(LD) -g $(OBJ) -o $(EXEC)
	@echo Done!

$(OBJ): $(ASM_SOURCE)
	@echo Compiling...
	$(AS) -g  $(ASM_SOURCE) -o $(OBJ)

debug: $(EXEC)
	gdb -tui $(EXEC)

clean:
	@echo Cleaning...
	rm -rf *.o
	rm -rf $(EXEC)

