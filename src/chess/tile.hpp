#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL.h>
#include "piece.hpp"

class Tile
{
	public:
		SDL_Rect square;
		ChessPiece* piece;
		int colour;
	public:
		Tile();
        ~Tile();
};

#endif