all: ./src/matrixTest
	./src/matrixTest
	rm ./src/matrixTest

pixel: ./src/pixel.cpp
	g++ ./src/pixel.cpp -c

line: screen ./src/line.cpp
	g++ ./src/line.cpp -c

screen: pixel ./src/screen.cpp
	g++ ./src/screen.cpp -c

matrix: screen ./src/matrix.cpp
	g++ ./src/matrix.cpp -c
