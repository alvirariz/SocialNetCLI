#pragma once
#pragma once
#include <iostream>
#include "../SEM2_Project/Post.h"
#include "../SEM2_Project/User.h"
using namespace std;
class Activity : public Post {
	string Type[4]= { "Feeling","Thinking about","Making","Celebrating" };
	string Value[4][3] = { {"Happy","Sad","Excited"},{"Life","Future","Meaning of Life"},{"Money","Art","Memories"},{"A Birthday","Halloween", "Success"} };
	int ValueIndex;
	int TypeIndex;
public:
	Activity();
	~Activity() {};
	Activity(string, string, int, int, int, int, int);
	 void View(User &) override;
};