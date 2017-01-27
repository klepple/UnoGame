//klepple 250836229
#include "UnoCard.h"
#include "Bag.h"

UnoCard::UnoCard(int val, Color col) {
	this->cardVal = val;//Set card Value
	this->cardCol = col;//Set card Color
}

UnoCard::~UnoCard(){ }

inline int UnoCard::getVal()const{
	return cardVal;
}

inline Color UnoCard::getColor()const{
	return cardCol;
}

bool UnoCard::sameValue(UnoCard& c){
	if (c.getVal() == cardVal) {
		return true;
	}
	else {
		return false;
	}
}

bool UnoCard::sameColor(UnoCard& c){
	if (c.getColor() == cardCol) {
		return true;
	}
	else {
		return false;
	}
}