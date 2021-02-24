#include "board.h"
#include <stdlib.h>
namespace tictactoe{
	//Constructor for tic-tac-toe board
	board::board(int board_size){
		size = board_size;

		b = new std::string*[board_size];
		for(int i = 0; i < board_size; i++){
    			b[i] = new std::string[board_size];
    		}

		for(int i = 0; i < board_size; i++){
			for(int j = 0; j < board_size; j++){
				std::string k = std::to_string(((i * board_size) + j));
				b[i][j] = k;
			}
		}
	}
	
	bool board::is_num(const std::string& s){
	    std::string::const_iterator it = s.begin();
	    while (it != s.end() && std::isdigit(*it)) ++it;
	    return !s.empty() && it == s.end();
	}

	size_t board::get_size()const{
		return size;
	}
	
	//Function for getting item at a specific location on the board 
	std::string board::get_item(int row, int col) const{
		return b[row][col];
	}

	//Function definition for x win
	bool board::x_win(){
		//Vertical Win
                for(int i = 0; i < size; i++) 
                        for(int j = 0; j < size; j++){
                                if(b[j][i] != "X")
                                        break; 
                                if(j == (size-1))
                                        return true;
                        }
	
		//Horizontal Win
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(b[i][j] != "X")
					break;
				if(j == (size-1))
					return true;
			}
		}

		//Top Left to Bottom Right Diagonal Win
		for(int i = 0; i < size; i++){
			if(b[i][i] != "X")
				break;
			if(i == (size-1))
				return true;
		}
 
		//Top Right to Bottom Left Diagonal Win
		for(int i = 0; i < size; i++){
			if(b[(size-1)-i][i] != "X")
				break;
			if(i == (size-1))
				return true;
		}

		return false;
	}

	//Function definition for o win 
	bool board::o_win(){
		//Vertical Win
                 for(int i = 0; i < size; i++){
                         for(int j = 0; j < size; j++){
                                 if(b[j][i] != "O")
                                         break;
                                 if(j == (size-1))
                                         return true;
                         }
		}
		//Horizontal Win
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(b[i][j] != "O")
					break;
				if(j == (size-1))
					return true;
			}
		}

		//Top Left to Bottom Right Diagonal Win
		for(int i = 0; i < size; i++){
			if(b[i][i] != "O")
				break;
			if(i == (size-1))
				return true;
		}
 
		//Top Right to Bottom Left Diagonal Win
		for(int i = 0; i < size; i++){
			if(b[(size-1)-i][i] != "O")
				break;
			if(i == (size-1))
				return true;
		}

		return false;
	}

	//Insertion of X
	bool board::x_insert(int pos){
		int row = pos / size;
		int col = pos % size;
		if(is_num(b[row][col])){
			b[row][col] = "X";
			return true;
		} 
		return false;
	}

	//Insertion of O
	bool board::o_insert(int pos){
		int row = pos / size;
		int col = pos % size;
		if(is_num(b[row][col])){
			b[row][col] = "O";
			return true;
		} 
		return false;
	}

	//Function for outputting tic-tac-toe board on the command line in terminal  
	std::ostream& operator << (std::ostream& out, const board& b){
		for(int i = 0; i < b.get_size(); i++){
			out << std::endl;
			for(int j = 0; j < b.get_size(); j++){
				out << "----"; 
			}
			out << std::endl << "|";

			for(int j = 0; j < b.get_size(); j++){
				std::string item = b.get_item(i,j);
				int len = item.length();
				if(len <= 1)
					out <<std::setw(2)<< item << std::setw(2) << "|";
				else if(len == 2)
					out <<std::setw(1)<< item << std::setw(2) << "|";
				else if (len == 3)
					out <<std::setw(0)<< item << std::setw(1) << "|";
			}
		}

		out << std::endl;
		for(int j = 0; j < b.get_size(); ++j){
			out << "----";  
		}
		out << std::endl;
		return out;
	}
}
