/*********************************************************************
 * ** Program Filename: deck.h
 * ** Author: Megan Lynn Tucker
 * ** Date: 02/02/2020
 * **********************************************************************/
#ifndef DECK_H
#define DECK_H

#include<iostream>
#include "card.h"

using namespace std;

class Deck{
	private: 
		Card cards[52]; //deck itself never changes size, we just draw from it until n_cards == 52
		int n_cards; //number of cards remaining in the deck
	public:
		Deck(); //constructor; creates the array of cards
		int getN_cards() const;
		Card getCard(int);
		void setN_cards(int);
		void shuffleDeck();
		void printDeck() const;
		~Deck(); //destructor
};

#endif 
