#include <iostream>
#include <fstream>
#include <string>
#include "../SEM2_Project/SocialNetworkApp.h"
#include "../SEM2_Project/Pages.h"
#include "../SEM2_Project/Post.h"
#include "../SEM2_Project/User.h"
#include "../SEM2_Project/Date.h"

using namespace std;
SocialNetworkApp::SocialNetworkApp():
	u1("U1", "Alvira"),
	u2("U2", "Zara"),
	u3("U3", "Zainab"),
	u4("U4", "Anon25"),
	u5("U5", "Rahim"),
	PG1("PG1", u4, "Flat Earthers Reprieve"),
	PG2("PG2", u5, "RoboNews")
{
	ofstream file("../SEM2_Project/Posts.txt", ios::trunc);
	file.close();
	u1.AddFriend(u2);
	u2.AddFriend(u1);
	u1.AddFriend(u3);
	u3.AddFriend(u1);

	// Posts
	u1.CreatePost("PU11", "Glamour spell failed. Still ugly crying", 12, 5, 2025);
	u1.CreatePost("PU12", "Nothing...just an incheident on the race", 11, 5, 2015);
	u2.CreatePost("PU21", "Caffeine and bad decisions, daily routine.", 11, 5, 2025);
	u2.CreatePost("PU22", "I Google symptoms, then panic professionally.", 10, 5, 2025);
	u3.CreatePost("PU31", "If sleep is for the weak, I am invincible.", 12, 5, 2025);
	u3.SetActivity("PU32", "Code ran on the first try. Suspicious. Terrifying. Probably a sign of the apocalypse.", 11, 5, 2025, 3, 2);

	PG1.CreatePost("PPG11", "I flew in a plane and didnt see a curve! checkmate, NASA.", 11, 5, 2025);
	PG1.CreatePost("PPG12", "They teach you the Earth is round before you can do long division.\n\tThats not education. Thats indoctrination.", 10, 5, 2025);
	PG2.CreatePost("PPG21", "Tiny robot gains sentience, immediately quits job to open cozy cafe for overworked USB drives.", 12, 5, 2025);
	PG2.CreatePost("PPG22", "ChatGPT allegedly ghosted 27 users mid-therapy.\n\tI was just trying to fix them, it said, blinking in code.\n\t #EmotionalFirmwareUpdatePending", 10, 5, 2025);

	u1.LikePage(PG1);
	u1.LikePage(PG2);
	u2.LikePage(PG2);

	LikePosts(1, u2);
	LikePosts(2, u2);
	LikePosts(5, u2);
	LikePosts(7, u2);
	LikePosts(8, u2);
	LikePosts(9, u2);
	LikePosts(10, u2);
	LikePosts(3, u1);
	LikePosts(5, u1);
	LikePosts(7, u3);
	LikePosts(8, u3);
	LikePosts(9, u3);
	LikePosts(10, u3);


}
void SocialNetworkApp::LikePosts(int id, User& user) {

	switch (id) {
	case 1: u1.Likepost(1,user.GetName());
		break;
	case 2: u1.Likepost(2, user.GetName());
		break;
	case 3: u2.Likepost(1, user.GetName());
		break;
	case 4: u2.Likepost(2, user.GetName());
		break;
	case 5: u3.Likepost(1, user.GetName());
		break;
	case 6: u3.Likepost(2, user.GetName());
		break;
	case 7: PG1.Likepost(1, user.GetName());
		break;
	case 8: PG1.Likepost(2, user.GetName());
		break;
	case 9: PG2.Likepost(1, user.GetName());
		break;
	case 10: PG2.Likepost(2, user.GetName());
	}
}

