#pragma once
#ifndef __DECK_h_
#define __DECK_h_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "card.h"
using namespace std;

class DECK
{
public:
	//Constructors
	DECK();
	DECK(vector<CARD> cards);
	//Member Functions
	void shuffle();
	CARD dealCard();
	DECK dealStack(int i);
	int size();
	void add(CARD c);
	void empty();
private:
	vector<CARD> deck; //Vector used to hold all the cards
};
ostream & operator<<(ostream & os, DECK & myDeck); //output operator overload (to display cards)
#endif __DECK_h_