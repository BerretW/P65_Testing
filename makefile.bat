
del .\output\*.* /Q


cd .\src
cc65 -t none -O --cpu 65C02 main.c
ca65 --cpu 65C02 main.s -o ..\output\main.o
ca65 --cpu 65C02 utils.asm -o ..\output\utils.o
ca65 --cpu 65C02 vectors.asm -o ..\output\vectors.o
ca65 --cpu 65C02 kernel_c_lib.asm -o ..\output\kernel_c_lib.o
ca65 --cpu 65C02 interrupts.asm -o ..\output\interrupts.o


ca65 --cpu 65C02 test_asm.asm -o ..\output\test_asm.o
ca65 --cpu 65C02 vectors_asm.asm -o ..\output\vectors_asm.o

move *.s ..\output

cd ..\output

ld65 -C ..\config\APP_RAM_DISK.cfg -m main.map main.o kernel_c_lib.o interrupts.o vectors.o ..\library\p65.lib -o ..\output\RAM.bin
ld65 -C ..\config\APP_RAM_DISK.cfg test_asm.o kernel_c_lib.o interrupts.o vectors_asm.o -o ..\output\RAM_ASM.bin
