build:
	cc -Wall -std=c99 src/*.c `pkg-config sdl3 --cflags --libs` -o color_buffer 

run:
	./color_buffer
