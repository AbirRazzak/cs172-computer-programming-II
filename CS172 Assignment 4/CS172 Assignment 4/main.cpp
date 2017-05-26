//WAR! Card Game
//Code Written by: Abir Razzak
//Date of Last Revision: 5/25/2017
//Description:
//This program is meant to represent the card game WAR!
//The purpose of this game is to out-rank your opponent until he/she
//	does not have any cards left. If both your and your opponent's cards
//	have the same rank, then engauge in a war.
//War: both players must place a card face down, and then play another card.
//	the winner of this will get all the cards on the field. If you do not have
//	enough cards, then you automatically lose.
//
//NOTE: This simulation is among two CPU's. There is no human-interaction involved.

#include "card.h"
#include "deck.h"
using namespace std;

//Prototypes
void playTurn(DECK & d1, DECK & d2, CARD c1, CARD c2);
void playWar(DECK & d1, DECK & d2, vector<CARD> prize);

int main()
{
	//create a deck with 52 cards;
	DECK full_deck = DECK();
	for (int i = 0; i < 4; i++) {
		switch (i)
		{
		case(0): //add all the clubs to the deck
			for (int j = 0; j < 13; j++)
				full_deck.add(CARD(CLUBS, static_cast<Rank>(j)));
			break;
		case(1): //add all the hearts to the deck
			for (int j = 0; j < 13; j++)
				full_deck.add(CARD(HEARTS, static_cast<Rank>(j)));
			break;

		case(2): //add all the spades to the deck
			for (int j = 0; j < 13; j++)
				full_deck.add(CARD(SPADES, static_cast<Rank>(j)));
			break;
		case(3): //add all the diamonds to the deck 
			for (int j = 0; j<13; j++)
				full_deck.add(CARD(DIAMONDS, static_cast<Rank>(j)));
			break;
		}
	}
	//cout << full_deck; //use this line to check if the entire deck is inputted correctly

	//shuffle deck and deal both players half the deck
	full_deck.shuffle();
	DECK p1 = full_deck.dealStack(26);
	DECK p2 = full_deck.dealStack(26);
	//if (full_deck.size() == 0) cout << "Done dealing"; //Check if all cards are gone from the starting deck
	//cout << "Player 1 has " << p1.size() << " cards. Player 2 has " << p2.size() << " cards. \n"; //check if both players have 26 cards

	//while both players have cards....
	while (p1.size() != 0 && p2.size() != 0)
	{
		CARD playerOne = p1.dealCard(); //p1 draws a card
		CARD playerTwo = p2.dealCard(); //p2 draws a card
		playTurn(p1, p2, playerOne, playerTwo);
	}

	//cout << p1.size() << " " << p2.size() << endl;

		//Player without cards loses
		if (p1.size() == 0) cout << "Player 2 wins!" << endl;
		if (p2.size() == 0) cout << "Player 1 wins!" << endl;

	//Class tests used:
	/* DECK TESTING
	DECK my_deck = DECK();
	CARD a = CARD(HEARTS, QUEEN);
	CARD b = CARD(HEARTS, ACE);
	CARD c = CARD(CLUBS, TWO);
	CARD d = CARD(SPADES, FIVE);
	my_deck.add(a); my_deck.add(b); my_deck.add(c); my_deck.add(d);
	cout << my_deck;
	cout << "-------------\n";
	my_deck.shuffle();
	cout << my_deck;
	cout << "-------------\n";
	my_deck.shuffle();
	cout << my_deck;
	cout << "-------------\n";
	my_deck.shuffle();
	cout << my_deck;
	cout << "-------------\n";
	my_deck.shuffle();
	cout << my_deck; */

	/* CARD TESTING
	CARD a = CARD(HEARTS, QUEEN);
	CARD b = CARD(HEARTS, ACE);
	if (a < b)
	{
		cout << "True bro.\n";
	}
	else
	{
		cout << "Not true man.\n";
	} */
	return 0;
}

//playTurn - plays a turn of WAR!
//@param d1 - player 1's deck
//@param d2 - player 2's deck
//@param c1 - player 1's card for current turn
//@param c2 - player 2's card for current turn
void playTurn(DECK & d1, DECK & d2, CARD c1, CARD c2)
{
	cout << c1 << " vs " << c2 << endl;
	if (c1 > c2) //if p1 wins, p1 takes both cards
	{
		d1.add(c1); //Add both cards to
		d1.add(c2);	//to winner's deck
	}
	else if (c2 > c1) //if p2 wins, p2 takes both cards
	{
		d2.add(c2); //Add both cards to
		d2.add(c1);	//to winner's deck
	}
	else if (c1 == c2) //WAR!
	{
		if (d1.size() < 2) //check if player 1 has enough cards to do a war
		{
			cout << "Player 1 does not have enough cards left for war!" << endl;
			d1.empty();
		}
		else if (d2.size() < 2) //check if player 2 has enough cards to do a war
		{
			cout << "Player 2 does not have enough cards left for war!" << endl;
			d2.empty();
		}
		else //if both players have enough cards to initiate a war:
		{
			vector<CARD> warCards;	//Creat a prize pool for
			warCards.push_back(c1);	//the WAR! And add the
			warCards.push_back(c2);	//two current cards to pool

			playWar(d1, d2, warCards); //play the war
		}
	}
}

//playWar - play a turn of war in WAR!
//@param d1 - player 1's deck
//@param d2 - player 2's deck
//@param prize - vector of all the cards the winner will recieve
void playWar(DECK & d1, DECK & d2, vector<CARD> prize)
{
	if (d1.size() < 2)	//check if player 1 has enough cards to do a war
	{
		cout << "Player 1 does not have enough cards left for war!" << endl;
		d1.empty();
	}
	else if (d2.size() < 2)	//check if player 2 has enough cards to do a war
	{
		cout << "Player 2 does not have enough cards left for war!" << endl;
		d2.empty();
	}
	else //if both players have enough cards to initiate a war:
	{
		cout << "WAR!!	";
		prize.push_back(d1.dealCard()); //Each player places a card face down
		prize.push_back(d2.dealCard()); //(and add these cards to the prize pool).

		CARD warOne = d1.dealCard(); //player 1 draws a card
		CARD warTwo = d2.dealCard(); //player 2 draws a card
		cout << warOne << " vs " << warTwo << endl;
		prize.push_back(warOne); //Also add these cards
		prize.push_back(warTwo); //to the prize pool

		if (warOne == warTwo) //if the two war cards are equal:
		{
			playWar(d1, d2, prize); //then play war again
		}
		else if (warOne > warTwo) //if player 1 wins the war:
		{
			for (CARD c : prize) //Take every card in the prize pool
			{					 //
				d1.add(c);		 //and add it to player 1's deck
			}
		}
		else if (warTwo > warOne) //if player 2 wins the war:
		{
			for (CARD c : prize) //Take every card in the prize pool
			{					 //
				d2.add(c);		 //and add it to player 1's deck
			}
		}
	}
}

