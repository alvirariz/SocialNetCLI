#include "../SEM2_Project/Date.h"
#include <iostream>
using namespace std;

Date::Date(int d, int m, int y) {
	Day = d;
	Month = m;
	Year = y;
}

Date::Date() :Day(0), Month(0), Year(0) {};

void Date::Print() {
	cout << Day << "/" << Month << "/" << Year << endl;
}
int Date::getday() {
	return Day;
}
int Date::getyear() {
	return Year;
}
int Date::getmonth() {
	return Month;
}