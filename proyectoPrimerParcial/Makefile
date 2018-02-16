all:
	gcc findMultiplesInArray.c -o findMultiplesInArray.exe
	./findMultiplesInArray.exe

findMultiplesInArray.o: findMultiplesInArray.c
	gcc -c findMultiplesInArray.c
	

test: findMultiplesInArray.o 
	gcc findMultiplesInArray.c -o findMultiplesInArray.exe
	./maintest.tcl ./findMultiplesInArray.exe
	