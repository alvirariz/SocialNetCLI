#pragma once

#include "../SEM2_Project/Date.h"
#include <iostream>
class Memory;
using namespace std;
class Pages;
class Post;


class User {
	string User_ID;
	string Name;
	User ** FriendList;
	int Friendcount;
	Pages ** Likedpages;
	int Pagecount;
	Post** PostList;
	int Postcount;
	int * memorylist; // stores teh integer of post that is a memory!
	int memorycount;
	

public:
	User(string id, string name);
	User();
	~User();
	void ViewHomepage(Date&);
	void ViewFriendList();
	void ViewLikedPage();
	void Addcomment(int, string, User&);
	void ViewTimeline();
	void ViewPost(int i);
	void View(int i);
	void SetActivity(string id, string des, int d, int m, int y, int t, int v);

	void ViewPostlikedList(int);
	void CreateMemories(string pid, string text, int d, int m, int y,int i); // automatically intialised
	void ViewMemories(Date& );
	void IntialiseMemories(Date& );
	void Likepost(int,string);


	void AddFriend(User&);
	void LikePage(Pages& obj);
	void CreatePost(string, string ,int,int,int);
	
	//getters and setters;
	string GetName();
	string GetId();
	int getpostcount();
	int getmemoryindex(int);
	

};