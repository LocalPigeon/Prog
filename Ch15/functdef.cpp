/* 
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp functdef.cpp `fltk-config --ldflags --use-images`
*/


#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <iostream>

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
try {
    Simple_window win {Point{100, 100}, 600, 600, "Function graphs"};

    Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
    Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};

    x.set_color(Color::red);
    y.set_color(Color::red);

    win.attach(x);
    win.attach(y);

    constexpr int r_min = -10;
    constexpr int r_max = 11;

    constexpr int num_points = 400;

    constexpr int x_scale = 20;
    constexpr int y_scale = 20;

    const Point orig {300, 300};

    Function f {one, r_min, r_max, orig, num_points, x_scale, y_scale};
    Function g {slope, r_min, r_max, orig, num_points, x_scale, y_scale};
    Function h {[](double x) { return x * x; }, r_min, r_max, orig, num_points, x_scale, y_scale};
    Function i {cos, r_min, r_max, orig, num_points, x_scale, y_scale};
    i.set_color(Color::blue);
    Function j {[](double x) { return cos(x) + slope(x); }, r_min, r_max, orig, num_points, x_scale, y_scale};

    win.attach(f);
    win.attach(g);
    win.attach(h);
    win.attach(i);
    win.attach(j);

    win.wait_for_button();
}
catch (exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown error!\n";
    return 2;
}
