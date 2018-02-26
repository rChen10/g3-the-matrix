all: line matrix matrix_test
	g++ *.o
	./a.out
	rm *.o

matrix_test: ./src/matrix_test
	g++ ./src/matrix_text.cpp -c

pixel: ./src/pixel.cpp
	g++ ./src/pixel.cpp -c

line: screen ./src/line.cpp
	g++ ./src/line.cpp -c

screen: pixel ./src/screen.cpp
	g++ ./src/screen.cpp -c

matrix: screen ./src/matrix.cpp
	g++ ./src/matrix.cpp -c
