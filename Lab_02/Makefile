Lab_02: main.o Executive.o Matrix.o
	g++ -o -std=c++11 Lab_02 main.o Executive.o Matrix.o

main.o: main.cpp Executive.h Matrix.h
	g++ -c -std=c++11 main.cpp

Executive.o: Executive.cpp Executive.h Matrix.h
	g++ -c -std=c++11 Executive.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c -std=c++11 Matrix.cpp

clean:
	rm main.o Executive.o Matrix.o Lab_02
