#ifndef SURFACE_MANAGEMENT
#define SURFACE_MANAGEMENT

#include <iostream>
#include <SDL2/SDL.h>

class surface_management 
{
//errors are automatically handled
//and the destructor takes care of
//freeing the memory
private:
    SDL_Surface * surface;

public:

    surface_management( SDL_Surface * window_surface );
    
    surface_management( std::string file_name );
    
    //deleted copy constructor and 
    //assignment operator
    
    surface_management( const surface_management& new_class ) = delete;
    
    surface_management & operator=( const surface_management& new_class ) = delete;
    
    void optimize_surface ( SDL_Surface * screen_surface );
    
    SDL_Surface * get_surface_instance();
    
    ~surface_management();
};

#endif
