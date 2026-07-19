#include<stdio.h> 
#include<stdlib.h> 
#include<SDL2/SDL.h> 

unsigned char* read_PPM_image ( const char *Filename , int *width , int *height) ;

int main () 
{ 
    int width, height ; 
    unsigned char *pixel_data = read_PPM_image("image.ppm",&width ,&height) ;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *ppm_image = SDL_CreateWindow("PPM_IMAGE_VIEWER", 0 , 0 , width ,height, 0) ; 

    SDL_Surface *ppm_image_surface = SDL_GetWindowSurface(ppm_image) ;

    // loop to keep the window running
    SDL_Event event;
    int isRunning = 1;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = 0 ;
            }
        }

        for ( int i = 0 ; i < width ; i++)
        { 
            for ( int j = 0 ; j < height ; j++)
            { 
                // finding index
                int index = (j*width + i  ) *3 ;

                Uint8 r = pixel_data[index];
                Uint8 g = pixel_data[index+1];
                Uint8 b = pixel_data[index+2];

                Uint32 colour = SDL_MapRGB(ppm_image_surface->format, r, g, b);

                SDL_Rect pixel = (SDL_Rect){ i , j , 1 , 1 } ; 
                SDL_FillRect(ppm_image_surface , &pixel , colour) ;
                
            }
        }

        SDL_UpdateWindowSurface(ppm_image) ;

    }

    free(pixel_data); 
    return 0 ; 
}

unsigned char* read_PPM_image ( const char *Filename , int *width , int *height)
{ 
    // using rb since the ppm file we have is P6 aka binary file 
    FILE *file = fopen(Filename, "rb" ) ; 

    // checking if the file is uploaded or not using NULL since fopen gets NULL if nothing is given 
    if ( file == NULL)
    { 
        printf("didnt upload the file? or wrong file name check again");
        return NULL;
    }

    // checking if the uploading file is PPM P6 binary file and using [3] so we can also eat up the newline character 
    char file_check[3] ; 

    fscanf(file,"%2s", file_check) ; 

    if (file_check[0] != 'P' || file_check[1] != '6') 
    { 
        printf("wrong file format") ;
        return NULL ;
    }

    fscanf(file,"%d %d" , width , height) ;
    fgetc(file);// to remove the max_colour num 255 
    fgetc(file); // to remove the newline character 
    printf("okay got the width and height\n") ;
    printf("Width: %d\n", *width);
    printf("Height: %d\n", *height);

    int total_bytes = (*width) * (*height) * 3 ;
    unsigned char *pixel_data = malloc(total_bytes);
    // fread explanation : pass destination , size of item , total no of items , and finally the source 
    fread(pixel_data, 1, total_bytes, file);
    fclose(file);
    return pixel_data ; 
}
