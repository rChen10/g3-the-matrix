#include "matrix.cpp"

int main(){
	matrix m = matrix();

	std::cout << "creating points\n";
	//simple square
	point p1 = point(100, 100);
	point p2 = point(400, 100);
	point p3 = point(400, 400);
	point p4 = point(100, 400);

	//std::cout << m.size();
	std::cout << "creating edges\n";

	line e1 = line(p1, p2);
	line e2 = line(p2, p3);
	line e3 = line(p3, p4);
	line e4 = line(p4, p1);

	std::cout << "adding first edge using point\n";

	m += p1;
	m += p2;

	std::cout << "adding rest of edges using line\n";
	
	m += e2;
	m += e3;
	m += e4;

	std::cout << "printing matrix (points are sorted)\n";
	std::cout << m;

	std::cout << "creating identity matrix\n";
	matrix iden = matrix(8, 8);
	iden.ident();

	std::cout << "printing identity matrix\n";
	std::cout << iden;
	std::cout << "\n";


	std::cout << "multiplying and printing result\n";
	matrix result = iden * m;

	std::cout << result;

	std::cout << "rendering to square1.ppm\n";
	screen s = screen(500, 500);
	m.draw(s);
	//e1.draw(s); e2.draw(s); e3.draw(s); e4.draw(s);
	s.render("square1.ppm");

	//std::cout << "creating transform matrix\n";
	//iden[
}
