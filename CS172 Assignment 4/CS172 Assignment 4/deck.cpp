#include "card.h"
#include "deck.h"
using namespace std;
//initialize an empty deck
DECK::DECK()
{
	deck = {};
}
//initialize a deck with certain cards
//@param cards - a vector of all the cards to 
//				 add to the deck when created.
DECK::DECK(vector<CARD> cards)
{
	for (CARD c : cards) deck.push_back(c);
}
//shuffle - shuffle the deck
void DECK::shuffle()
{
	srand(time(NULL));
	for (int i = 0; i < deck.size() - 2; i++)
	{
		int j = rand() % (deck.size() - i) + i; //random number i <= j < size
		//swap deck[i] and deck[j]:
		CARD temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}
//dealCard - deal a card
//return - the card at the top of the deck
CARD DECK::dealCard()
{
	CARD a = deck[0]; //get the card at the top
	deck.erase(deck.begin()); //remove it from the deck
	return a;
}
//dealStack - deal multiple cards at the same time
//return - deck containing all the cards that were just dealt
DECK DECK::dealStack(int i)
{
	DECK stack = DECK();
	for (int j = i; j > 0; j--)
	{
		stack.add(dealCard());
	}
	return stack;
}
//size - gives the size of the deck
//return - int with size of deck
int DECK::size()
{
	return deck.size();
}
//add - adds a card to the bottom of the deck
void DECK::add(CARD c)
{
	deck.push_back(c);
}
//empty - empties deck (lose all your cards)
void DECK::empty()
{
	for(int i=0; i<deck.size(); i++)
	{
		deck.erase(deck.begin());
	}
}

//overloaded the output operator for deck
//use: used when testing the deck class
ostream & operator<<(ostream & os, DECK & myDeck)
{
	for (int i = 0; i < myDeck.size(); i++)
	{
		CARD c = myDeck.dealCard();
		os << c << endl;
		myDeck.add(c);
	}
	return os;
}
