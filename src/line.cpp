#include <iostream>
#include <vector>
#include <fstream>
#include "screen.cpp"

class line{
	public:

	point p0, p1;
	pixel color;

	line(){
		p0 = point();
		p1 = point();
		color = pixel(0, 0, 0);
	}

	line(int x0, int y0, int x1, int y1){
		if(x1 - x0 < 0){
			p0 = point(x1, y1);
			p1 = point(x0, y0);
		}
		else{
			p0 = point(x0, y0);
			p1 = point(x1, y1);
		}
		color = pixel(0, 0, 0);
	}

	void set_color(pixel p){
		color = p;
	}

	void draw(screen s){
		if (p1[1] - p0[1] > p1[0] - p0[0]){
			draw_oct2(s);
		}
		else{
		//std::cout << "here\n";	
			if (p1[1] - p0[1] > 0)
				draw_oct1(s);
			else if((p1[1] - p0[1]) * -1 < p1[0] - p0[0])
				draw_oct8(s);
			else
				draw_oct7(s);
		}
	}

	void draw_oct1(screen s){
		point pn = point(p0[0], p0[1], p0[2]);
		int a = 2 * (p1[1]-p0[1]); int b = p0[0]-p1[0];
		int d = 2 * a + b;
		while (pn[0] <= p1[0]){
			//std::cout << d << "\n";
			s.plot(pn, color);
			if (d > 0){
				pn[1] +=  1;
				d += 2 * (b);	
			}	
			pn[0] += 1;
			d += 2 * (a);
		}
	}

	
	void draw_oct2(screen s){
		point pn = point(p0[0], p0[1], p0[2]);
		int a = 2 * (p1[1]-p0[1]); int b = p0[0]-p1[0];
		int d = 2 * a + b;
		while (pn[1] <= p1[1]){
			//std::cout << d << "\n";
			s.plot(pn, color);
			if (d < 0){
				pn[0] += 1;
				d += 2 * (a);	
			}	
			pn[1] +=  1;
			d += 2 * (b);
		}
	}
	void draw_oct7(screen s){
		point pn = point(p0[0], p0[1], p0[2]);
		int a = 2 * (p1[1]-p0[1]); int b = p0[0]-p1[0];
		int d = 2 * a + b;
		while (pn[1] >= p1[1]){
			//std::cout << d << "\n";
			s.plot(pn, color);
			if (d < 0){
				pn[0] += 1;
				d += 2 * (a);	
			}	
			pn[1] += -1;
			d += 2 * (b);
		}
	}
	void draw_oct8(screen s){
		point pn = point(p0[0], p0[1], p0[2]);
		int a = 2 * (p1[1]-p0[1]); int b = p0[0]-p1[0];
		int d = 2 * a + b;
		while (pn[0] <= p1[0]){
			//std::cout << d << "\n";
			s.plot(pn, color);
			if (d > 0){
				pn[1] += -1;
				d += 2 * (b);	
			}	
			pn[0] += 1;
			d += 2 * (a);
		}
	}
};
