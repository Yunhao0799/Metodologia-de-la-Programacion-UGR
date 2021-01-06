all:	bin/ejercicio6

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio6

obj/utilidades.o:	src/utilidades.cpp include/utilidades.h 
	g++ -c -o obj/utilidades.o -Iinclude src/utilidades.cpp

obj/ejercicio6.o:	include/utilidades.h src/utilidades.cpp src/ejercicio6.cpp
	g++ -c -o obj/ejercicio6.o -Iinclude src/ejercicio6.cpp

bin/ejercicio6:	obj/ejercicio6.o obj/utilidades.o
	g++ -o bin/ejercicio6 obj/ejercicio6.o obj/utilidades.o


