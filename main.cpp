//klepple 250836229
#include <iostream>
#include "UnoCard.h"
#include "UnoGame.h"
#include "UnoPlayer.h"
#include "CircularDoublyLinkedList.h"
using namespace std;

int main() {
	cout << "~~~~~ WELCOME TO UNO ~~~~~" << endl;
	UnoGame newGame(3, 7, 5);
	newGame.play();
	cout << "~~~~ Thanks for playing! ~~~~~" << endl;
	return 0;
}