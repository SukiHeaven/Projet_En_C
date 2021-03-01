
Run: ArbreB.o Sommet.o
	g++ -g -Wall ArbreB.o Sommet.o Main.cc -o Main
	./Main

ArbreB.o: ArbreB.cc ArbreB.h Sommet.h 
	g++ -c ArbreB.cc -o ArbreB.o

# Cryptage.o: Cryptage.cc Cryptage.h ArbreB.h Sommet.h 
# 	g++ -c -Wall -g Cryptage.cc -o Cryptage.o

Sommet.o: Sommet.cc Sommet.h 
	g++ -c -Wall -g Sommet.cc -o Sommet.o

clean:
	rm -f *.o ex

