#pragma once

#define SCREEN_W 1024
#define SCREEN_H 764

class LWindow{
	private:
		bool sdlMode;
		SDL_Window* win=nullptr;
		SDL_Renderer* ren=nullptr;
		int tw;
		int th;
		const char* wtitle;
	public:
		LWindow(const char* title, bool forceTerminal=false);
		void add();
		void update();
		~LWindow();

};

