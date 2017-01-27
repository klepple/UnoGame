//klepple 250836229
#include "UnoPlayer.h"

UnoPlayer::UnoPlayer(string name){//Constructor
	this->name = name;
}

UnoPlayer::~UnoPlayer(){//Deconstructor
}

void UnoPlayer::setName(string name){
	this->name = name;
}

string UnoPlayer::getName() const{
	return name;
}

void UnoPlayer::addCard(UnoCard& c){
	hand.insert(c);
}

int UnoPlayer::getHandLength(){
	return hand.getLength();
}

bool UnoPlayer::checkMatch(Stack<UnoCard>& pile){
	//Could use this but instructions specified to check the value before the color
	/*for (int i = 1; i <= hand.getLength(); i++) {
		if (pile.peek() == hand.retrieve(i)) {
			pile.push(hand.remove(i));
			return true;
		}
	}*/
	//Check value
	for (int i = 1; i <= hand.getLength(); i++) {//Look through player's hand
		if ((pile.peek()).sameValue(hand.retrieve(i))) {//If a card has the same value, play it
			pile.push(hand.remove(i));
			return true;
		}
	}
	//Check color
	for (int j = 1; j <= hand.getLength(); j++) {//Look through player's hand
		if ((pile.peek()).sameColor(hand.retrieve(j))) {//If a card has the same color, play it
			pile.push(hand.remove(j));
			return true;
		}
	}
	return false;
}

void UnoPlayer::printHand() const{
	cout << "# remaining: " << hand.getLength() << " | ";//Number of remaining cards
	for (int i = 1; i <= hand.getLength(); i++) {
		cout << hand.retrieve(i);//Card values and colors
	}
}
