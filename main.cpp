#include <SDL2/SDL.h>
#include <iostream>
#include "window_management.h"
#include "surface_management.h"

int main( int argc, char * args[] ) 
{   
    const std::string window_title = "Circle";
    
    const int width = 500;
    
    const int height = 500; 
    
    const int spawn_pos_x = 500;
    
    const int spawn_pos_y = 100;
    
    const int delay_time_in_mili = 3000;
    
    window_management window
    ( 
        window_title, 
        width, height, 
        spawn_pos_x, 
        spawn_pos_y 
    );
    
    window.init_window();
    
    surface_management window_surface( window.get_window_surface() );
    
    surface_management image( "images/circle.bmp" );
    
    SDL_FillRect
    ( 
        window_surface.get_surface_instance(), 
        NULL, 
        SDL_MapRGB
        ( 
            window_surface.get_surface_instance()->format, 
            0x0,      
            0xAE,     
            0xBF 
        )    
    );
    
    SDL_BlitSurface
    ( 
        image.get_surface_instance(), 
        NULL, 
        window_surface.get_surface_instance(),
        NULL
    );                          
    
    SDL_UpdateWindowSurface( window.get_window_instance() );   
    
    SDL_Delay( delay_time_in_mili );   
}
