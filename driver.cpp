/********************************************************************
 * ** Program Filename: driver.cpp
 * ** Author: Megan Lynn Tuker
 * ** Date: 02/02/2020
 * ** Description: Plays the game; prompts the user if they want to play again
 * ** Input: Integer between 1 and 2
 * ** Output: Who won the game; if they want to play again
 * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include "game.h"

int main(){
	int again;
	string s;
	
	do{ //loop until the player does not wish to play again
		again = 2;	
		Game crazy8s;
		
		bool game_over;
		do{ //dowhile loop that loops function turn until game is over
			game_over = true;
			crazy8s.printGame(); //print the player hand and the pile card
			game_over = crazy8s.turn(0); //player turn
			if(game_over == false){ //only run the computer turn if the player did not win
				game_over = crazy8s.turn(1); //computer turn
			}
		}while(game_over == false);

		cout << "Do you want to play again? [1] Yes [2] No: ";
		bool valid_input;
		do{ //verify that their input is valid; loops until the input is either a 1 or a 2
			valid_input = true;
			getline(cin, s);
			again = atoi(s.c_str());
			if(again < 1 || again > 2){
				cout << "Invalid input. ";
				valid_input = false;
			}
		}while(valid_input == false);

	}while(again == 1);

	return 0;
}
