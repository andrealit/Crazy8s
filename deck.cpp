/********************************************************************
 * ** Program Filename: deck.cpp
 * ** Author: Megan Lynn Tuker
 * ** Date: 02/02/2020
 * ** Description: Contains information on the deck class
 * ** Input: N/A
 * ** Output: Array of 52 cards and the number of cards in the deck
 * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include "deck.h"
#include "card.h"

/********************************************************************* 
 * ** Function: Deck
 * ** Description: Constructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Deck object was created
 * ** Post-Conditions: A deck of 52 cards was created with unique rank and suit combinations
 * *********************************************************************/ 
Deck::Deck(){
	int counter = 0;
	for(int j = 1; j <= 13; j++){
		for(int k = 1; k <= 4; k++){
			cards[counter].setRank(j); //for every rank
			cards[counter].setSuit(k); //set the suit
			counter++; //each time the inner loop is finished the counter increases by 4; 13 times yields 52
		}
	}
}

/********************************************************************* 
 * ** Function: getN_cards
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Deck object was created
 * ** Post-Conditions: Returns the number of cards in the deck
 * *********************************************************************/ 
int Deck::getN_cards() const{
	return n_cards;
}

/********************************************************************* 
 * ** Function: getCard
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Deck object was created
 * ** Post-Conditions: Returns the location of a particular card in the deck
 * *********************************************************************/ 
Card Deck::getCard(int card_location){
	return cards[card_location];
}

/********************************************************************* 
 * ** Function: setN_cards
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Card object was created
 * ** Post-Conditions: Resets the number of cards in the deck
 * *********************************************************************/ 
void Deck::setN_cards(int num_cards){
	n_cards = num_cards;
}

/********************************************************************* 
 * ** Function: shuffleDeck
 * ** Description: Randomly changes the position of the cards in the deck
 * ** Parameters: N/A
 * ** Pre-Conditions: The deck was created
 * ** Post-Conditions: The deck has been randomly shuffled
 * *********************************************************************/ 
void Deck::shuffleDeck(){
	srand(time(0));
	for(int i = 0; i < 52; i++){
		int cards_left = i + (rand() % 52 - i);
		swap(cards[cards_left], cards[i]);
	}
}

/********************************************************************* 
 * ** Function: printDeck
 * ** Description: Prints the value of each card in the deck
 * ** Parameters: N/A
 * ** Pre-Conditions: N/A
 * ** Post-Conditions: The deck is printed in the order it sits in the array
 * *********************************************************************/ 
void Deck::printDeck() const{
	for(int i = 0; i < 52; i++){
		cards[i].printCard();
	}
}

/********************************************************************* 
 * ** Function: Deck
 * ** Description: Destructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Deck object fell out of scope
 * ** Post-Conditions: Memory holding information about this object is freed
 * *********************************************************************/ 
Deck::~Deck(){
	//not needed; no dynamic memory
}
