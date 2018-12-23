#include <SDL2/SDL.h>
#include <iostream>
#include "window_management.h"
#include "surface_management.h"

void increment_sequentially(int& x, int& y, int increment_by);

void repeat_n_times( 
                       int n, 
                       surface_management &image,
                       surface_management &window_surface,
                       SDL_Rect *image_rect,
                       window_management &window,
                       int &value_to_increase,
                       int movement_speed,
                       int delay_time
                   ); 

int main( int argc, char * args[] ) 
{   
    const std::string window_title = "Box";
    
    const int width = 500;
    
    const int height = 500; 
    
    const int spawn_pos_x = 500;
    
    const int spawn_pos_y = 100;
    
    const int delay_time_in_mili = 1;
    
    const int size_w = 50;
    const int size_h = 50;
    
    int movement_speed = 5;
    
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
    
    image.optimize_surface( window_surface.get_surface_instance() );
    
    SDL_Rect image_rect = {width/2, height/2, size_w, size_h};
    
    SDL_FillRect
    ( 
        window_surface.get_surface_instance(), 
        NULL, 
        SDL_MapRGB
        ( 
            window_surface.get_surface_instance()->format, 
            0x0,      
            0x0,     
            0x0 
        )    
    );                            
    
    bool closed = false;
    
    while (!closed)
    {
        SDL_Event event;
        
        while( SDL_PollEvent( &event ) != 0 ) 
        //while an event happened
        {
            //if the player X's out,
            //closed becomes true
            if( event.type == SDL_QUIT )
            {
                closed = true;
            }
        }
        
        
        static int counter = 4;
        const int choices_amount = 4;
        static int amount_of_moves = 1;
        
        switch (counter % choices_amount)
        {
            case 0:
                image_rect.y += -movement_speed;
                repeat_n_times
                (
                    ++amount_of_moves,
                    image, 
                    window_surface, 
                    &image_rect, 
                    window,
                    image_rect.y,
                    -movement_speed,
                    delay_time_in_mili
                );

                break;
            case 1:
                image_rect.x += movement_speed;
                repeat_n_times
                (
                    ++amount_of_moves,
                    image, 
                    window_surface, 
                    &image_rect, 
                    window,
                    image_rect.x,
                    movement_speed,
                    delay_time_in_mili
                );

                break;
            case 2:
                image_rect.y += movement_speed;
                repeat_n_times
                (
                    ++amount_of_moves,
                    image, 
                    window_surface, 
                    &image_rect, 
                    window,
                    image_rect.y,
                    movement_speed,
                    delay_time_in_mili
                );

                break;
            case 3:
                image_rect.x += -movement_speed;
                amount_of_moves++;
                repeat_n_times
                (
                    ++amount_of_moves,
                    image, 
                    window_surface, 
                    &image_rect, 
                    window,
                    image_rect.x,
                    -movement_speed,
                    delay_time_in_mili
                );
                image_rect.w--;
                image_rect.h--;
                break;
        }
        
        counter++;

    }
       
}

void repeat_n_times( 
                       int n, 
                       surface_management &image,
                       surface_management &window_surface,
                       SDL_Rect *image_rect,
                       window_management &window,
                       int &value_to_increase,
                       int movement_speed,
                       int delay_time
                   ) 
{
    while(n > 0) 
    {
        value_to_increase += movement_speed;
        
        SDL_BlitScaled
        (    
            image.get_surface_instance(), 
            NULL, 
            window_surface.get_surface_instance(),
            image_rect
        );
                
        SDL_UpdateWindowSurface
        ( 
             window.get_window_instance() 
        );
        std::cout << n << '\n';
        SDL_Delay( delay_time );
        n--;
    }
}
