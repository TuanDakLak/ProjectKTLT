#include "global.h"

void nhapngay(Student*& s)
{
	cout << "Input date: ";
	cin >> s->dateOfBirth.ngay;
	cout << "Input month: ";
	cin >> s->dateOfBirth.thang;
	cout << "Input year: ";
	cin >> s->dateOfBirth.nam;
}

bool checkTime(Date a, Date b)
{
	if (a.thang < b.thang) return false;
	else if (a.thang > b.thang) return true;
	else if (a.thang == b.thang) {
		if (a.ngay < b.ngay) return false;
		return true;
	}

}