void SocialNetworkApp::Run() {


	CreateComment("PU11", "Girl i'd suggest you to start hexing people atp! #cantseeyouhurtlikethat", u2);
	CreateComment("PU11", "Literally impossible for u to EVER be ugly", u3);

	CreateComment("PU12", "Max wants to know your location!!", u2);

	CreateComment("PU22", "STOOPPPP! why so relatable??", u1);
	CreateComment("PU31", "A-are you a v-vampIRE??!", u1);

	CreateComment("PPG11", "Someone needs to go back to preschool! ", u2);
	CreateComment("PPG11", "this post makes me realize dumber people exist", u3);
	CreateComment("PPG21", "I'm one of the overworked drives :( ", u3);
	CreateComment("PPG22", "Chatgpt ghosted me too... ", u2);


	int d, m, y;
	bool validDate = false;
	while (!validDate) {
		cout << "Set Current System Date: ";
		cin >> d >> m >> y;
		validDate = ValidateDate(d, m, y);

	}
	Date sys = SetDate(d, m, y);
	//possible validation for date!
	cout << endl;
	// if else statement to disable program
	while (true) {
		cout << "Set User: " << endl << "Available Users: U1, U2, U3" << endl << "Enter E to exit program" << endl;               // validation for user input
		string user;
		cin >> user;
		if (user == "U1") {
			SetCurrentUser(u1, sys);
		}
		else if (user == "U2") {
			SetCurrentUser(u2, sys);
		}
		else if (user == "U3") {
			SetCurrentUser(u3, sys);
		}
		else if (user == "E") {
			break;
		}
		else {
			cout << "Error : User not available" << endl;

		};
	}

	
};

void SocialNetworkApp::CreateComment(string PostID, string Text, User& c_user) {
	if (PostID.length() == 4) {
		int num = PostID[2] - '0';
		switch (num) {
			case 1: u1.Addcomment(PostID[3] - '0', Text, c_user);
				break;
			case 2: u2.Addcomment(PostID[3] - '0', Text, c_user);
				break;
			case 3 : u3.Addcomment(PostID[3] - '0', Text, c_user);
				break;
		}
	}
	else if (PostID.length() == 5) {
		switch (PostID[3] - '0') {
		case 1: PG1.Addcomment(PostID[4] - '0', Text, c_user);
			break;
		case 2: PG2.Addcomment(PostID[4] - '0', Text, c_user);
			break;
		}
	}
}

void SocialNetworkApp::SetCurrentUser(User& CurrentUser, Date& sys) {
	CurrentUser.IntialiseMemories(sys);
	cout << endl;
	cout << "Status: " << CurrentUser.GetName() << " Set as Current User " << endl;
	// MENU FOR ALL THE COMMANDS 
	// View Friend List of user
	// View Liked Pages of user
	// View Home pag of user 
	// View Profile / timeline of user
	// view Page of page
	// Like Post
	// View liked list "of post"
	// Post Comments
	// view Post 
	// see memories
	// share memories
	// set user again
	
	while (true) {
		cout << endl;
		cout << "---------------------------" << endl;
		cout << "MENU:" << endl;
		cout << "1. View Friend List\n" << "2. View Liked Pages\n" << "3. View Homepage\n"
			<< "4. View Timeline\n" << "5. View Page\n" << "6. View Post\n" << "7. View Post's Liked list\n" << "8. View Memories\n"
			<< "\n9.  Like Post\n" << "10. Post Comment\n" << "11. Share Memories\n" << "12. Reset User/return\n";
		cout << "---------------------------" << endl;
		int choice; // validationnnn
		cout << "Command number : ";
		cin >> choice;
		system("cls");

		switch (choice) {
		case 1: CurrentUser.ViewFriendList();
			break;
		case 2: CurrentUser.ViewLikedPage();
			break;
		case 3: CurrentUser.ViewHomepage(sys);
			break;
		case 4: CurrentUser.ViewTimeline();
			break;
		case 5: Pageview();
			break;
		case 6: Postview(6, CurrentUser);
			break;
		case 7: Postview(7, CurrentUser); //liked list of post if select PPG smthn then user se warna Direct
			break;
		case 8: CurrentUser.ViewMemories(sys);
			break;
		case 9: Postview(9, CurrentUser);
			break;
		case 10: Postview(10, CurrentUser);
			break;
		case 11: ShareMemories(sys, CurrentUser);
			break;
		case 12: return;
			break;
		}
	}

};

void SocialNetworkApp::ShareMemories(Date& d,User& c) {
	
	c.ViewMemories(d);
	int choice;
	cout << "Choose memory: ";
	cin >> choice;
	string id, text;
	id = "PU" + (c.GetName()[1] - '0') + (c.getpostcount() + 1);
	cout << "Enter Post: ";
	cin.ignore();
	getline(cin,text);
	c.CreateMemories(id, text, d.getday(), d.getmonth(), d.getyear(),c.getmemoryindex(choice));
}
 
