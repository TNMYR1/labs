#include "Hipotenuse.h"
#include <math.h>
//конструктор без параметров
Hipo::Hipo(void):Pair() 
{ 
	hipot=0;
}
//дестрктор
Hipo::~Hipo(void) { } 
//конструктор с параметрами
Hipo::Hipo(int C, int P, int G):Pair(C,P)
{
	hipot= sqrt(C * C+ P * P);
} 
//конструктор копирования
Hipo::Hipo(const Hipo &L) 
{
	first=L.first;
	second=L.second;
}
//модификатор
void Hipo::Set_hipot(int G) 
{
	hipot=G; 
} 
//оперция присваивания 
Hipo& Hipo::operator=(const Hipo& l)
{
	if (&l == this)return *this;
	second = l.second;
	first = l.first;
	hipot = l.hipot;
	return *this;
}
	//операция ввода
	istream& operator>>(istream&in,Hipo&l) 
	{ 
		cout<<"\nfirst:";in>>l.first;
		cout<<"\nsecond:";in>>l.second;
		l.hipot = sqrt(l.first * l.first + l.second * l.second);
		return in; 
	}
	//операция вывода 
	ostream& operator<<(ostream& out, const Hipo& l)
	{
		out << "\nfirst : " << l.first;
		out << "\nsecond : " << l.second;
		out << "\nhipot : " << l.hipot;
		out << "\n";
		return out;
	}
	
void Hipo::Show() 
	{ 
	cout << "\nfirst : " << first; 
	cout << "\nsecond : " << second; 
	cout << "\nhipot : " << hipot;
	cout << "\n";
} 
