CFLAGS= -Wall -g
CC = gcc

run: clean graphe
	./graphe 

graphe: main.o graphe.o
	$(CC) main.o graphe.o -o graphe

%.o: %.c graphe.h
	$(CC) -c $< $(CFLAGS) 

# Le debug
valgrind: graphe
	valgrind --leak-check=full ./graphe

# Le clean
clean: 
	rm -f *.o
	rm -f graphe
	
	rm -rf ${ZIPNAME}
	rm -rf ${ZIPNAME}.zip

# Le .zip
ZIPNAME=Projet_Graphe
archive:
	rm -rf ${ZIPNAME}
	rm -rf ${ZIPNAME}.zip
	mkdir ${ZIPNAME}
	cp *.txt ${ZIPNAME}
	cp *.c ${ZIPNAME}
	cp *.h ${ZIPNAME}
	cp makefile ${ZIPNAME}
	zip -r $(ZIPNAME).zip $(ZIPNAME)
	rm -rf ${ZIPNAME}
	ls -l
