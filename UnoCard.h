//klepple 250836229
#pragma once
#include <iostream>
#include "Bag.h"
#include "Stack.h"
using namespace std;

enum Color { Red = 1, Blue = 2, Green = 3, Yellow = 4 };
class UnoCard {
private:
	int cardVal;
	Color cardCol;
	friend std::ostream& operator<<(std::ostream& os, const UnoCard &c);
public:
	UnoCard(int num = 1, Color col = Red);
	~UnoCard();
	int getVal()const;
	Color getColor()const;
	bool sameValue(UnoCard &c);
	bool sameColor(UnoCard &c);
};
inline bool operator<(const UnoCard& a, const UnoCard& b) {
	if (a.getColor() == b.getColor()) {
		return (a.getVal() < b.getVal());
	}
	else {
		return (a.getColor() < b.getColor());
	}
}
//Could use this to compare cards - see UnoPlayer.cpp checkMatch function
/*inline bool operator==(UnoCard& a, UnoCard& b) { 
	return (a.getVal() == b.getVal() || a.getColor() == b.getColor()); 
}*/


inline std::ostream& operator <<(std::ostream& os, const UnoCard& c) {
	int color = c.getColor();
	int value = c.getVal();
	os << " [" << value;
	switch (color) {
	case 1:
		os << "(Red)]";
		break;
	case 2:
		os << "(Blue)]";
		break;
	case 3:
		os << "(Green)]";
		break;
	case 4:
		os << "(Yellow)]";
		break;
	}
	return os;
}