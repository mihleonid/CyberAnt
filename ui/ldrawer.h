#pragma once

class LDrawer{
	private:
		// Created for optimization
		static Rect drawTextT(int x, int y, const char* text, int len);
		static Rect drawTextRightT(int x, int y, const char* text, int len);
		static Rect drawTextCenterT(int x, int y, const char* text, int len);
	public:
		//SDL
		static std::pair<int, int> draw(int x, int y, SDL_Texture* tex);
		static std::pair<int, int> drawRight(int x, int y, SDL_Texture* tex);
		static std::pair<int, int> drawCenter(int x, int y, SDL_Texture* tex);

		static std::pair<int, int> drawText(int x, int y, int text);
		static std::pair<int, int> drawText(int x, int y, const char* text);

		static std::pair<int, int> drawTextRight(int x, int y, int text);
		static std::pair<int, int> drawTextRight(int x, int y, const char* text);

		static std::pair<int, int> drawTextCenter(int x, int y, const char* text);
		static std::pair<int, int> drawTextCenter(int x, int y, int text);

		static SDL_Texture* makeText(SDL_Renderer* ren, const char* c);

		//Terminal

		static Rect drawTextT(int x, int y, int text);
		static Rect drawTextT(int x, int y, const char* text);

		static Rect drawTextRightT(int x, int y, int text);
		static Rect drawTextRightT(int x, int y, const char* text);

		static Rect drawTextCenterT(int x, int y, int text);
		static Rect drawTextCenterT(int x, int y, const char* text);
};

