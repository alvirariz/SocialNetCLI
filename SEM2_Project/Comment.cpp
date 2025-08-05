#include <iostream>
#include "./../SEM2_Project/Comment.h"
using namespace std;
Comment::Comment(string id, string txt, string c_id, string c_nm) {
	Post_ID = id;
	Description = txt;
	CommenterID = c_id;
	CommenterName = c_nm;
}

void Comment::Displaycomment() {
	cout << "\t\t";
	cout << CommenterName << ": " << Description << endl;
}
