/********************************************************************
 * ** Program Filename: game.cpp
 * ** Author: Megan Lynn Tucker
 * ** Date: 02/02/2020
 * ** Description: Contains information on the game class
 * ** Input: N/A
 * ** Output: Array of 2 players, Deck class, int representing the location in the deck 
 * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include "game.h"
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;

/********************************************************************* 
 * ** Function: Game
 * ** Description: Constructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Game object was created
 * ** Post-Conditions: Create two players (one with input name, other computer) and deal out 7 cards to each
 * *********************************************************************/ 
Game::Game(){
	cout << "Enter a name: ";
	string playerName;
	getline(cin, playerName);
	players[0].setName(playerName);
	players[1].setName("Computer");

	cards.shuffleDeck();
	
	for(int i = 0; i < 14; i = i + 2){ //iterate by 2 because 1 card is drawn for player and 1 for computer
		int rank0 = cards.getCard(i).getRank(); //player
		int suit0 = cards.getCard(i).getSuit(); //player
		int rank1 = cards.getCard(i + 1).getRank(); //computer; add 1 to ensure we don't draw the same card twice
		int suit1 = cards.getCard(i + 1).getSuit(); //computer; add 1 to ensure we don't draw the same card twice
		players[0].drawCard(rank0, suit0);
		players[1].drawCard(rank1, suit1);
	}

	setPile(cards.getCard(14)); //"draw" one last card to start the pile
	card_location = 15; //we are now at the 15th card in the deck (technically the 16th, but array sees this as 15)
}

/********************************************************************* 
 * ** Function: getPile
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Game object was created
 * ** Post-Conditions: Returns the Card object pile
 * *********************************************************************/ 
Card Game::getPile() const{
	return pile;
}

/********************************************************************* 
 * ** Function: getCard_location
 * ** Description: Accessor (getter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Game object was created
 * ** Post-Conditions: Returns the card location in the deck
 * *********************************************************************/ 
int Game::getCard_location() const{
	return card_location;
}

/********************************************************************* 
 * ** Function: setPile
 * ** Description: Mutator (setter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Game object was created
 * ** Post-Conditions: Sets the pile to a new card
 * *********************************************************************/ 
void Game::setPile(Card new_card){
	pile = new_card;
}

/********************************************************************* 
 * ** Function: setCard_location
 * ** Description: Mutator (setter)
 * ** Parameters: N/A
 * ** Pre-Conditions: A Game object was created
 * ** Post-Conditions: Redefine the card_location
 * *********************************************************************/ 
void Game::setCard_location(int new_location){
	card_location = new_location;
}

/********************************************************************* 
 * ** Function: printGame
 * ** Description: Prints the status of the game; pile card and the player hand
 * ** Parameters: N/A
 * ** Pre-Conditions: N/A
 * ** Post-Conditions: Game is printed to the screen
 * *********************************************************************/ 
void Game::printGame(){
	cout << endl << "Pile: ";
	pile.printCard();
	cout << endl<< "Player hand:" << endl;
	players[0].printHand();
	cout << endl;
}

/********************************************************************* 
 * ** Function: checkHand
 * ** Description: Checks to see if the player can play a card in their hand; if not draw card; check if deck is empty
 * ** Parameters: player number and game over status
 * ** Pre-Conditions: The game is not over
 * ** Post-Conditions: Player has a hand that contains cards which they are able to play
 * *********************************************************************/ 
bool Game::checkHand(int player_number, bool game_over){
	int pileRank = pile.getRank();
	int pileSuit = pile.getSuit();
	bool can_play;
	int n_cards;

	do{
		can_play = true;
		n_cards = players[player_number].getN_cards();

		for(int i = 0; i < n_cards; i++){ //check to see if we can play a card in the hand		
			int cardRank = players[player_number].getHand().getCards()[i].getRank();
			int cardSuit = players[player_number].getHand().getCards()[i].getSuit();
			
			if(cardRank == pileRank || cardSuit == pileSuit || cardRank == 8){
				can_play = true; //at least one card can be played so we break out of for loop
				break; //break out of the for loop but not the dowhile
			}
			else{
				can_play = false;
			}
		}
		
		if(can_play == false){ //if we never broke out of the for loop, draw a card
			if(card_location == 52){ //first check to see that we can draw a card
				cout << "The deck is empty. Game over. ";
				if(players[0].getHand().getN_cards() < players[1].getHand().getN_cards()){
					cout << players[0].getName() << " wins! "; //player wins
				}
				else if(players[0].getHand().getN_cards() > players[1].getHand().getN_cards()){
					cout << "Computer wins! "; //computer wins
				}
				else if(players[0].getHand().getN_cards() == players[1].getHand().getN_cards()){
					cout << "Tie. "; //neither wins
				}
				game_over = true;
				return game_over;
			}
			else{ //we can draw a card so we draw a card
				Card card = cards.getCard(card_location); //pull next card from the deck
				if(player_number == 0){ //only print which card is drawn for the player
					cout << "Unable to play a card. Draw [" << n_cards + 1 << "]";
					card.printCard();
				}
				int rank = card.getRank();
				int suit = card.getSuit();
				players[player_number].drawCard(rank, suit); //add the card from the deck to hand
				++card_location; //change the location of where we are in the deck
			}
		}
	}while(can_play == false);
	return game_over;
}

