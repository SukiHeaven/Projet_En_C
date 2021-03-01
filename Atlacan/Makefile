run : main
	./main
	
main : main.o atlacan.o
	gcc -Wall -o main atlacan.o main.o
	
main.o : main.c atlacan.h
	gcc -Wall -o main.o -c main.c 

atlacan.o : atlacan.h atlacan.c
	gcc -Wall -o atlacan.o -c atlacan.c 
	
	
clean : 
	rm -f main.o
	rm -f main
	rm -f atlacan.o