#pragma once
#include "Pair.h"
//класс Lorry наследуется от класса Car
class Hipo :
	public Pair
{
public:
	Hipo(void);//конструктор без параметров 
public: ~Hipo(void);//деструктор 
	  Hipo(int, int, int);//конструктор с параметрами 
	  Hipo(const Hipo&);//конструктор копирования 
	  void Show();
	  int Get_hipot() { return hipot; }//модификатор
	  void Set_hipot(int);//селектор
	  Hipo& operator=(const Hipo&);//операция присваивания

	  friend istream& operator>>(istream& in, Hipo& l);//операция ввода 
	  friend ostream& operator<<(ostream& out, const Hipo& l); //операция вывода
protected:
	int hipot;//атрибут грузоподъемность
};