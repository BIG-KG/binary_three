all: hello

hello: main.o three_funk.o akinator.o
	g++ main.o three_funk.o akinator.o -o hell.exe

main.o: main.cpp
	g++ -c main.cpp

three_funk.o: sourse\\three_funk.cpp
	g++ -c    sourse\\three_funk.cpp

akinator.o:   sourse\\akinator.cpp
	g++ -c    sourse\\akinator.cpp

clean:
	rm -rf *.o hello2
