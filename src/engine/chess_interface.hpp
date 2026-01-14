#pragma once
#include <vector>
#include <string>

#include "stockfish_module.hpp"

using namespace std;

class ChessInterface {
    
    vector<string> total_moves;
    Stockfish chess_engine;

public:
   
    string play_move(string cur_move);
    vector<string> list_legal_moves();
    string get_eval_score();

    void add_captured_piece(string name, string color);
    vector<string> read_captured_pieces(string color);

    template <typename Game>
    void save_game(Game& board);

    template <typename Game>
    void load_game(Game& board);
};