/********************************************************************* 
 * ** Function: playCard
 * ** Description: Asks player to select card to play; checks if play is valid (in not reprompt); call playCard
 * ** Parameters: Player number
 * ** Pre-Conditions: The card to be played is a valid choice
 * ** Post-Conditions: The size of the hand is decreased by 1 
 * *********************************************************************/ 
void Game::playCard(int player_number){
	//if the player only has one card in their hand and they can play it then they win the game
	int cardRank, cardSuit;
	bool can_play;
	do{
		can_play = true;
		int card_number;
		card_number = players[player_number].selectCard(); //selectCard() in player verifies input is valid
		cardRank = players[player_number].getHand().getCards()[card_number].getRank();
		cardSuit = players[player_number].getHand().getCards()[card_number].getSuit();
		int pileRank = pile.getRank();
		int pileSuit = pile.getSuit();

		if(cardRank == pileRank || cardSuit == pileSuit || cardRank == 8){
			can_play = true; //at least one card can be played so we break out of for loop
			players[player_number].playCard(card_number); //remove card from hand; 1 less than in
			if(cardRank == 8){
				cout << "Choose a suit. Select [1]diamonds [2]hearts [3]spades [4]clubs: ";
				bool valid_input;
				string s;
				do{
					valid_input = true;
					getline(cin, s);
					cardSuit = atoi(s.c_str());
					if(cardSuit < 1 || cardSuit > 4){
						cout << "Invalid input. ";
						valid_input = false;
					}
				}while(valid_input == false);
			}
		}
		else{
			cout << "You cannot play that card. ";
			can_play = false;
		}
	}while(can_play == false);
	//reset the pile to the new suit and rank
	pile.setRank(cardRank);
	pile.setSuit(cardSuit);
	cout << endl << "Pile: ";
	pile.printCard();
}

/********************************************************************* 
 * ** Function: playComputer_card
 * ** Description: Automatically plays the first card possible; calls play card
 * ** Parameters: Player number
 * ** Pre-Conditions: Player is computer
 * ** Post-Conditions: The size of the hand is decreased by 1 
 * *********************************************************************/ 
void Game::playComputer_card(int player_number){
	cout << endl << "Computer turn." << endl;
	int pileRank = pile.getRank();
	int pileSuit = pile.getSuit();
	int cardRank, cardSuit;
	for(int i = 0; i < players[player_number].getHand().getN_cards(); i++){
		cardRank = players[player_number].getHand().getCards()[i].getRank();
		cardSuit = players[player_number].getHand().getCards()[i].getSuit();
		if(cardRank == pileRank || cardSuit == pileSuit || cardRank == 8){
			players[player_number].playCard(i); //remove card from hand
			if(cardRank == 8){
				cardSuit = players[player_number].choose8suit();
			}
			break;
		}
	}
	pile.setRank(cardRank);
	pile.setSuit(cardSuit);
}

/********************************************************************* 
 * ** Function: turn
 * ** Description: checks the hand then depending on if the player is the user or computer calls the proper function
 * ** Parameters: player_number
 * ** Pre-Conditions: game_over == false
 * ** Post-Conditions: the game is either over or it is not and another turn will be initiated
 * *********************************************************************/ 
bool Game::turn(int player_number){
	bool game_over = false;
	game_over = checkHand(player_number, game_over); //check if the deck is empty in here
	
	//after checking that they can play cards in their hand, if their hand is 1 then they win
	if(game_over == false){
		if(players[player_number].getN_cards() == 1){
			cout << players[player_number].getName() << " wins! ";
			game_over = true;
		}
		else if(player_number == 0){
			playCard(player_number);
		}
		else if(player_number == 1){
			playComputer_card(player_number);
		}
	}
	return game_over;
}

/********************************************************************* 
 * ** Function: ~Game
 * ** Description: Destructor
 * ** Parameters: N/A
 * ** Pre-Conditions: A Game object fell out of scope
 * ** Post-Conditions: Memory holding information about this game was freed
 * *********************************************************************/ 
Game::~Game(){
	//no memory dynamically allocated
}
