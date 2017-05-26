// This is the test program for Assignment 1 for CS172
// Program written by: Abir Razzak
#include <ostream>
#include <fstream>
#include <iostream>
#include "socialite.h"
using namespace std;


	//default constructor
	socialite::socialite() {
		last_name = ""; first_name = ""; userid = ""; picture = ""; website_link = ""; website_discription = "";
	}
	//mutators
	void socialite::setLastName(string a) {
		last_name = a;
	}
	void socialite::setFirstName(string a) {
		first_name = a;
	}
	void socialite::setUserid(string a) {
		userid = a;
	}
	void socialite::setPicture(string a) {
		picture = a;
	}
	void socialite::setWebsiteLink(string a) {
		website_link = a;
	}
	void socialite::setWebsiteDescription(string a) {
		website_discription = a;
	}
	//inpectors
	string socialite::getLastName() { return last_name; }
	string socialite::getFirstName() { return first_name; }
	string socialite::getUserid() { return userid; }
	string socialite::getPicture() { return picture; }
	string socialite::getWebsiteLink() { return website_link; }
	string socialite::getWebsiteDescription() { return website_discription; }
	//member functions		
	// textOutput - writes to a textfile about the attributes of the socailite
	// @param &txt - the text file the function will output to
	void socialite::textOutput(ostream &txt) {
		txt << "First name: " << first_name << endl
			<< "Last name: " << last_name << endl
			<< "User ID: " << userid << endl
			<< "Picture: " << picture << endl
			<< "Website: " << website_link << endl
			<< "Website description: " << website_discription << endl;
	}
	// htmlOutput - creates a website based on the socialite (like a share page)
	// @param &html - html file that will be written in by the function
	void socialite::htmlOutput(ostream &html) {
		html << "<html>" << endl << "<head>" << endl << "<title>"
			<< first_name << " " << last_name << "'s Socialite Page"
			<< "</title>" << endl << "</head>" << endl << "<body>"
			<< endl << "<img SRC=\"" << picture << "\"" << endl
			<< "ALT=\"" << first_name << " " << last_name << "'s picture\" "
			<< "ALIGN=\"RIGHT\" height=\"500px\" />" << endl << "<h1> "
			<< userid << "</h1>" << "<h2>" << first_name << " "
			<< last_name << "</h2>" << "<hr />" << endl << "<p>" << first_name
			<< " wants to share <a HREF=\"" << website_link << "\" TARGET=_blank"
			<< ">" << website_discription << "</a> with you: <br />" << endl
			<< website_link << "</p>" << endl << "</body>" << endl << "</html>"
			<< endl;
	}