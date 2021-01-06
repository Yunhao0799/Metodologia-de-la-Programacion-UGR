all:	bin/main

clean:
	echo "Limpiando"
	rm obj/*

mrproper: clean	
	rm bin/main

obj/class.o:	src/class.cpp include/class.h 
	g++ -c -o obj/class.o -Iinclude src/class.cpp

obj/main.o:	include/class.h src/class.cpp src/main.cpp
	g++ -c -o obj/main.o -Iinclude src/main.cpp

bin/main:	obj/main.o obj/class.o
	g++ -o bin/main obj/main.o obj/class.o


