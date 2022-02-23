#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main(){
	using namespace Graph_lib;
	Point tl{100,100};
	Simple_window win{tl,600,400,"My Window"};

	//12.7
	Axis xa {Axis::x, Point{20,300}, 300, 10, "x.axis"};
	Axis ya {Axis::y, Point{20,300}, 280, 10, "y.axis"};
	
	Function sine {sin, 0, 100, Point{20,150}, 1000, 50, 50};
	
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	Rectangle r{Point{200,200}, 100, 50};

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});

	Text t{Point{150,150}, "This Is The Way."};

	Circle c{Point{100,200},50};
	Ellipse e{Point{100,200},75,25};
	Mark m{Point{100,200}, 'x'};

	Image one{Point{100,50}, "one.jpg"};
	Image two{Point{300,50}, "two.jpg"};



	//Display
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.attach(one);
	win.attach(two);

	
	//Changes
	r.set_fill_color(Color::blue);
	poly.set_style(Line_style(Line_style::dot,5));
	poly_rect.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_fill_color(Color::red);


	one.move(200,250);
	two.move(400,250);

	win.wait_for_button();
}