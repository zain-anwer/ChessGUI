#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/process.hpp>
#include <boost/process/detail/child_decl.hpp>
#include <boost/process/pipe.hpp>
#include <string>
#include <vector>
#include <iostream>

#include "stockfish_module.hpp"

using namespace std;
namespace bp = boost::process;


Stockfish::Stockfish()
{
    program = new bp::child("stockfish", bp::std_in < stock_in, bp::std_out > stock_out);
    stock_in << "uci\nisready\nposition startpos\n";
}

string Stockfish::play_move(vector<string> move_vector)
{
    string line, move_string;

    for (auto str : move_vector) 
        line += str + " ";
    
    stock_in << "position startpos moves " + line << endl;
    stock_in << "go movetime 300" << endl;

    while (getline(stock_out, line))
    {
        if (!line.compare(0, 8, "bestmove")){
            move_string = line; break;
        }
    }

    move_string = move_string.substr(9, move_string.size()-9);

    // splits move_string on the basis of spaces to prevent errors
    
    boost::split(move_vector, move_string, boost::is_any_of(" "));

    return move_vector.at(0);
}

vector<string> Stockfish::list_legal_moves(){
    
    int line_count = 0; string line; vector<string> legal_moves;
    
    // input to the stockfish game engine

    stock_in << "go perft 1" << endl;

    while (getline(stock_out, line)){
        
        // ignore the first two lines

        if (line_count++ < 2) 
            continue;
        
        // ignoring the last line that starts with "Nodes ..."
        // string::compare() returns zero on equality

        else if (!line.compare(0, 5, "Nodes")) break;

        // only concerned with the first four letters of each line (moves)

        line = line.substr(0, 4);
        legal_moves.push_back(line);
    }

    return legal_moves;
}

string Stockfish::get_eval_score(){
    
    string line, eval_string;
    vector<string> eval_vector;

    stock_in << "eval" << endl;
    
    while (getline(stock_out, line)){
        if (!line.compare(0, 5, "Final")){
            eval_string = line; break;
        }
    }
    
    boost::split(eval_vector, eval_string, boost::is_any_of(" "));

    for (auto i=0; i<eval_vector.size(); i++)
        if (eval_vector.at(i) == "")
            eval_vector.erase(eval_vector.begin() + i--);

    eval_string = eval_vector.at(2);

    if (eval_string == "none") throw 'C';
    else return eval_string;
}
