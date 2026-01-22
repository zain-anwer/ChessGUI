/*

Notes:
1. Virtual destructors are used so that the derived class destructor runs when an object is deleted through a base class pointer.
2. We use base class pointers to store derived instances hence destructor is virtual
3. Base class pointers can hold derived class instances if inheritance is public

*/

#ifndef PIECE_HPP 
#define PIECE_HPP

#include <SDL2/SDL.h>
#include "../engine/chess_interface.hpp"
#include <iostream>

extern string images[2][6];

class ChessPiece
{
	public:
        int colour;
        string name;
        SDL_Surface* image;
        SDL_Texture* texture;
        float value;
        bool endGame;

	public:

        ChessPiece(int colour,string name,string image_name, float value);
        void virtual initialization() = 0; 
        void operator=(ChessPiece& c);
        virtual ~ChessPiece();
};

class Pawn : public ChessPiece
{
	protected:
	    bool firstMovePlayed;
	public:
	Pawn(int type);	
	void initialization();
};

class Knight : public ChessPiece
{
	public:
	Knight(int type);
	void initialization();
};

class Bishop : public ChessPiece
{
	public:
	Bishop(int type);
	void initialization();
};

class Rook : public ChessPiece
{
	public:
	Rook(int type);
	void initialization();
};

class Queen : public ChessPiece
{
	public:
	Queen(int type);
	void initialization();
};

class King : public ChessPiece
{
	public:
	King(int type);
	void initialization();
};

#endif