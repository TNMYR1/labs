#include "mars.h" 
#include <iostream>
#include <string> 
using namespace std;
//конструктор без параметров
mars::mars()
{
	otp = "";
	naz = "";
	time = 0;
	cout << "Constructor bez parametrov dlia objecta: " << this << endl;
}
//конструктор с параметрами
mars::mars(string N, string K, float S)
{
	otp = N;
	naz = K;
	time = S;
	cout << "Constructor s parametrami dlia objecta: " << this << endl;
} //деструктор
mars::mars(const mars& obj)
{
	this->otp = obj.otp;
	this->naz = obj.naz;
	this->time = obj.time;
}
mars::~mars()
{
	cout << "Destructor dlia objecta: " << this << endl;
} //селекторы 
string mars::get_otp()
{
	return otp;
}
string mars::get_naz()
{
	return naz;
}
float mars::get_time()
{
	return time;
}
//модификаторы 
void mars::set_otp(string N)
{
	otp = N;
}
void mars::set_naz(string K)
{
	naz = K;
}
void mars::set_time(float S)
{
	time = S;
} //метод для просмотра атрибутов
void mars::show()
{
	cout << "otpravlenie :" << otp << endl;
	cout << "naznachenie :" << naz << endl;
	cout << "time :" << time << endl;
}