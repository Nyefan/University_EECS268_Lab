Lab_05: Knights_Tour.o BoardSpace.0 main.o
	g++ -std=c++11 -o Lab_04 main.o BoardSpace.o Knights_Tour.o

BoardSpace.o: BoardSpace.cpp BoardSpace.h
	g++ -std=c++11 -c BoardSpace.cpp
	
Knights_Tour.o: Knights_Tour.cpp Knights_Tour.h BoardSpace.h
	g++ -std=c++11 -c Knights_Tour.cpp

main.o: main.cpp Knights_Tour.h
	g++ -std=c++11 -c main.cpp

clean:
	rm Lab_05 BoardSpace.o Knights_Tour.o main.o
