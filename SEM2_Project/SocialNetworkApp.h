#pragma once
#include <iostream>
#include "./../SEM2_Project/Date.h"
#include "./../SEM2_Project/Pages.h"
#include "./../SEM2_Project/User.h"
using namespace std;
class SocialNetworkApp {
	Pages PG1, PG2;
	User u1,u2,u3,u4, u5;
	Date System_Date;
public:
	SocialNetworkApp();
	~SocialNetworkApp() {};
	void Run();
	void SetCurrentUser(User&, Date&);
	Date SetDate(int,int,int);
	void Pageview();
	void Postview(int,User&);
	void CreateComment(string, string, User&);
	void LikePosts(int,User&);
	void ShareMemories(Date& ,User&);
	bool ValidateDate(int& day, int& month, int& year);

};