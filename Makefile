PPM_Image_File_Viewer: PPM_Image_File_Viewer.c
	gcc-15 $(shell pkg-config --cflags sdl2) -Wall PPM_Image_File_Viewer.c -o PPM_Image_File_Viewer $(shell pkg-config --libs sdl2)