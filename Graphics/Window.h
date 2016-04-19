#ifndef WINDOW_H
#define WINDOW_H

#include "Object.h"
#include "Tensor.h"
#include "Planet.h"
#include <string>
#include <vector>

class Window
{
	public:
		Window(std::string windowname, Tensor topleft, Tensor botright,int i_height=640, int i_width=480, int i_bpp=32);
		~Window();
		int createobj(std::string imagename, Tensor t);
		int createobj(std::string message, int fontsize,
									std::string fontname, int x, int y);
		bool removeobj(int obj_num);
		bool returnobj(int obj_num);
		bool colorobj(int,Uint8,Uint8,Uint8);
		bool move(int obj_number, Tensor t);
		int getheight();
		int getwidth();
		bool update();
		bool reset();
	private:
		SDL_Surface* screen;
		int height;
		int width;
		int bpp;
		std::vector<Object> obj;
		Tensor topleft;
		Tensor botright;
		int getx(Tensor,int);
		int gety(Tensor,int);
		bool quit;
};

#endif // WINDOW_H