all:	bin/ejercicio4

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio4

obj/utilidades.o:	src/utilidades.cpp include/utilidades.h 
	g++ -c -o obj/utilidades.o -Iinclude src/utilidades.cpp

obj/ejercicio4.o:	include/utilidades.h src/utilidades.cpp src/ejercicio4.cpp
	g++ -c -o obj/ejercicio4.o -Iinclude src/ejercicio4.cpp

bin/ejercicio4:	obj/ejercicio4.o obj/utilidades.o
	g++ -o bin/ejercicio4 obj/ejercicio4.o obj/utilidades.o