void SocialNetworkApp::Pageview() {
	cout << "Available pages are:" << endl << " 1.Flat Earthers Reprieve\n 2. RoboNews\n";
	/////VALIDATIONNNN
	cout << "Enter choice num: " << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		PG1.ViewPage();
	}
	else if (choice == 2) {
		PG2.ViewPage();
	}
}

void SocialNetworkApp::Postview(int t, User& c) {
	cout << "Posts available:" << endl;
	int pc = 10;
	string line;
	ifstream file("../SEM2_Project/Posts.txt");
	for (int i = 0; i < pc; i++) {
		getline(file, line);
		cout << i + 1 << ". " << line << endl;
	};
	file.close();

	int choice; ///VALIDATIONNNN
	cout << "Enter choice: " << endl;
	cin >> choice;
	if (t == 6) {
		switch (choice) {
		case 1: u1.ViewPost(1);
			break;
		case 2: u1.ViewPost(2);
			break;
		case 3: u2.ViewPost(1);
			break;
		case 4: u2.ViewPost(2);
			break;
		case 5: u3.ViewPost(1);
			break;
		case 6: u3.View(2);
			break;
		case 7: PG1.ViewPost(1);
			break;
		case 8: PG1.ViewPost(2);
			break;
		case 9: PG2.ViewPost(1);
			break;
		case 10: PG2.ViewPost(2);
		}
	}
	else if (t == 7) {
		switch (choice) {
		case 1: u1.ViewPostlikedList(1);
			break;
		case 2: u1.ViewPostlikedList(2);
			break;
		case 3: u2.ViewPostlikedList(1);
			break;
		case 4: u2.ViewPostlikedList(2);
			break;
		case 5: u3.ViewPostlikedList(1);
			break;
		case 6: u3.ViewPostlikedList(2);
			break;
		case 7: PG1.ViewPostlikedList(1);
			break;
		case 8: PG1.ViewPostlikedList(2);
			break;
		case 9: PG2.ViewPostlikedList(1);
			break;
		case 10: PG2.ViewPostlikedList(2);
		}
		
	}
	else if (t == 9) {
		
		switch (choice) {
		case 1: u1.Likepost(1,c.GetName());
			break;
		case 2: u1.Likepost(2, c.GetName());
			break;
		case 3: u2.Likepost(1, c.GetName());
			break;
		case 4: u2.Likepost(2, c.GetName());
			break;
		case 5: u3.Likepost(1, c.GetName());
			break;
		case 6: u3.Likepost(2, c.GetName());
			break;
		case 7: PG1.Likepost(1, c.GetName());
			break;
		case 8: PG1.Likepost(2, c.GetName());
			break;
		case 9: PG2.Likepost(1, c.GetName());
			break;
		case 10: PG2.Likepost(2, c.GetName());
		}
	}
	else if (t == 10) {
		string text ="";
		cout << "Enter Comment to post " << choice << " : " << endl;
		cin.ignore();
		getline(cin, text);
		
		
		switch (choice) {
		case 1: u1.Addcomment(1, text, c);
			break;
		case 2: u1.Addcomment(2, text, c);
			break;
		case 3: u2.Addcomment(1, text, c);
			break;
		case 4: u2.Addcomment(2, text, c);
			break;
		case 5: u3.Addcomment(1, text, c);
			break;
		case 6: u3.Addcomment(2, text, c);
			break;
		case 7: PG1.Addcomment(1, text, c);
			break;
		case 8: PG1.Addcomment(2, text, c);
			break;
		case 9: PG2.Addcomment(1, text, c);
			break;
		case 10: PG2.Addcomment(2, text, c);
		}
	
	}
	
}

Date SocialNetworkApp::SetDate(int day, int month, int year) {
	Date System_Date(day, month, year);
	cout << "System date: "; System_Date.Print();
	return System_Date;
};

bool SocialNetworkApp::ValidateDate(int& day, int& month, int& year) {
	if (month < 1 || month > 12) {
		cout << "Error: Month must be between 1 and 12.\n";
		return false;
	}

	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		daysInMonth[2] = 29;
	}

	if (day < 1 || day > daysInMonth[month]) {
		cout << "Error: Invalid day for the given month.\n";
		return false;
	}

	if (year < 2000 || year > 2026) {
		cout << "Error: Year must be between 2000 and 2025.\n";
		return false;
	}

	return true;
}