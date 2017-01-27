//klepple 250836229
#pragma once
#include <iostream>
#include "OrderedList.h"
#include "UnoCard.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;
class UnoPlayer {
private:
	string name;
	OrderedList<UnoCard> hand;
	friend std::ostream& operator<<(std::ostream& os, const UnoPlayer& p);
public:
	UnoPlayer(string name = "CoolGuy");
	~UnoPlayer();
	void setName(string name);
	string getName() const;
	void addCard(UnoCard& c);
	int getHandLength();
	bool checkMatch(Stack<UnoCard>& pile);
	void printHand() const;
};

inline std::ostream& operator <<(std::ostream& os, const UnoPlayer& p) {
	os << endl << p.getName() << "'s hand: ";
	p.printHand();
	os << endl;
	return os;
}