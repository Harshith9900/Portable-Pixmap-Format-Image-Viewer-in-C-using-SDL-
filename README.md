# PPM Image Viewer

PPM stands for Portable Pixmap Format and comes in two formats P6 and P3 .
P6 stands for raw binary which we want since each colour would be 8 bits and total of 24 bits which perfectly matches with SDL graphics framework which I used .

This is a very lightweight, custom built image viewer written entirely in raw C.
This program parses raw binary data from a P6 `.ppm` image file and renders the pixels to the screen using the SDL2 graphics framework as I have mentioned . 

## Features
* **Custom Binary Parser:** Reads header data and extracts raw RGB pixel bytes directly from memory without relying on heavy external libraries.
* **Hardware Rendering:** Maps the 1D binary pixel array into a 2D coordinate system and renders it using SDL2 hardware acceleration.

## Prerequisites
To run this project, you need the **SDL2** development library installed on your system . **SDL2** for showing image and might also need **Pillow** for converting png or jpeg images into ppm . 

**For macOS (using Homebrew):** ( for both sdl2 and pillow )
```bash
brew install sdl2 
python3 -m venv .venv
source .venv/bin/activate
pip3 install Pillow
```
I have already written a conversion.py you can use it then you can later type 
``` bash
deactivate
rm -rf .venv
```
in your terminal after converting your png/jpeg image into ppm . 

## How to Build and Run

This project also includes `Makefile` to handle the compilation process without needing to attach headerfiles of sdl2 .

( note: this Makefile only works for macOS due to use of pkgconfig sorry about that ) 

1. Clone this repository to your local machine.
2. Open your terminal in the project directory.
3. To compile the code, simply run 
```bash
make
./PPM_Image_File_Viewer
```

