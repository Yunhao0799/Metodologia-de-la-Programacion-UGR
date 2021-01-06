all:	bin/ejercicio7

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio7

obj/Matriz2D.o:	src/Matriz2D.cpp include/Matriz2D.h 
	g++ -c -o obj/Matriz2D.o -Iinclude src/Matriz2D.cpp

obj/ejercicio7.o:	include/Matriz2D.h src/Matriz2D.cpp src/ejercicio7.cpp
	g++ -c -o obj/ejercicio7.o -Iinclude src/ejercicio7.cpp

bin/ejercicio7:	obj/ejercicio7.o obj/Matriz2D.o
	g++ -o bin/ejercicio7 obj/ejercicio7.o obj/Matriz2D.o


