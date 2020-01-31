/********************************************************************
 * ** Program Filename: player.cpp
 * ** Author: Megan Lynn Tuker
 * ** Date: 02/02/2020
 * ** Description: Contains information on the player class
 * ** Input: N/A
 * ** Output: Hand and name of player
 * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include "player.h"
#include "hand.h"
#include "deck.h"

/********************************************************************* 
 * ** Function: Player
 * ** Description: Constructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Player object was created
 * ** Post-Conditions: N/A
 * *********************************************************************/ 
Player::Player(){
	//nothing to construct by default; everything is done using setters
}

/********************************************************************* 
 * ** Function: getName
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Player object was created
 * ** Post-Conditions: Returns the name of a player
 * *********************************************************************/ 
string Player::getName() const{
	return name;
}

/********************************************************************* 
 * ** Function: getHand
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Player object was created
 * ** Post-Conditions: Returns the players hand
 * *********************************************************************/ 
Hand Player::getHand() const{
	return hand;
}

/********************************************************************* 
 * ** Function: getN_cards
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Player object was created
 * ** Post-Conditions: Returns the number of cards in the player's hand
 * *********************************************************************/ 
int Player::getN_cards(){
	hand.getN_cards();
}

/********************************************************************* 
 * ** Function: setName
 * ** Description: Mutator (setter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Player object was created
 * ** Post-Conditions: Returns the name of hte player
 * *********************************************************************/ 
void Player::setName(string player_name){
	name = player_name;
}

int Player::selectCard(){
	int card_location;
	bool valid_input;
	do{
		valid_input = true;
		cout << "Select which card you wish to play: ";
		string s;
		getline(cin,s);
		card_location = atoi(s.c_str()); //convert string to integer 1-9 if input was integer or 0 otherwise
		if(card_location > hand.getN_cards() || card_location < 1){
			cout << "Invalid input. ";
			valid_input = false;
		}
	}while(valid_input == false);
	
	return card_location - 1; //the cards are numbered 1 - last card, so if the player selects [3] they mean 2 in array
}

/********************************************************************* 
 * ** Function: playCard
 * ** Description: Calls playCard in Hand; creates an array 1 smaller with all the old cards except the card played
 * ** Parameters: Card location in the hand
 * ** Pre-Conditions: The card to be played is a valid choice
 * ** Post-Conditions: The size of the array of cards is decreased by 1 and the card that is played is removed
 * *********************************************************************/ 
void Player::playCard(int card_location){
	hand.playCard(card_location);
}

/********************************************************************* 
 * ** Function: drawCard
 * ** Description: Calls drawCard in Hand; Creates array 1 larger with all old cards and drawn card added to the end
 * ** Parameters: Rank and suit of the card drawn from the deck
 * ** Pre-Conditions: The player was unable to play a card in their hand
 * ** Post-Conditions: The size of the array of cards is increased by 1 and a new card of rank and suit is added
 * *********************************************************************/ 
void Player::drawCard(int rank, int suit){
	hand.drawCard(rank, suit);
}

/********************************************************************* 
 * ** Function: printHand
 * ** Description: Prints the value of each card in the player's hand
 * ** Parameters: N/A
 * ** Pre-Conditions: N/A
 * ** Post-Conditions: The hand is printed in the order it sits in the array along with its posiiton
 * *********************************************************************/ 
void Player::printHand() const{
	hand.printHand();
}

/********************************************************************* 
 * ** Function: choose8suit
 * ** Description: Randomly chooses a suit when the computer plays an 8
 * ** Parameters: N/A
 * ** Pre-Conditions: Computer plays an 8
 * ** Post-Conditions: A new suit 1-4 is chosen
 * *********************************************************************/ 
int Player::choose8suit(){
	int suit;
	srand(time(NULL));
	suit = (rand() % 4) + 1; //mod 4 gives numbers 0-3, we want 1-4
	if(suit == 1){
		cout << "New suit: diamonds" << endl;
	}
	else if(suit == 2){
		cout << "New suit: hearts" << endl;
	}
	else if(suit == 3){
		cout << "New suit: spades" << endl;
	}
	else if(suit == 4){
		cout << "New suit: clubs" << endl;
	}
	return suit;
}

/********************************************************************* 
 * ** Function: ~Player
 * ** Description: Destructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Player object fell out of scope
 * ** Post-Conditions: Memory holding information about this player was freed
 * *********************************************************************/ 
Player::~Player(){
	//no memory allocated
}
