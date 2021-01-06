all:	bin/ejercicio5

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio5

obj/lista.o:	src/lista.cpp include/lista.h 
	g++ -c -o obj/lista.o -Iinclude src/lista.cpp

obj/ejercicio5.o:	include/lista.h src/lista.cpp src/ejercicio5.cpp
	g++ -c -o obj/ejercicio5.o -Iinclude src/ejercicio5.cpp

bin/ejercicio5:	obj/ejercicio5.o obj/lista.o
	g++ -o bin/ejercicio5 obj/ejercicio5.o obj/lista.o





