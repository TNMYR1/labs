#include "mars.h"
#include <iostream>
#include <string> 
using namespace std;

mars make_mars()
{
	string s;
	string i;
	float d;
	cout << "Vvedite otpravlenie: ";
	cin >> s;
	cout << "Vvedite naznachenie ";
	cin >> i;
	cout << "Vvedite time: ";
	cin >> d;
	mars t(s, i, d);
	return t;
}

void print_mars(mars t)
{
	t.show();
}

int main()
{
	mars t1;
	t1.show();
	mars t2("ottuda", "tuda", 15000);
	t2.show();
	mars t3 = t2;
	t3.set_otp("zdec");
	t3.set_naz("ne zdec");
	t3.set_time(5000.0);
	print_mars(t3);
	t1 = make_mars();
	t1.show();
	return 0;
}