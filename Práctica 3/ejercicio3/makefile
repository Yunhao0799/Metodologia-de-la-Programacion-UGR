all:	bin/ejercicio3

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio3

obj/utilidades.o:	src/utilidades.cpp include/utilidades.h 
	g++ -c -o obj/utilidades.o -Iinclude src/utilidades.cpp

obj/ejercicio3.o:	include/utilidades.h src/utilidades.cpp src/ejercicio3.cpp
	g++ -c -o obj/ejercicio3.o -Iinclude src/ejercicio3.cpp

bin/ejercicio3:	obj/ejercicio3.o obj/utilidades.o
	g++ -o bin/ejercicio3 obj/ejercicio3.o obj/utilidades.o





