#pragma once
#include <iostream>
using namespace std;		
class Comment {		
	string Post_ID;
	string Description;
	string CommenterID;
	string CommenterName;
public:
	Comment(string id, string txt, string c_id, string c_nm);
	void Displaycomment();
	~Comment() {};
}; 
