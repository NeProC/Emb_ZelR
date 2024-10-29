all: Sens_prog

Sens_prog: Sens_info.o temp_functions.o
	gcc -o Sens_prog Sens_info.o temp_functions.o

Sens_info.o: Sens_info.c temp_functions.h
	gcc -c -o Sens_info.o Sens_info.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	del *.o del Sens_prog.exe