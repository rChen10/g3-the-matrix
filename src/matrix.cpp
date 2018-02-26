#include "line.cpp"
#include <vector>
#include <iostream>

class matrix{
	std::vector< std::vector<int> > m;
	int s;

	public:
	
	matrix(){
		m = std::vector<std::vector<int>>();
		s = 0;
	}

	matrix(int x, int y){
		std::vector<int> *v;
		for(int i = 0; i < x; i++){
			v = new std::vector<int>(y, 0);
			m.push_back(*v);
		}
		s = x;
	}
	
	matrix& operator+=(std::vector<int>& p){
		m.push_back(p);
		s++;
		return *this;
	}

	matrix& operator+=(line l){
		m.push_back(l.p0);
		m.push_back(l.p1);
		s+=2;
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

	void draw(screen scrn){
		//line *l;
		//point *p0, *p1;
		for(int i = 0; i < s; i+=2){
			auto p0 = point(m[i]);
			auto p1 = point(m[i+1]);
			//std::cout << (*p1)[0] << " " << (*p1)[1] << "\n";
			auto l = line(p0, p1);
			l.draw(scrn);

			//std::cout << (*l).p0[0] << " " << (*l).p0[1] << " " << (*l).p1[0] << (*l).p1[1] << "\n";
			//free(l);
			//free(p0); free(p1);
		}
	}
	
	private:
};

std::ostream& operator<<(std::ostream& os, matrix& m){
	//os << m.size() << "\n";
	for(int i = 0; i < m.size(); i++){
		os << "| ";
		for(int j = 0; j < m[0].size(); j++){
			os << m[i][j] << " ";
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
