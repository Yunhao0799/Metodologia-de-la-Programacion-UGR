all:	bin/ejercicio4

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/ejercicio4

obj/Celda.o:	src/Celda.cpp include/Celda.h 
	g++ -c -o obj/Celda.o -Iinclude src/Celda.cpp

obj/Lista.o:	src/Lista.cpp include/Lista.h 
	g++ -c -o obj/Lista.o -Iinclude src/Lista.cpp
	
obj/ejercicio4.o:	include/Celda.h src/Celda.cpp include/Lista.h src/Lista.cpp src/ejercicio4.cpp
	g++ -c -o obj/ejercicio4.o -Iinclude src/ejercicio4.cpp

bin/ejercicio4:	obj/ejercicio4.o obj/ejercicio4.o obj/Lista.o obj/Celda.o
	g++ -o bin/ejercicio4 obj/ejercicio4.o obj/Lista.o obj/Celda.o
