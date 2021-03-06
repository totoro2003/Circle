#include "surface_management.h"

surface_management::surface_management( SDL_Surface * window_surface ) 
{
    this->surface = window_surface;
    
    if (surface == NULL) 
    {
        std::cout << "SDL couldn't load the surface. error: "
        << SDL_GetError(); 
    }
}

surface_management::surface_management( std::string file_name ) 
{
    this->surface = SDL_LoadBMP( file_name.c_str() );
    
    if (surface == NULL) 
    {
        std::cout << "SDL couldn't load the image. error: "
        << SDL_GetError(); 
    }
}

void surface_management::optimize_surface ( SDL_Surface * screen_surface )
{
    SDL_Surface * optimized_surface = SDL_ConvertSurface 
    (
        surface,
        screen_surface->format,
        0
    );
    
    if ( optimized_surface == NULL )
    {
        std::cout << "SDL was unable to optimize the surface. error: "
        << SDL_GetError();
    }
    else 
    {
        surface = optimized_surface;
    }
    //SDL_FreeSurface( optimized_surface );
}

SDL_Surface * surface_management::get_surface_instance() 
{
    return surface;
}

surface_management::~surface_management() 
{
    SDL_FreeSurface(surface);
}
