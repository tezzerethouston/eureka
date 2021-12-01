all:
	gcc src/main.c -lncurses

hellosdl:
	#echo gcc hellosdl.c -L../SDL2-2.0.18/x86_64-w64-mingw32/lib `./../SDL2-2.0.18/x86_64-w64-mingw32/bin/sdl2-config --libs` -I../SDL2-2.0.18/x86_64-w64-mingw32/include/SDL2
	gcc hellosdl.c -L../SDL2-2.0.18/x86_64-w64-mingw32/lib -lcygwin -lSDL2main -lSDL2 -mwindows -I../SDL2-2.0.18/x86_64-w64-mingw32/include/SDL2

helloncurses:
	gcc helloncurses.c -lncurses
