CC=gcc.exe

all: Sens_prog  
#	del *.o							#для Win10
	rm *.o							#для Linux
#	Sens_prog.exe

Sens_prog: Sens_info.o temp_functions.o
	$(CC) -o Sens_prog Sens_info.o temp_functions.o

Sens_info.o: Sens_info.c temp_functions.h
	$(CC) -c -o Sens_info.o Sens_info.c

temp_functions.o: temp_functions.c
	$(CC) -c -o temp_functions.o temp_functions.c

clean:
	del *.o Sens_prog.exe

cleano:
	del *.o

start:
	Sens_prog.exe