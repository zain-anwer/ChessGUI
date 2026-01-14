#include <string>
#include <vector>
#include <fstream>

#include "chess_interface.hpp"

string ChessInterface::play_move(string cur_move)
{
    total_moves.push_back(cur_move);
    return chess_engine.play_move(total_moves);
}

vector<string> ChessInterface::list_legal_moves()
{    return chess_engine.list_legal_moves();    }

string ChessInterface::get_eval_score()
{
    
    try { return chess_engine.get_eval_score(); }

    catch (const char error_code){
        switch(error_code){
            case 'C': throw "check";
        }
    }

    return "check";
}

void ChessInterface::add_captured_piece(string name, string color)
{
    ofstream f_out;

    if (color == "White") f_out.open("white_pieces.txt");
    else if (color == "Black") f_out.open("black_pieces.txt");
    else throw "Invalid Piece Color!";

    f_out << name << endl;
    f_out.close();
}

vector<string> ChessInterface::read_captured_pieces(string color){
    
    ifstream f_in; string piece;
    vector<string> captured_pieces;

    if (color == "Black") f_in.open("white_pieces.txt");
    else if (color == "White") f_in.open("black_pieces.txt");
    else throw "Invalid Piece Color!";

    while (!f_in.eof()){
        f_in >> piece; captured_pieces.push_back(piece);
    }

    f_in.close(); return captured_pieces;
}

template <typename Game>
void ChessInterface::save_game(Game& board){
    ofstream f_out("game_state.bin", ios::out | ios::binary);
    f_out.write((char*) &board, sizeof(board));
    f_out.close();
}

template <typename Game>
void ChessInterface::load_game(Game& board){
    ifstream f_in("game_state.bin", ios::in | ios::binary);
    f_in.read((char*) &board, sizeof(board));
    f_in.close();
}
