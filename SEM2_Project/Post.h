#pragma once

#include <iostream>
#include "../SEM2_Project/Date.h"
#include "../SEM2_Project/Comment.h"
#include "../SEM2_Project/User.h"
using namespace std;
class User;

class Post {

	string Post_ID;
	string Description;
	int Likes;
	string* ListOfUserLiked;
	Date SharedDate;
	Comment** Comments;
	int commentnum;

public:
	void PostComment(string, User&);
	Post(string, string,int,int,int);
	Post();
	~Post();
	void ViewLikedList();
	Date GetDate();
	string GetID();
	string GetDes();
	void PrintPost();
	void PrintComment();
	template <class T>
	void ViewPost(T& poster) {
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		cout << "  " << poster.GetName() << "         Posted on "; SharedDate.Print();
		PrintPost();
		cout << "------------------------------------------------------------------------------------------------------" << endl;
	}
	 virtual void View(User&);
	 void Addlikes(string);

};