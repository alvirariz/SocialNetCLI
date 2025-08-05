#pragma once						
#include <iostream>
#include "../SEM2_Project/Post.h"
#include "../SEM2_Project/User.h"
using namespace std;
class User;
class Post;

class Pages {
	string Pages_ID;
	User * Owner;
	string Name;
	Post** PostList;
	int Postcount;
	int NumOfLike;

public:
	Pages(string id, User& Own, string t);
	~Pages();
	void CreatePost(string pid, string text,int,int,int);
	void ViewPage();
	void ViewPost(int);
	string GetName();
	string GetId();
	int getpostcount();
	Post * GetPostList(int);
	void Addcomment(int, string, User&);
	void Likepost(int, string);
	void ViewPostlikedList(int);
};