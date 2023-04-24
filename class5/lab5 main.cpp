#include "Object.h"
#include "Pair.h" 
#include "Hipotenuse.h" 
#include "Vector.h" 
#include <string> 
#include <iostream>
using namespace std;
void main() { 
	Vector v(5);//вектор из 5 элементов 
	Pair a;//объект класса Pair 
	cin>>a; 
	Hipo b;// объект класса  Hipo
	cin>>b; 
	Object*p=&a;//ставим указатель на объект класса Pair 
	v.Add(p);//добавляем объект в вектор 
	p=&b;//ставим указатель на объект класса 
	v.Add(p); //добавляем объект в вектор
	cout<<v;//вывод вектора
}