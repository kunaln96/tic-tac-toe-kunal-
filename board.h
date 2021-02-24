#ifndef BOARD_H
#define BOARD_H
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
namespace tictactoe{
	class board{
	public: 
		board(int board_size = 3);
		std::string get_item(int row, int col) const;
		size_t get_size() const; 
		bool x_win();
		bool o_win();
		bool x_insert(int pos);
		bool o_insert(int pos);
		bool is_num(const std::string& s);
	private:
		std::string **b;
		size_t size;
	};
	std::ostream& operator << (std::ostream& out, const board& b);
}
#endif
