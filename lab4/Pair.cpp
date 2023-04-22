#include "Pair.h"
//конструктор без параметров 
Pair::Pair(void) 
{
	; first=0; second=0;
} //деструктор
Pair::~Pair(void) { } 
//конструктор с параметрами 
Pair::Pair(int C,int P)
{ 
	 first=C; second=P; 
} //конструктор копирования 
Pair::Pair(const Pair& t)
{
	first = t.first;
	second = t.second;
}
	//модификаторы
void Pair::Set_first(int C) 
{
	first=C; 
} 
void Pair::Set_second(int P) 
{
	second=P; 
} 
//перегрузка операции присваивания
Pair& Pair::operator=(const Pair&c)
{
	if(&c==this)return *this; 
	second=c.second; 
	first=c.first;
	return *this; 
}
//глобальная функция для ввода
istream& operator>>(istream&in,Pair&c) 
{ 
	cout<<"\nfirst:";in>>c.first; 
	cout<<"\nsecond:";in>>c.second; 
	return in; 
} 
//глобальная функция для вывода 
ostream& operator<<(ostream&out,const Pair&c) 
{
	out<<"\nfirst: "<<c.first; 
	out<<"\nsecond : "<<c.second; 
	out<<"\n";
	return out;
}