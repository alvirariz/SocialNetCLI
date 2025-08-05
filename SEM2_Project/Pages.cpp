#include <iostream>
#include <fstream>
#include "../SEM2_Project/Pages.h"
using namespace std;

Pages::Pages(string id, User& Own, string t) { // there might be a need for assignment operator
	Pages_ID = id;
	Owner = &Own;
	Name = t;
	PostList = nullptr;
	Postcount = 0;
	NumOfLike = 0;
}
void WriteFile1(string val) {

	ofstream file("../SEM2_Project/Posts.txt", ios::app);
	file << val << endl;


	file.close();
}
void Pages::CreatePost(string pid, string text, int d, int m, int y) {
	Post** temp = new Post * [Postcount + 1];
	for (int i = 0; i < Postcount; i++) {
		temp[i] = PostList[i];
	}
	temp[Postcount] = new Post(pid, text,d,m,y);
	delete[] PostList;
	PostList = temp;
	Postcount++;

	WriteFile1(pid);
}

Pages::~Pages() {
	if (PostList != nullptr) {
		for (int i = 0; i < Postcount; i++) {
			delete PostList[i];
		}
		delete[] PostList;
	}
	delete Owner;
}

string Pages::GetId() {
	return Pages_ID;
}
string Pages::GetName() {
	return Name;
}
int Pages::getpostcount() {
	return Postcount;
}

Post * Pages::GetPostList(int i) {
	return PostList[i];
}

void Pages::Addcomment(int i,string text,User& cmtr) {
	PostList[i-1]->PostComment(text, cmtr);
}

void Pages::ViewPage() {
	for (int i = 0; i < Postcount; i++) {
		PostList[i]->ViewPost(*this);
	}
}

void Pages::ViewPost(int i) {
	PostList[i-1]->ViewPost(*this);
}

void Pages::Likepost(int i, string user) {
	PostList[i - 1]->Addlikes(user);
}
void Pages::ViewPostlikedList(int i) {
	PostList[i - 1]->ViewLikedList();
}