#include <iostream>
#include "./../SEM2_Project/Post.h";
Post::Post(string id = "", string des = "", int d = 0,int m=0,int y=0) {
	Post_ID = id;
	Description = des;
	Likes = 0;
	ListOfUserLiked = nullptr;
	Comments = nullptr;
	SharedDate = Date(d, m, y);
	commentnum = 0;
};
Post::Post() {
	Post_ID = "";
	Description = "";
	Likes = 0;
	ListOfUserLiked = nullptr;
	Comments = nullptr;
	SharedDate = Date(0, 0, 0);
	commentnum = 0;
};
Date Post::GetDate() {
	return SharedDate;
}
string Post::GetID() {
	return Post_ID;
}

void Post::PostComment(string text, User& Cmtr) {
	if (commentnum <= 10) { // only 10 comments allowed
		Comment** temp = new Comment * [commentnum + 1];
		for (int i = 0; i < commentnum; i++) {
			temp[i] = Comments[i];
		}
		temp[commentnum] = new Comment(Post_ID, text, Cmtr.GetId(), Cmtr.GetName());
		delete[] Comments;
		Comments = temp;
		commentnum++;
	}
	
}

Post:: ~Post() {
	delete[] ListOfUserLiked;
	
	if (Comments != nullptr) {
		for (int i = 0; i < commentnum; i++) {
			delete Comments[i];
		}
		delete[] Comments;
	}
}
void Post::PrintPost() {
	cout<<"\n\t" << Description << endl;
	cout << endl;
	for (int i = 0; i < commentnum; i++) {
		 Comments[i]->Displaycomment();
	}
}
void Post::PrintComment() {
	for (int i = 0; i < commentnum; i++) {
		Comments[i]->Displaycomment();
	}
}

void Post::Addlikes(string user) {
	string* temp = new string[Likes + 1];
	for (int i = 0; i < Likes; i++) {
		temp[i] = ListOfUserLiked[i];
	}
	temp[Likes] = user;
	delete[] ListOfUserLiked;
	ListOfUserLiked = temp;
	Likes++;

}

void Post::ViewLikedList() {
	cout << "List of People Liked: " << endl;
	for (int i = 0; i < Likes; i++) {
		cout << i+1 <<". " << ListOfUserLiked[i] << endl;
	}
}

string Post::GetDes() {
	return Description;
}
 void Post:: View(User& poster) {
	 cout << "------------------------------------------------------------------------------------------------------" << endl;
	 cout << "  " << poster.GetName() << "         Posted on "; SharedDate.Print();
	 PrintPost();
	 cout << "------------------------------------------------------------------------------------------------------" << endl;
};