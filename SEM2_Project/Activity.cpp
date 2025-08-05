#include <iostream>
#include "../SEM2_Project/Activity.h"
using namespace std;

Activity::Activity()
	:Post()
{
	ValueIndex = 0;
	TypeIndex = 0;
}
Activity::Activity(string id, string des, int d, int m , int y , int t, int v)
	:Post(id, des, d, m, y)
{
	ValueIndex = v;
	TypeIndex = t;

}

void Activity::View(User& poster) {
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cout << "  " << poster.GetName() <<" is " <<Type[TypeIndex] <<" " << Value[TypeIndex][ValueIndex] << "          Posted on "; Post::GetDate().Print();

	PrintPost();
	cout << "------------------------------------------------------------------------------------------------------" << endl;
}
