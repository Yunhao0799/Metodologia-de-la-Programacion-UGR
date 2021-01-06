all:	bin/ejercicio6

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio6

obj/Matriz2D.o:	src/Matriz2D.cpp include/Matriz2D.h 
	g++ -c -o obj/Matriz2D.o -Iinclude src/Matriz2D.cpp

obj/ejercicio6.o:	include/Matriz2D.h src/Matriz2D.cpp src/ejercicio6.cpp
	g++ -c -o obj/ejercicio6.o -Iinclude src/ejercicio6.cpp

bin/ejercicio6:	obj/ejercicio6.o obj/Matriz2D.o
	g++ -o bin/ejercicio6 obj/ejercicio6.o obj/Matriz2D.o


