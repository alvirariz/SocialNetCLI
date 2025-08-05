#include <iostream>
#include <fstream>
#include "./../SEM2_Project/User.h"
#include "../SEM2_Project/Post.h"
#include "../SEM2_Project/Pages.h"
#include "../SEM2_Project/Memory.h"
#include "../SEM2_Project/Activity.h"
using namespace std;

User::User(string id = "", string name = "") {

	User_ID = id;
	Name = name;
	Friendcount = 0;
	Postcount = 0;
	FriendList = nullptr;
	Likedpages = nullptr;
	PostList = nullptr;
	memorylist = nullptr;
	memorycount = 0;

}

User::User() {
	User_ID = "";
	Name = "";
	Friendcount = 0;
	Postcount = 0;
	Pagecount = 0;
	FriendList = nullptr;
	Likedpages = nullptr;
	PostList = nullptr;
	memorylist = nullptr;
	memorycount = 0;
}


void User::AddFriend(User& obj) {
	User ** temp = new User *[Friendcount + 1];
	for (int i = 0; i < Friendcount; i++) {
		temp[i] = FriendList[i];
	}
	temp[Friendcount] = &obj;
	delete[] FriendList;
	FriendList = temp;
	Friendcount++;
}

void WriteFile(string val) {

	ofstream file("../SEM2_Project/Posts.txt",ios::app);
	file << val << endl;


	file.close();
}

void User::CreatePost(string pid, string text, int d, int m, int y) {
	Post** temp = new Post * [Postcount + 1];
	for (int i = 0; i < Postcount; i++) {
		temp[i] = PostList[i];
	}
	temp[Postcount] = new Post(pid,text,d,m,y);
	delete[] PostList;
	PostList = temp;
	Postcount++;
	WriteFile(pid);
}

void User::CreateMemories(string pid, string text, int d, int m, int y,int i) {
Post** temp = new Post * [Postcount + 1]; // make this llike activity!
	for (int j = 0; j < Postcount; j++) {
		temp[j] = PostList[j];
	}
	temp[Postcount] = new Memory(pid, text, d, m, y, *PostList[i]);
	delete[] PostList;
	PostList = temp;
	Postcount++;
	WriteFile(pid);
}


void User::SetActivity(string id, string des, int d, int m, int y, int t, int v) {
	Post** temp = new Post * [Postcount + 1];
	for (int i = 0; i < Postcount; i++) {
		temp[i] = PostList[i];
	}
	temp[Postcount] = new Activity (id, des, d, m, y,t,v);
	delete[] PostList;
	PostList = temp;
	Postcount++;
	WriteFile(id);

}

void User::LikePage(Pages& obj) {
	Pages ** temp = new Pages *[Pagecount + 1];
	for (int i = 0; i < Pagecount; i++) {
		temp[i] = Likedpages[i];
	}
	temp[Pagecount] = &obj;
	delete[] Likedpages;
	Likedpages = temp;
	Pagecount++;
}

User::~User() {
	delete[] FriendList;
	delete[] Likedpages;
	delete[] memorylist;

	if (PostList != nullptr) {
		for (int i = 0; i < Postcount; i++) {
			delete PostList[i];
		}
		delete[] PostList;
	}

	FriendList = nullptr;
	PostList = nullptr;
	Likedpages = nullptr;
	memorylist = nullptr;
}

string User::GetName() {
	return Name;
}
string User::GetId() {
	return User_ID;
}


void User::ViewFriendList() {
	cout << endl;
	cout << Name << "'s Friend List: " << endl;
	for (int i = 0; i < Friendcount; i++) {
		
		cout << FriendList[i]->GetId() << " - " << FriendList[i]->GetName() << endl;
	}
}

void User::ViewLikedPage() {
	cout << endl;
	cout << Name << "'s Liked Pages: " << endl;
	for (int i = 0; i < Pagecount; i++) {

		cout << Likedpages[i]->GetId() << " - " << Likedpages[i]->GetName() << endl;
	}
}

int User::getpostcount() {
	return Postcount;
}

bool CheckDate(Date& p_date, Date& sys_Date) {
	if (p_date.getyear() == sys_Date.getyear()) {
		if (p_date.getday() == sys_Date.getday() || p_date.getday() == (sys_Date.getday() - 1)) {
			return true;
		}
	}
	return false;
}

void User::ViewHomepage(Date& Currentdate){
	cout << "\n HOMEPAGE: " << endl;
	Date dt;
	int pc =0;
	for (int i = 0; i < (Friendcount); i++) {
		pc = FriendList[i]->getpostcount(); // POAT COUNT 2 MEAN 0 ND 1
		for(int j =0; j < pc; j++){
			dt = FriendList[i]->PostList[j]->GetDate();
			if (CheckDate(dt,Currentdate)) {
				FriendList[i]->PostList[j]->View(*FriendList[i]);
			}
			cout << endl;
		}
	}

	for (int i = 0; i < (Pagecount); i++) {
		for (int j = 0; j < (Likedpages[i]->getpostcount()); j++) {
			dt = Likedpages[i]->GetPostList(j)->GetDate();
			if (CheckDate(dt, Currentdate)) {
				Likedpages[i]->GetPostList(j)->ViewPost(*Likedpages[i]);
			}
			cout << endl;
		}
	}
}

void User::Addcomment(int i, string text, User& c_user) {
	PostList[i-1]->PostComment(text, c_user);
}
void User::ViewTimeline() {
	cout << "TIMELINE: " << endl;
	for (int i = 0; i < Postcount; i++) {
		PostList[i]->View(*this);
	}
}

void User:: ViewPost(int i) {
	PostList[i-1]->ViewPost(*this);
}
void User::View(int i) {
	PostList[i-1]->View(*this);
}

void User::Likepost(int i, string user) {
	PostList[i - 1]->Addlikes(user);
}

void User::ViewPostlikedList(int i) {
	PostList[i - 1]->ViewLikedList();
}

void User::IntialiseMemories(Date& sys) {
	for (int i = 0; i < Postcount; i++) {
		if (PostList[i]->GetDate().getyear() < sys.getyear()) {
			int* temp = new int[memorycount + 1];
			for (int j = 0; j < memorycount; j++) {
				temp[i] = memorylist[i];
			}
			temp[memorycount] = i;
			delete[] memorylist;
			memorylist = temp;
			memorycount++;

		}
	}
}

void User::ViewMemories(Date& sys) {
	cout << "Memories: " << endl;
	for (int i = 0; i < memorycount; i++) {
			cout << "Memory num: " << i + 1 << endl ;
			PostList[memorylist[i]]->ViewPost(*this);
	}
}
int User::getmemoryindex(int i) {
	return memorylist[i - 1];
}