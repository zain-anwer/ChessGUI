#include "SDL2/SDL.h"
#include "board.hpp"
#include "../engine/chess_interface.hpp"
#include <iostream>

#define NORMAL 0
#define SELECT 1
#define DANGER 2
#define CHECK  3

#define INVALID_CHOICE 0 
#define VALID_CHOICE 1
#define CHECKMATE 2
#define STALEMATE 3

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
        bool validate(Board& B);
		string move(Board& B);
        bool check(Board &B);
		void flipBoard(Board& B);
};