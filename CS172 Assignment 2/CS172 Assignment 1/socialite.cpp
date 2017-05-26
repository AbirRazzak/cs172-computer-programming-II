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
	//extra constructor
	socialite::socialite(string first, string last, string user_id, string pic, string site, string description){
		last_name = last; first_name = first; userid = user_id; picture = pic; website_link = site; website_discription = description;
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
	void socialite::addClique(string a) {
		cliques_.push_back(a);
	}
	//inpectors
	string socialite::getLastName() { return last_name; }
	string socialite::getFirstName() { return first_name; }
	string socialite::getUserid() { return userid; }
	string socialite::getPicture() { return picture; }
	string socialite::getWebsiteLink() { return website_link; }
	string socialite::getWebsiteDescription() { return website_discription; }
	string socialite::getClique(int a) { return cliques_[a]; }
	//member functions		
	// textOutput - writes to a textfile about the attributes of the socailite
	// @param &txt - the text file the function will output to
	void socialite::textOutput(ostream &txt) {
		txt << "Socailite: " << first_name << " " << last_name << endl
			<< "User ID: " << userid << endl
			<< "Picture: " << picture << endl
			<< "Shared Link: " << website_link << endl
			<< "Description: " << userid << ": " << website_discription << endl
			<< "Cliques:" << endl;
		for (int i = 0; i < cliques_.size(); i++) txt << cliques_[i] << endl;
	}
	// htmlOutput - creates a website based on the socialite (like a share page)
	// @param &html - html file that will be written in by the function
	void socialite::htmlOutput(ostream &html) {
		html<< "<html>" << endl
				<< "<head>" << endl
					<< "<title>" << first_name << " " << last_name << "'s Socialite Page" << "</title>" << endl
				<< "</head>" << endl
				<< "<body>" << endl
					<< "<img SRC=\"" << picture << "\" ALT=\"" << first_name << "'s picture\" ALIGN=\"RIGHT\" />" << endl
					<< "<h1> " << userid << "</h1>" << endl
					<< "<h2>" << first_name << " " << last_name << "</h2>" << endl
					<< "<hr />" << endl
					<< first_name << " wants to share <a HREF=\"" << website_link << "\" TARGET=_blank>" << website_discription << "</a> with you: <br />" << endl
					<< website_link << endl
					<< "<p><i>Cliques:</i></p>" << endl
					<< "<ul>" << endl;
						for (int i = 0; i < cliques_.size(); i++) html << "<li>" << cliques_[i] << "</li>" << endl;
		html		<< "</ul>" << endl
				<< "</body>" << endl
			<< "</html>";
	}
	// numCliques - returns the number of cliques the soicalite is apart of
	// return - number of cliques socialite is apart of
	int socialite::numCliques() {
		return cliques_.size();
	}