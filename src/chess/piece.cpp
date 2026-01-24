#include "piece.hpp"

string images[2][6] = {
	{"ChessPieceImages/King-B.bmp",
     "ChessPieceImages/Queen-B.bmp",
     "ChessPieceImages/Rook-B.bmp",
     "ChessPieceImages/Bishop-B.bmp",
     "ChessPieceImages/Knight-B.bmp",
     "ChessPieceImages/Pawn-B.bmp"},
	{"ChessPieceImages/King-W.bmp",
     "ChessPieceImages/Queen-W.bmp",
     "ChessPieceImages/Rook-W.bmp",
     "ChessPieceImages/Bishop-W.bmp",
     "ChessPieceImages/Knight-W.bmp",
     "ChessPieceImages/Pawn-W.bmp"}
};

ChessPiece::ChessPiece(int colour,string name,string image_name, float value)
{
	this->colour = colour;
	this->name = name;
	this->image =nullptr;
	this->image = SDL_LoadBMP(image_name.c_str());
	this->value = value;
	this->texture = nullptr;
	this->endGame = true;
}

void ChessPiece::operator=(ChessPiece& c)
{
	colour = c.colour;
	name = c.name;
	if (image != nullptr)
	{
		SDL_FreeSurface(image);
		image = nullptr;
	}
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
	} 
	if (c.image != nullptr)
		image = c.image;
	value = c.value;
}

ChessPiece::~ChessPiece()
{
	if (image != nullptr){ SDL_FreeSurface(image); image = nullptr; } 

	if (texture != nullptr){ SDL_DestroyTexture(texture); texture = nullptr; }
}

Pawn::Pawn(int type):ChessPiece(type,"Pawn",images[type][5],1){}
	
void Pawn::initialization()
{	cout << colour << " pawn initialized" << endl;  }

Knight::Knight(int type):ChessPiece(type,"Knight",images[type][4],3){}

void Knight::initialization()
{   cout << colour << " knight initialized" << endl;    }

Bishop::Bishop(int type):ChessPiece(type,"Bishop",images[type][3],3.5){}
void Bishop::initialization()
{   cout << colour << " bishop initialized" << endl;    }

Rook::Rook(int type):ChessPiece(type,"Rook",images[type][2],5){}
void Rook::initialization()
{   cout << colour << " rook initialized" << endl;  }


Queen::Queen(int type):ChessPiece(type,"Queen",images[type][1],9){}
void Queen::initialization()
{   cout << colour << "  queen initialized" << endl;    }

King::King(int type):ChessPiece(type,"King",images[type][0],100){}
void King::initialization()
{   cout << colour << " king initialized" << endl;  }
