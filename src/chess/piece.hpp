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

string images[2][6] = {"../../ChessPieceImages/King-W.bmp","../../ChessPieceImages/Queen-W.bmp",
	"../../ChessPieceImages/Rook-W.bmp","../../ChessPieceImages/Bishop-W.bmp",
	"../../ChessPieceImages/Knight-W.bmp","../../ChessPieceImages/Pawn-W.bmp",
	"../../ChessPieceImages/King-B.bmp","../../ChessPieceImages/Queen-B.bmp",
	"../../ChessPieceImages/Rook-B.bmp","../../ChessPieceImages/Bishop-B.bmp",
	"../../ChessPieceImages/Knight-B.bmp","../../ChessPieceImages/Pawn-B.bmp"};
string c[2] = {"White","Black"};

class ChessPiece
{
	public:
        string colour;
        string name;
        SDL_Surface* image;
        SDL_Texture* texture;
        float value;
        bool endGame;
        static ChessInterface* interface;

	public:

        ChessPiece(string colour,string name,string image_name, float value);
        void virtual initialization() = 0; 
        void operator=(ChessPiece& c);
        virtual ~ChessPiece();
};

class Pawn : public ChessPiece
{
	protected:
	    bool firstMovePlayed;
	public:
	Pawn(int type):ChessPiece(c[type],"Pawn",images[type][5],1){}
	void initialization()
	{
		cout << colour << " pawn initialized" << endl;
	}
};

class Knight : public ChessPiece
{
	public:
	Knight(int type):ChessPiece(c[type],"Knight",images[type][4],3){}
	void initialization()
	{
		cout << colour << " knight initialized" << endl;
	}
};

class Bishop : public ChessPiece
{
	public:
	Bishop(int type):ChessPiece(c[type],"Bishop",images[type][3],3.5){}
	void initialization()
	{
		cout << colour << " bishop initialized" << endl;
	}
};

class Rook : public ChessPiece
{
	public:
	Rook(int type):ChessPiece(c[type],"Rook",images[type][2],5){}
	void initialization()
	{
		cout << colour << " rook initialized" << endl;
	}
};

class Queen : public ChessPiece
{
	public:
	Queen(int type):ChessPiece(c[type],"Queen",images[type][1],9){}
	void initialization()
	{
		cout << colour << "  queen initialized" << endl;
	}
};

class King : public ChessPiece
{
	public:
	King(int type):ChessPiece(c[type],"King",images[type][0],100){}
	void initialization()
	{
		cout << colour << " king initialized" << endl;
	}
};

#endif