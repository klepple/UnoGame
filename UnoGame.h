//klepple 250836229
#pragma once
#include "UnoCard.h"
#include "UnoPlayer.h"
#include "Bag.h"
#include "OrderedList.h"
#include "Queue.h"
#include "Stack.h"

class UnoGame {
private:
	int numPlayers, numCards, n;
	Queue<UnoCard> drawDeck;
	Stack<UnoCard> faceUpPile;
	UnoPlayer *gamePlayers;
	
public:
	UnoGame(int numPlayers = 3, int numCards = 7, int n = 5);
	~UnoGame();
	void repopulateDeck();
	void play();
};