#ifndef BOARD_HPP
#define BOARD_HPP


#define NORMAL 0
#define SELECT 1
#define DANGER 2
#define CHECK  3

#define BLACK 0
#define WHITE 1

#include <SDL2/SDL.h>
#include "tile.hpp"

class Board {

	public:

        Tile tiles[8][8];
        int x_pos;
        int y_pos;
	
    public:
		
    	Board(ChessInterface* interface);
	    void drawBoard(SDL_Renderer* renderer);
};

#endif 