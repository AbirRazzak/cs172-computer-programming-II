//-----------------------------------------------------
// Program Name: Socialite Sharing Website
// Purpose: Simulate an social media platorm performing
//			a sharing of a link. 
// Coder: Abir Razzak
// Date: 4/15/17
// Last Modified: Abir Razzak, 4/16/17
//-----------------------------------------------------
#include "socialite.h"
#include <fstream>
#include <ostream>
#include <iostream>
using namespace std;

int main() {
	//Personal Socialite
	cout << "Personal socialite.... ";
	socialite personal = socialite(); //create a new socialite
	personal.setFirstName("Abir"); //set details
	personal.setLastName("Razzak");
	personal.setUserid("13752509");
	personal.setPicture("https://media.licdn.com/mpr/mpr/shrinknp_200_200/AAEAAQAAAAAAAA3iAAAAJGY1ZWYzZmM5LTI4MGEtNGMxNy1hNTdmLTdiNTg0ZWRiYWUxNg.jpg");
	personal.setWebsiteLink("https://www.linkedin.com/in/animnations/");
	personal.setWebsiteDescription("My linkedin!");
	cout << "Socailite created." << endl;
	ofstream abirTxt, abirHtml; 
	abirTxt.open("abir.txt"); abirHtml.open("abir.html"); //create outfiles
	personal.textOutput(abirTxt); personal.htmlOutput(abirHtml); //create textfile and html
	abirTxt.close(); abirHtml.close(); //close output files

	//Sports Figure
	cout << "Sports figure socialite.... ";
	socialite sport = socialite();
	sport.setFirstName("LeBron");
	sport.setLastName("James");
	sport.setUserid("LB_James42");
	sport.setPicture("https://lh3.googleusercontent.com/vv7J-trWJQD3TJS7YDC7Ux9PXyKiPirDEuhh3JA7_PUtcDlk_jg");
	sport.setWebsiteLink("https://en.wikipedia.org/wiki/LeBron_James");
	sport.setWebsiteDescription("Read my wikipedia!");
	cout << "Socailite created." << endl;
	ofstream sportTxt, sportHtml;
	sportTxt.open("sport.txt"); sportHtml.open("sport.html");
	sport.textOutput(sportTxt); sport.htmlOutput(sportHtml);

	//Political Figure
	cout << "Politcal Figure socialite.... ";
	socialite p = socialite();
	p.setFirstName("Rick");
	p.setLastName("Scott");
	p.setUserid("ILuvFlorida");
	p.setPicture("http://media2.s-nbcnews.com/i/MSNBC/Components/Video/__NEW/n_hayes_1fl_130718.jpg");
	p.setWebsiteLink("https://en.wikipedia.org/wiki/Rick_Scott");
	p.setWebsiteDescription("Read my wiki!");
	cout << "Socailite created." << endl;
	ofstream pTxt, pHtml;
	pTxt.open("political.txt"); pHtml.open("political.html");
	p.textOutput(pTxt); p.htmlOutput(pHtml);

	//Cartoon Character
	cout << "Cartoon Character socialite.... ";
	socialite c = socialite();
	c.setFirstName("Ojii");
	c.setLastName("san");
	c.setUserid("Picos_Grandaddy");
	c.setPicture("https://myanimelist.cdn-dena.com/images/characters/7/106598.jpg");
	c.setWebsiteLink("https://myanimelist.net/anime/1639/Boku_no_Pico");
	c.setWebsiteDescription("Check out my show!");
	cout << "Socailite created." << endl;
	ofstream cTxt, cHtml;
	cTxt.open("cartoon.txt"); cHtml.open("cartoon.html");
	c.textOutput(cTxt); c.htmlOutput(cHtml);

	//Anyone
	cout << "Anyone socialite.... ";
	socialite a = socialite();
	a.setFirstName("Shia");
	a.setLastName("LeBeouf");
	a.setUserid("JUST_DO_IT");
	a.setPicture("https://i.ytimg.com/vi/ZXsQAXx_ao0/maxresdefault.jpg");
	a.setWebsiteLink("https://www.youtube.com/watch?v=ZXsQAXx_ao0");
	a.setWebsiteDescription("JUST DO IT!");
	cout << "Socailite created." << endl;
	ofstream aTxt, aHtml;
	aTxt.open("LeBeouf.txt"); aHtml.open("LeBeouf.html");
	a.textOutput(aTxt); a.htmlOutput(aHtml);

	return 0;
}