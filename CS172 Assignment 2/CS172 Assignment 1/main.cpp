//-----------------------------------------------------
// Program Name: Socialite Sharing Website
// Purpose: Simulate an social media platorm performing
//			a sharing of a link. 
// Coder: Abir Razzak
// Date: 4/15/17
// Last Modified: Abir Razzak, 5/3/17
//-----------------------------------------------------
#include "socialite.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//Ask user for the file name
	cout << "What's the name of the file you want to open? ";
	string input;
	cin >> input;

	//Open said file
	ifstream infile;
	infile.open(input);

	string curr_line; // Keeps track of current line program is reading
	int counter = 1; //Keeps track of line # for current socialite
	string first_name, last_name, user_id, img_link, share_link, description, clique; //Stores socialite attributes
	vector<socialite> socialites; //Create a list of all socialites on the file
	vector<string> cliques; //Create a list of cliques that current socialite belongs to

	while (getline(infile, curr_line)) {
		if (curr_line == "++++") {
			//"++++" indicates that current socialite is now over. Begin storing all the info on the socialite and get
			//ready to move onto the next socialite.

			//reset counter to zero (so that counter++ will set counter to 1 at the beginning of the next loop)
			counter = 0;
			//Add newly created socialite to a vector of socialites in the file
			socialites.push_back(socialite(first_name, last_name, user_id, img_link, share_link, description));
			//Now add all cliques that new socialite is apart of
			int j = socialites.size() - 1;
			for (string c : cliques) socialites[j].addClique(c);
			//Clear the cliques vector for next socialite
			cliques.clear();
		}
		if (counter > 6) {
			//Every line after the sixth line will contain the name of a clique
			cliques.push_back(curr_line); //Store name of clique to clique vector
			cout << "Added clique: " << curr_line << endl;
		}
		if (counter == 6) {
			//Sixth line of a socialite will contain the website description
			description = curr_line; //Store site description
			cout << "Description: " << description << endl;
		}
		if (counter == 5) {
			//Fifth line of a socialite will contain the website link
			share_link = curr_line; //Store the website link
			cout << "Website link set. \n";
		}
		if (counter == 4) {
			//Fourth line of a socialite will contain the link to the picture
			img_link = curr_line; //Store the picture link
			cout << "Picture set. \n";
		}
		if (counter == 3) {
			//Third line of a socialite will contain the last name
			last_name = curr_line; //Store last name
			cout << "Last Name: " << last_name << endl;
		}
		if (counter == 2) {
			//Second line of a socialite will contain the first name
			first_name = curr_line; //Store first name
			cout << "First Name: " << first_name << endl;
		}
		if (counter == 1) {
			//First line of a socialite will contain the userID
			user_id = curr_line; //Store user ID
			cout << "User ID: " << user_id << endl;		
		}
		
		counter++;
		
	}

	cout << "---------------------------------------\n"; //Pretty asthetics

	ofstream html;
	for (socialite i : socialites) {
		//Check every socialite that was saved into the vector and create an HTML document for each of them
		cout << i.getUserid() << "'s page has been created. \n";
		html.open(i.getUserid() + ".html"); //Name the HTML File after the userID of the user
		i.htmlOutput(html); //Creates the HTML file
		html.close();
	}

	return 0;
}