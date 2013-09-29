#Lab_03: Count.o CountArray.o Executive.o main.o
#	g++ -std=c++11 -o Lab_03 main.o Count.o CountArray.o Executive.o

#Count.o: Count.cpp Count.h
#	g++ -std=c++11 -c Count.cpp

#CountArray.o: CountArray.cpp CountArray.h Count.h
#	g++ -std=c++11 -c CountArray.cpp

Lab_03: Executive.o main.o
	g++ -std=c++11 -o Lab_03 main.o Executive.o

Executive.o: Executive.cpp Executive.h Count.h CountArray.h
	g++ -std=c++11 -c Executive.cpp

main.o: main.cpp Executive.h
	g++ -std=c++11 -c main.cpp

clean:
	rm Lab_03 main.o Executive.o
