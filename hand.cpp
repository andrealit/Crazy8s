/********************************************************************
 * ** Program Filename: hand.cpp
 * ** Author: Megan Lynn Tuker
 * ** Date: 02/02/2020
 * ** Description: Contains information on the hand class
 * ** Input: N/A
 * ** Output: Dynamic array of cards in the hand, number of cards in the hand
 * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include<cstddef>
#include "hand.h"
#include "card.h"

/********************************************************************* 
 * ** Function: Hand
 * ** Description: Constructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Hand object was created
 * ** Post-Conditions: The pointer to the array of cards is set to null and the number of cards in hand set to 0
 * *********************************************************************/ 
Hand::Hand(){
	cards = NULL;
	n_cards = 0;
}

/********************************************************************* 
 * ** Function: Hand
 * ** Description: Copy Constructor
 * ** Parameters: N/A
 * ** Pre-Conditions: Hand a = something; Hand b; b = a
 * ** Post-Conditions: a is copied over into b
 * *********************************************************************/ 
Hand::Hand(const Hand& old_hand){
	n_cards = old_hand.n_cards;
	cards = new Card[n_cards];
	for(int i = 0; i < n_cards; i++){
		cards[i] = old_hand.cards[i];
	}
}

/********************************************************************* 
 * ** Function: Hand
 * ** Description: Assignment Operator Overload
 * ** Parameters: N/A
 * ** Pre-Conditions: Hand a = something; Hand b = a
 * ** Post-Conditions: a is copied over into b when b is being created
 * *********************************************************************/ 
Hand& Hand::operator=(const Hand old_hand){
	n_cards = old_hand.n_cards;
	cards = new Card[n_cards];
	for(int i = 0; i < n_cards; i++){
		cards[i] = old_hand.cards[i];
	}
	return *this;
}

/********************************************************************* 
 * ** Function: getN_cards
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Hand object was created
 * ** Post-Conditions: Returns the number of cards in the hand
 * *********************************************************************/ 
int Hand::getN_cards() const{
	return n_cards;
}

/********************************************************************* 
 * ** Function: getCards
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Hand object was created
 * ** Post-Conditions: Returns a pointer to the array of cards in the hand
 * *********************************************************************/ 
Card* Hand::getCards() const{
	return this->cards;
}

/********************************************************************* 
 * ** Function: setN_cards
 * ** Description: Mutator (setter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Hand object was created
 * ** Post-Conditions: Resets the number of cards in the hand
 * *********************************************************************/ 
void Hand::setN_cards(int num_cards){
	n_cards = num_cards;
}

/********************************************************************* 
 * ** Function: printHand
 * ** Description: Prints the value of each card in the hand
 * ** Parameters: N/A
 * ** Pre-Conditions: N/A
 * ** Post-Conditions: The hand is printed in the order it sits in the array along with its posiiton
 * *********************************************************************/ 
void Hand::printHand() const{
	for(int i = 0; i < n_cards; i++){
		cout << "[" << i + 1 << "]"; //posiitons are +1 so we can use atoi to verify input values
		cards[i].printCard();
	}
}

/********************************************************************* 
 * ** Function: playCard
 * ** Description: Creates an array 1 smaller with all the old cards except the card played
 * ** Parameters: Card location in the hand
 * ** Pre-Conditions: The card to be played is a valid choice
 * ** Post-Conditions: The size of the array of cards is decreased by 1 and the card that is played is removed
 * *********************************************************************/ 
void Hand::playCard(int card_location){
	--n_cards; //change the total value of cards
	Card *temp = new Card[n_cards];
	for(int i = 0; i < n_cards; i++){
		if(i >= card_location){
			temp[i] = cards[i + 1]; //skip the card to be played
		}
		else{
			temp[i] = cards[i]; //copy the values of cards into temp
		}
	}
	delete [] cards; //delete the old array
	cards = temp; //make the pointer for cards point to temp; no need to derefference 
	temp = NULL;
}

/********************************************************************* 
 * ** Function: drawCard
 * ** Description: Creates an array 1 larger with all the old cards and the drawn card added to the end
 * ** Parameters: Rank and suit of the card drawn from the deck
 * ** Pre-Conditions: The player was unable to play a card in their hand
 * ** Post-Conditions: The size of the array of cards is increased by 1 and a new card of rank and suit is added
 * *********************************************************************/ 
void Hand::drawCard(int rank, int suit){
	if(n_cards == 0){ //check if the array exists; if not it is the start of the game and we must draw cards
		cards = new Card[1]; //create an array of size 1 to be filled with the first card
		cards[0].setRank(rank);
		cards[0].setSuit(suit);
		++n_cards;
	}
	else{
		++n_cards; //change the value of the total number of cards in the hand
		Card *temp = new Card[n_cards];
		for(int i = 0; i < n_cards; i++){
			if(i == n_cards - 1){ //if we are at the last value in the array
				temp[i].setRank(rank); //make a new card of the given rank
				temp[i].setSuit(suit); //and the given suit
			}
			else{
				temp[i] = cards[i]; //copy the value of cards into temp
			}
		}
		delete [] cards; //delete the old array
		cards = temp; //make the pointer for cards point to temp; no need to derefference 
		temp = NULL;
	}
}

/********************************************************************* 
 * ** Function: ~Hand
 * ** Description: Destructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Hand object fell out of scope
 * ** Post-Conditions: Memory holding information about this hand was freed
 * *********************************************************************/ 
Hand::~Hand(){
	delete [] cards;
	cards = NULL; //as a precaution set the pointer to null to ensure we do not double free
}
