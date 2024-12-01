SRC=src/
OBJ=obj/
BUILD_DIR=build/
CROSS_PREFIX=arm-linux-gnueabi-
OLLVM_COMPILER=/opt/obfuscator-llvm/build/bin/clang
OLLVM_FLAG=-target arm-linux-gnueabi -mllvm -sub -mllvm -sub_loop=3

LINKER=$(SRC)main.ld

all: $(BUILD_DIR)firmware.bin

$(OBJ)startup.o: $(SRC)startup.s
	$(CROSS_PREFIX)as -g -c $< -o $@

$(OBJ)main.o: $(SRC)main.c
	$(CROSS_PREFIX)gcc -g -c $< -o $@ 

$(OBJ)auth.o: $(SRC)auth.c
	$(OLLVM_COMPILER) -c $< -o $@ $(OLLVM_FLAG)

$(BUILD_DIR)firmware.elf: $(OBJ)startup.o $(OBJ)main.o $(OBJ)auth.o
	$(CROSS_PREFIX)ld -T$(LINKER) $^ -o $@

$(BUILD_DIR)firmware.bin: $(BUILD_DIR)firmware.elf 
	$(CROSS_PREFIX)objcopy -O binary $^ $@


clean:
	rm -f $(BUILD_DIR)* $(OBJ)*.o $(SRC)a.out


run: $(BUILD_DIR)firmware.bin
	qemu-system-arm -M virt -nographic -kernel $(BUILD_DIR)firmware.bin

tout:
	make clean
	make $(BUILD_DIR)firmware.bin
	make run
