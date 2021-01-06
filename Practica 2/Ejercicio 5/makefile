all:	bin/ejercicio5

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio5

obj/utilidades.o:	src/utilidades.cpp include/utilidades.h 
	g++ -c -o obj/utilidades.o -Iinclude src/utilidades.cpp

obj/ejercicio5.o:	include/utilidades.h src/utilidades.cpp src/ejercicio5.cpp
	g++ -c -o obj/ejercicio5.o -Iinclude src/ejercicio5.cpp

bin/ejercicio5:	obj/ejercicio5.o obj/utilidades.o
	g++ -o bin/ejercicio5 obj/ejercicio5.o obj/utilidades.o


