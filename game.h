/*********************************************************************
 * ** Program Filename: game.h
 * ** Author: Megan Lynn Tucker
 * ** Date: 02/02/2020
 * **********************************************************************/
#ifndef GAME_H
#define GAME_H

#include<iostream>
#include "game.h"
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;

class Game{
	private:
		Deck cards;
		Card pile; //card representing the top of the pile; copy new card each time 
		int card_location; //where we are in the deck
		Player players[2]; //one player is computer
	public:
		Game(); //constructor; creates the deck
		Card getPile() const;
		int getCard_location() const;
		void setPile(Card); //define a new pile value using the location in the deck
		void setCard_location(int);
		Card drawCard(); //draw a card from the deck
		void printGame();
		bool checkHand(int, bool); //check to see if the player has any cards that can be played
		void playCard(int); //input is the player number
		void playComputer_card(int); //input is the player number
		bool turn(int); //returns true when the game is over and false if not
		~Game(); //destructor
};

#endif 
