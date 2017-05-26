#ifndef __socailite_h__
#define __socialite_h__

//imports
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// socailite object - a mock socail media platform used to share links
// Attributes include a first and last name, user id, picture, website link
// and a description for the website.
// Use set_ to set values for the attributes and get_ to return the values.
class socialite {
	public:
		//default constructor
		socialite();
		//extra constructor
		socialite(string first, string last, string user_id, string pic, string site, string description);
		//mutators
		void setLastName(string a);
		void setFirstName(string a);
		void setUserid(string a);
		void setPicture(string a);
		void setWebsiteLink(string a);
		void setWebsiteDescription(string a);
		void addClique(string a);
		//inpectors
		string getLastName();
		string getFirstName();
		string getUserid();
		string getPicture();
		string getWebsiteLink();
		string getWebsiteDescription();
		string getClique(int a);
		//member functions		
		// textOutput - writes to a textfile about the attributes of the socailite
		// @param &txt - the text file the function will output to
		void textOutput(ostream &txt);
		// htmlOutput - creates a website based on the socialite (like a share page)
		// @param &html - html file that will be written in by the function
		void htmlOutput(ostream &html);
		// numCliques - returns the number of cliques the soicalite is apart of
		// return - number of cliques socialite is apart of
		int numCliques();

	private:
		string last_name;
		string first_name;
		string userid;
		string picture;
		string website_link;
		string website_discription;
		vector<string> cliques_;
};

#endif

