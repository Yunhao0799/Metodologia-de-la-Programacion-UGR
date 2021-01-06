all:	bin/ejercicio2

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio2

obj/utilidades.o:	src/utilidades.cpp include/utilidades.h 
	g++ -c -o obj/utilidades.o -Iinclude src/utilidades.cpp

obj/ejercicio2.o:	include/utilidades.h src/utilidades.cpp src/ejercicio2.cpp
	g++ -c -o obj/ejercicio2.o -Iinclude src/ejercicio2.cpp

bin/ejercicio2:	obj/ejercicio2.o obj/utilidades.o
	g++ -o bin/ejercicio2 obj/ejercicio2.o obj/utilidades.o


