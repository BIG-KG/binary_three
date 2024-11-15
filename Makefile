all: hello

hello:  main.o three_funk.o akinator.o three_data_base.o onegin.o
	g++ main.o three_funk.o akinator.o three_data_base.o onegin.o -o hell.exe

main.o:    main.cpp
	g++ -c main.cpp

three_funk.o: sourse\\three_funk.cpp
	g++ -c    sourse\\three_funk.cpp

akinator.o:   sourse\\akinator.cpp
	g++ -c    sourse\\akinator.cpp

three_data_base.o:   sourse\\three_data_base.cpp
	g++ -c           sourse\\three_data_base.cpp

onegin.o:  onegin\\onegin.cpp
	g++ -c onegin\\onegin.cpp

clean:
	rm -rf *.o hello2
