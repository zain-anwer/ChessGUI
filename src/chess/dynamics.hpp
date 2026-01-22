#ifndef DYNAMICS_HPP 
#define DYNAMICS_HPP

#include "SDL2/SDL.h"
#include "board.hpp"
#include "../engine/chess_interface.hpp"
#include <iostream>

#define NORMAL 0
#define SELECT 1
#define DANGER 2
#define CHECK  3

#define SOURCE_SELECTION -1
#define INVALID_CHOICE 0 
#define VALID_MOVE 1
#define VALID_CAPTURE 2
#define CHECKMATE 3
#define STALEMATE 4

class Dynamics
{
	public:

		int src_i;
		int src_j;
		int dest_i;
		int dest_j;

        // used to decide whether to append special characters in communication string
        bool pawn_promotion; 

		ChessInterface* interface;

	public:
		
		Dynamics(ChessInterface* interface);
		int select(SDL_Point* p, Board& B);
        string convert();
        bool validate();
		string move(Board& B);
        bool check(Board &B);
		void flipBoard(Board& B);
};

#endif