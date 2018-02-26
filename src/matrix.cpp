//#include "screen.cpp"
#include <vector>
#include <iostream>

class matrix{
	std::vector< std::vector<int> > m;
	int s;

	public:
	
	matrix(){
		m = std::vector<std::vector<int>>();
	}
	
	matrix& operator+=(std::vector<int>& p){
		m.push_back(p);
		s++;
		return *this;
	}

	void ident(){
		for(int i = 0; i < s; i++){
			for(int j = 0; j < m[i].size(); j++){
				if( j == i )
					m[i][j] = 1;
				else
					m[i][j] = 0;
			}
		}	
	}

	matrix& operator*=(matrix& m){
		
	}

	int size(){
		return s;
	}

	std::vector<int> operator[](int i){
		return m[i];
	}
	
	private:
};

std::ostream& operator<<(std::ostream& os, matrix& m){
	for(int i = 0; i < m.size(); i++){
		os << "| ";
		for(int j = 0; j < m[j].size(); j++){
			os << m[i][j];
		}
		os << "|\n";
	}

	return os;
}

matrix operator*(matrix& m1, matrix& m2){
	int sum = 0;
	matrix m = matrix();
	std::vector<int> *v;
	for(int i = 0; i < m1.size(); i++){
		v = new std::vector<int>();
		for(int j = 0; j < m2[0].size(); j++){
			for(int k = 0; k < m2.size(); k++){
				sum += m1[i][k] * m2[k][j];
			}
			(*v).push_back(sum);
			sum = 0;
		}
		m += (*v);
	}
	return m;
}
