#ifndef SURFACE_MANAGEMENT
#define SURFACE_MANAGEMENT

#include <iostream>
#include <SDL2/SDL.h>

class surface_management 
{
//class exist so that the errors
//are automatically handled 
private:
    SDL_Surface * surface;

public:

    surface_management( SDL_Surface * window_surface );
    
    surface_management( std::string file_name );
    
    SDL_Surface * get_surface_instance();
    
    ~surface_management();
};

#endif
