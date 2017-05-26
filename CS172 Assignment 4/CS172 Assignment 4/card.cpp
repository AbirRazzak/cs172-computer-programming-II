#include "card.h"
using namespace std;

//creates a card with unknown suit and rank
CARD::CARD()
{
	suit;
	rank;
}

//creates a card
//@param s - suit of the card
//@param r - rank(number) of the card
CARD::CARD(Suit s, Rank r)
{
	suit = s;
	rank = r;
}

//getSuit - gives the suit of the card
//return - suit of the card
Suit CARD::getSuit()
{
	return suit;
}

//getRank - gives the rank(number) of the card
//return - rank of the card
Rank CARD::getRank()
{
	return rank;
}

//setSuit - sets the suit of the card
//@param s - desired suit of the card
void CARD::setSuit(Suit s)
{
	suit = s;
}

//setRank - sets the rank(number) of the card
//@param r - desired rank of the card
void CARD::setRank(Rank r)
{
	rank = r;
}

//display - creates what the card would look like in the program
//return - a string of what the card would look like in terminal
string CARD::display()
{
	string cardDisplay;
	//Determine what rank is diaplayed on card
	switch (getRank())
	{
	case(TWO):
		cardDisplay = "2";
		break;
	case(THREE):
		cardDisplay = "3";
		break;
	case(FOUR):
		cardDisplay = "4";
		break;
	case(FIVE):
		cardDisplay = "5";
		break;
	case(SIX):
		cardDisplay = "6";
		break;
	case(SEVEN):
		cardDisplay = "7";
		break;
	case(EIGHT):
		cardDisplay = "8";
		break;
	case(NINE):
		cardDisplay = "9";
		break;
	case(TEN):
		cardDisplay = "10";
		break;
	case(JACK):
		cardDisplay = "J";
		break;
	case(QUEEN):
		cardDisplay = "Q";
		break;
	case(KING):
		cardDisplay = "K";
		break;
	case(ACE):
		cardDisplay = "A";
		break;
	}
	//Determine what suit is displayed on card
	switch (getSuit())
	{
	case(CLUBS):
		cardDisplay += "C";
		break;
	case(SPADES):
		cardDisplay += "S";
		break;
	case(DIAMONDS):
		cardDisplay += "D";
		break;
	case(HEARTS):
		cardDisplay += "H";
		break;
	}
	return cardDisplay;
}

//overloaded the output operator for deck
//use: used to display values and suits of cards
ostream & operator<<(ostream & os, CARD myCard)
{
	string cardDisplay = myCard.display();
	os << cardDisplay;
	return os;
}
//overloaded the equals operator for deck
//use: to compare values of two cards
bool operator==(CARD & cardA, CARD & cardB)
{
	return (cardA.getRank() == cardB.getRank());
}
//overloaded the greater than operator for deck
//use: to compare values of two cards
bool operator>(CARD & cardA, CARD & cardB)
{
	return (cardA.getRank() > cardB.getRank());
}
//overloaded the less than operator for deck
//use: to compare values of two cards
bool operator<(CARD & cardA, CARD & cardB)
{
	return (cardA.getRank() < cardB.getRank());
}
