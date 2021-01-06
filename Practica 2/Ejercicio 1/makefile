
all:	bin/ejercicio1

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio1

obj/utilidades.o:	src/utilidades.cpp include/utilidades.h 
	g++ -c -o obj/utilidades.o -Iinclude src/utilidades.cpp

obj/ejercicio1.o:	include/utilidades.h src/utilidades.cpp src/ejercicio1.cpp
	g++ -c -o obj/ejercicio1.o -Iinclude src/ejercicio1.cpp

bin/ejercicio1:	obj/ejercicio1.o obj/utilidades.o
	g++ -o bin/ejercicio1 obj/ejercicio1.o obj/utilidades.o




