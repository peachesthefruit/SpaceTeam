#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#undef main
#include <SDL/SDL_main.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>
#include "Window.h"
#include "Timer.h"
#include "Tensor.h"
#include <iostream>
#include <string>
#include "../Planet.h"

int main ( int argc, char** argv ){
    Tensor t(-1e24,-1e24);
    Tensor t2(1e24,1e24);
    Tensor t3(0,0);
    Tensor t4(1e22,1e22);
    Window w("Test",t,t2,800,300);
	Planet Earth("Planet 1", "images/red_square.jpg", 5.97e24,0,0,0, 0, 0, 0);
	Planet Moon("Planet 2", "images/black_square.jpg", 7.33e22,3.84e8, 0, 0, 0, 10e2, 0);
	//Planet Thing("Thing", 3.44e23, 5.97e4, 4.83e6, 0);
	//Object e("images/red_square.jpg", &Earth);
	//Object m("images/black_square.jpg", &Moon);
	//w.addObject(&e);
	//w.addObject(&m);
    //int red = w.createobj("images/red_square.jpg",t+t4);
	SDL_Delay(1000);
    for(int i = 1; i < 20; i++){
		w.display();
		SDL_Delay(100);
		Planet::update(10);
		//w.move(red,t+(t4*i));
    }
    //w.createobj("images/black_square.jpg",t3);
    w.display();
    SDL_Delay(2000);
    return 0;
}
