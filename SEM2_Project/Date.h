#pragma once
#include <iostream>

using namespace std;
class Date {
	int Day;
	int Month;
	int Year;
public:
	Date(int, int, int);
	Date();
	~Date() {};
	void Print();
	
	int getyear();
	int getmonth();
	int getday();

};