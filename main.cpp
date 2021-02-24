#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "board.h"
using namespace std;

int main(){
	
	int counter = 0;     //counter initiation for a tie
	int board_size;     
	bool x_turn = true;

	cout << "2 PLAYER TIC-TAC-TOE" << endl;
	cout << "Enter a whole number for size of the board: ";
	cin >> board_size;
	tictactoe::board b(board_size);
        //This while loop will continue until all the tiles of the board are filled 
	while(counter != board_size*board_size){
		cout << string(10, '\n');
		cout << b;
		if(x_turn){
			bool inserted = false;
			while(!inserted){
				int pos;
				cout << "Player X, enter the position number: ";
				cin >> pos;
				inserted = b.x_insert(pos);
				x_turn = false;
				counter = counter + 1;
			}	
		}else{
			bool inserted = false;
			while(!inserted){
				int pos;
				cout << "Player O, enter the position number: ";
				cin >> pos;
				inserted = b.o_insert(pos);
				x_turn = true;
				counter = counter + 1;
			}
		}	
		if(b.x_win()){
 			cout << b;
			cout << "Player X has won!" << endl;
			break;
		}else if(b.o_win()){
			cout << b; 
			cout << "Player O has won!" << endl;
			break;
		}
	}
	if (counter == board_size*board_size){
		cout << b; 
		cout << "It is a tie!" << endl;
	}
	return EXIT_SUCCESS;
}
