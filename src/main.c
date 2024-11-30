#include "display.h"
#include <SDL3/SDL.h>

bool running = false;
uint32_t background_color = 0xff0f0908;
uint32_t foreground_color = 0xffd47d49;
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

void render_quads() {
	int num_quads_x = 3;
	int num_quads_y = 3;
	int quad_size = 50;
	int quad_offset = 50;
	int full_width = num_quads_x * (quad_size + quad_offset);
	int full_height = num_quads_y * (quad_size + quad_offset);
	int x_start = (window_width - full_width) * 0.5;
	int y_start = (window_height - full_height) * 0.5;
	for (int i = 0; i < num_quads_y; i++) {
		for (int j = 0; j < num_quads_x; j++) {
			int x = (j * quad_size) + (j * quad_offset) + x_start;
			int y = (i * quad_size) + (i * quad_offset) + y_start;
			draw_rectangle(
				x,
				y,
				quad_size,
				quad_size,
				foreground_color
			);
		}
	}
}

void render(void) {
	render_color_buffer();
	clear_color_buffer(background_color);
	render_quads();
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

