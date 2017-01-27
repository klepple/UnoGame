//klepple 250836229
#include "UnoGame.h"
#include <iostream>
#include <ctime>
using namespace std;

UnoGame::UnoGame(int numPlayers, int numCards, int n){
	this->numPlayers = numPlayers;
	this->numCards = numCards;
	this->n = n;
	//Create players
	gamePlayers = new UnoPlayer[numPlayers];

	//Customize player names (optional)
	gamePlayers[0].setName("Aang");
	gamePlayers[1].setName("Toph");
	gamePlayers[2].setName("Sokka");

	Bag<UnoCard> shuffleBag(n * 8);//Create bag big enough to contain all game cards
	Color c[] = { Red, Blue, Green, Yellow };//Create array of enum Colors
	srand(time(NULL));
	//Fill bag with cards
	for (int i = 0; i < 2; i++) {//Do twice (2 copies of each card)
		for (int col = 0; col < 4; col++) {
			for (int value = 1; value <= n; value++) {
				shuffleBag.add(UnoCard(value, c[col]));
			}
		}
	}

	//Set up drawDeck
	while(!shuffleBag.isEmpty()) {
		drawDeck.enqueue(shuffleBag.getOne());
	}
	//cout << "Deck has been shuffled and is ready!" << endl;

	//Deal out cards
	for (int j = 0; j < numPlayers; j++) {
		for (int i = 1; i <= numCards; i++) {
			gamePlayers[j].addCard(drawDeck.dequeue());
		}
		//cout << gamePlayers[j].getName() << " has drawn their hand!" << endl;
	}
	//Set card on top of face up pile
	faceUpPile.push(drawDeck.dequeue());
}

UnoGame::~UnoGame(){ }//Deconstructor

void UnoGame::repopulateDeck(){
	if (drawDeck.isEmpty()) {
		Bag<UnoCard> tempBag(faceUpPile.size());//Make a temporary bag to shuffle
		UnoCard tempTopCard = faceUpPile.pop();//Keep the top card of the face up pile
		for (int i = 0; i < faceUpPile.size(); i++) {//Add the cards from the face up pile to the bag
			tempBag.add(faceUpPile.pop());
		}
		for (int j = 0; j < tempBag.currentSize(); j++) {//Place the cards (now shuffled) back into the empty deck
			drawDeck.enqueue(tempBag.getOne());
		}
		faceUpPile.push(tempTopCard);//Push the top card we popped before shuffling back onto the face up pile
		cout << "The deck has been repopulated." << endl;
	}
}

void UnoGame::play(){
	bool endGame = false;
	cout << "Let's welcome our players! " << endl;
	for (int i = 0; i < numPlayers; i++) {
		cout << i + 1 << ": " << gamePlayers[i].getName() << ", ";
	}
	cout << endl;

	while (!endGame) {//Loops while no player has an empty hand
		cout << endl;
		for (int i = 0; i < numPlayers; i++) {
			cout << "Current top card: " << faceUpPile.peek() << endl;//Displays top of face up pile
			cout << "|| " << gamePlayers[i].getName() << "'s turn || ";
			cout << gamePlayers[i];//Prints out the number of remaining cards in the player's hand as well as their value and color
			if (gamePlayers[i].checkMatch(faceUpPile)) {//Players check to see if they can play
				cout << gamePlayers[i].getName() << " found a match! They played " << faceUpPile.peek() << endl;
			}
			else {//Did not find match
				cout << gamePlayers[i].getName() << " could not find a card to play. They drew a card from the deck." << endl;
				gamePlayers[i].addCard(drawDeck.dequeue());
			}
			cout << endl;
			if (drawDeck.isEmpty()) {
				repopulateDeck();
			}
			if (gamePlayers[i].getHandLength() == 1) {//Yell UNO
				cout << gamePlayers[i].getName() << " yells UNO!" << endl << endl;
			}
			if (gamePlayers[i].getHandLength() == 0) {//Game over
				cout << gamePlayers[i].getName() << " won UNO! CONGRATULATIONS!" << endl;
				endGame = true;
				break;
			}
		}
	}
}

