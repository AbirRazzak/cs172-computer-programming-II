#pragma once
#ifndef __CARD_h_
#define __CARD_h_

#include <iostream>
#include <string>
#include <ostream>
using namespace std;

//enums:
enum Suit { CLUBS, SPADES, DIAMONDS, HEARTS };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class CARD
{
public:
	//Constructors
	CARD();
	CARD(Suit s, Rank r);
	//Accessors
	Suit getSuit();
	Rank getRank();
	//Mutators
	void setSuit(Suit s);
	void setRank(Rank r);
	//Member Function
	string display();
private:
	Suit suit; //card's suit
	Rank rank; //card's rank (aka number on card)
};

//operator overloads
ostream & operator<<(ostream& os, CARD myCard);
bool operator==(CARD & cardA, CARD & cardB);
bool operator>(CARD & cardA, CARD & cardB);
bool operator<(CARD & cardA, CARD & cardB);
#endif