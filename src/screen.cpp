#include <iostream>
#include <fstream>
#include <vector>
#include "pixel.cpp"

class point : public std::vector<int>{
	public:
		//std::vector<int> v;

	point(){
		//v = std::vector<int>(4, 0);
	}

	point(int x) : std::vector<int>(4, 0){
		(*this)[0] = x;
		(*this)[3] = 1;
	}

	point(int x, int y) : std::vector<int>(4, 0){
		//v = std::vector<int>(4, 0);
		(*this)[0] = x;
		(*this)[1] = y;
		(*this)[3] = 1;
	}

	point(int x, int y, int z) : std::vector<int>(4, 0){
		//v = std::vector<int>(4, 0);
		(*this)[0] = x;
		(*this)[1] = y;
		(*this)[2] = z;
		(*this)[3] = 1;
	}

	point(std::vector<int> v) : std::vector<int>(4, 0){
		(*this)[0] = v[0];
		(*this)[1] = v[1];
		(*this)[2] = v[2];
		(*this)[3] = 1;
	}

	//int operator[](int i){
	//	return v[i];
	//}

//	void add(int pos, int i){
//		this[pos] += i;
//	}
};

class screen{
	public:
		std::vector<pixel> colors;
		pixel ***grid;
		int h, w;

		screen(){
			grid = 0;
		}

		screen(int x, int y){
			w = x;
			h = y;

			colors.push_back( pixel(255, 255, 255) );
			//colors.push_back( pixel(0, 0, 0) );

			grid = new pixel**[y];
			for (int i = 0; i < h; i++){
				grid[i] = new pixel*[x];
				for(int j = 0; j < w; j++){
					grid[i][j] = &colors[0];
				}
			}

		}

		void render(std::string name){
			std::ofstream f;
			f.open(name);
			f << "P3\n";
			f << w << " " << h << "\n";
			f << "255\n";

			for(int i = 0; i < h; i++){
				for(int j = 0; j < w; j++){
					f << *(grid[i][j]);
					if (j != (w-1))
						f << " ";
				}
				//if (i != (h-1))
					f << "\n";
			}

			f.close();
		}

		void plot(point& p, pixel& col){
			pixel& c = insert_color(col);

			grid[p[1]][p[0]] = &c;
		}

		pixel& insert_color(pixel& col){
			for (int i = 0; i < colors.size(); i++){
				if( colors[i] == col ){
					//delete &col;
					return colors[i];
				}
			}

			colors.push_back(col);
			return col;
		}
};
