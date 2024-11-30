#include "display.h"
#include <SDL3/SDL.h>

bool running = false;
uint32_t background_color = 0xff181818;
uint32_t foreground_color = 0xffffdd33;
int rectangle_width = 50;
int rectangle_height = 50;

void check_events(void) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_EVENT_QUIT:
				running = false;
				break;
		}
	}
}

void render(void) {
	render_color_buffer();
	clear_color_buffer(background_color);
	draw_rectangle(
		(window_width - rectangle_width) * 0.5,
		(window_height - rectangle_height) * 0.5,
		rectangle_width, 
		rectangle_height,
		foreground_color
	);
	SDL_RenderPresent(renderer);
}


int main(void) {
	running = init_display();
	while (running) {
		check_events();
		render();
	}
	destroy_display();
	return 0;
}

