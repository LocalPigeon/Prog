/*
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp main.cpp `fltk-config --ldflags --use-images`
*/ 

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

using namespace Graph_lib;

int main(){
	Point tl{100,100};
	Simple_window win{tl, 800, 1000, "Window"};

	int x_s=800;
	int y_s=800;
	int x_g=100;
	int y_g=100;

	Lines grid;
	for (int x=x_g; x<x_s; x+=x_g)
	      grid.add(Point{x,0},Point{x,y_s});	//függőleges
	for (int y = y_g; y<y_s; y+=y_g)
          grid.add(Point{0,y},Point{x_s,y});	//vízszintes

 	grid.set_color(Color::red);
 	win.attach(grid);
 	win.wait_for_button();

 	Vector_ref<Rectangle> rects;
 	for (int i = 0; i < x_s; i += x_g) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_g,i+x_g}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

    win.wait_for_button();

    Image img1 {Point{0,300}, "one.jpg"};
    Image img2 {Point{300,600}, "one.jpg"};
    Image img3 {Point{500,100}, "one.jpg"};

    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.wait_for_button();

    Image secondImg {Point{0,0}, "two.jpg"};
    win.attach(secondImg);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            secondImg.move(100, 0);
            win.wait_for_button();
        }
        secondImg.move(-700, 100);
        win.wait_for_button();
    }

}
