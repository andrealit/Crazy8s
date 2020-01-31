/*********************************************************************
 * ** Program Filename: hand.h
 * ** Author: Megan Lynn Tucker
 * ** Date: 02/02/2020
 * **********************************************************************/
#ifndef HAND_H
#define HAND_H

#include<iostream>
#include "card.h"

using namespace std;

class Hand{
	private: 
		Card *cards; //dynamic array of cards
		int n_cards; //number of cards in the hand
	public:
		Hand(); //constructor; creates the array of cards
		Hand(const Hand&); //copy constructor
		Hand& operator= (const Hand); //assignment operator overload
		int getN_cards() const;
		Card* getCards() const;
		void setN_cards(int);
		void printHand() const;
		void playCard(int); //uses card location in hand
		void drawCard(int, int); //uses rank and suit from deck`
		~Hand(); //destructor
};

#endif 
