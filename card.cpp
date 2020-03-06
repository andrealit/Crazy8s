/********************************************************************
 * ** Program Filename: card.cpp
 * ** Author: Megan Lynn Tucker
 * ** Date: 02/02/2020
 * ** Description: Contains information on the card class
 * ** Input: N/A
 * ** Output: Values for rank and suit of cards (in terms of integers)
 * *********************************************************************/
#include<iostream>
#include "card.h"

using namespace std;

/********************************************************************* 
 * ** Function: Card
 * ** Description: Constructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Card object was created
 * ** Post-Conditions: By default the rank and suit of each card is set to 0 so it is easy to check if they are bad
 * *********************************************************************/ 
Card::Card(){
	rank = 0;
	suit = 0;
}

/********************************************************************* 
 * ** Function: getRank
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Card object was created
 * ** Post-Conditions: Returns the rank of a card
 * *********************************************************************/ 
int Card::getRank() const{
	return rank;
}

/********************************************************************* 
 * ** Function: getSuit
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Card object was created
 * ** Post-Conditions: Returns the suit of a card
 * *********************************************************************/ 
int Card::getSuit() const{
	return suit;
}

/********************************************************************* 
 * ** Function: setRank
 * ** Description: Mutator (setter)
 * ** Parameters: Integer value for the rank (it is expected to be between 1 and 13 but is not checked here)
 * ** Pre-Conditions: Valid input was given (integer)
 * ** Post-Conditions: The value for rank is changed
 * *********************************************************************/ 
void Card::setRank(int rank_value){
	rank = rank_value;	
}

/********************************************************************* 
 * ** Function: setSuit
 * ** Description: Mutator (setter)
 * ** Parameters: Integer value for the suit (it is expected to be between 1 and 4 but is not checked here)
 * ** Pre-Conditions: Valid input was given (integer)
 * ** Post-Conditions: The value for suit is changed
 * *********************************************************************/ 
void Card::setSuit(int suit_value){
	suit = suit_value;
}

/********************************************************************* 
 * ** Function: printCard const
 * ** Description: Prints the value of a given card; does not change the value of the card
 * ** Parameters: N/A
 * ** Pre-Conditions: The card has a rank between 1-13 and a suit between 1-4
 * ** Post-Conditions: The rank and suit is printed in terms of their true string names
 * *********************************************************************/ 
void Card::printCard() const{
	if(rank == 1){
		cout << "ace of ";
	}
	else if(rank == 11){
		cout << "jack of ";
	}
	else if(rank == 12){
		cout << "queen of ";
	}
	else if(rank == 13){
		cout << "king of ";
	}
	else{
		cout << rank << " of ";
	}
	
	if(suit == 1){
		cout << "diamonds" << endl;
	}
	else if(suit == 2){
		cout << "hearts" << endl;
	}
	else if(suit == 3){
		cout << "spades" << endl;
	}
	else if(suit == 4){
		cout << "clubs" << endl;
	}
}

/********************************************************************* 
 * ** Function: ~Card
 * ** Description: Destructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Card object fell out of scope
 * ** Post-Conditions: Memory holding information about this card was freed
 * *********************************************************************/ 
Card::~Card(){
	//nothing to delete
}
