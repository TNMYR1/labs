#include <iostream>
#include <string>
using namespace std;
class mars
{
	string otp;
	string naz;
	float time;
public:
	mars();

	mars(string, string, float);
	mars(const mars& obj);
	~mars();
	string get_otp();
	void set_otp(string);
	string get_naz();
	void set_naz(string);
	float get_time();
	void set_time(float);
	void show();
};
