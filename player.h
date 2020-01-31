/*********************************************************************
 * ** Program Filename: player.h
 * ** Author: Megan Lynn Tucker
 * ** Date: 02/02/2020
 * **********************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include "player.h"
#include "hand.h"

using namespace std;

class Player{
	private: 
		Hand hand; //hand for particular player
		string name; //player name
	public:
		Player(); //constructor 
		//have a version that takes in a name and constructs the user player; else create computer player
		Hand getHand() const;
		string getName() const;
		int getN_cards();
		void setName(string);
		int selectCard(); //in game, first check that the card is valid, then check that this card matches pile
		void playCard(int); //input card location into this function
		void drawCard(int, int);
		void printHand() const;	
		int choose8suit(); //randomly chose a number 1-4 for the suit
		~Player(); //destructor
};

#endif 
