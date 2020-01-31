/*********************************************************************
 * ** Program Filename: card.h
 * ** Author: Megan Lynn Tucker
 * ** Date: 02/02/2020
 * **********************************************************************/
#ifndef CARD_H
#define CARD_H

#include<iostream>

class Card{
	private:
		int rank; //range 1-13
		int suit; //range 1-4
	public: 
		Card();
		int getRank() const;
		int getSuit() const;
		void setRank(int);
		void setSuit(int);
		void printCard() const;
		~Card();
};

#endif 
