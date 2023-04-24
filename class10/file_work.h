#include "Timess.h" 
#include <iostream>
#include <fstream> 
#include <string> 
using namespace std;

int del_file(const char* f_name, Times qwe) {
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)return -1;//ошибка открытия файла 
	int i = 0,c,d; Times p;
	c = qwe.get_min();
	d = qwe.get_sec();
	while (stream >> p)//пока нет конца файла выполняем чтение объекта 
	{ 
//если прочитан признак конца файла,то выход из 
		if (stream.eof())break; 
		i++; 
		int a, b;
		a = p.get_min();
		b = p.get_sec();
		//если номер объекта не равен k, то записыва
		if ((a == c) && (b == d))
			i;
		else temp << p;
	} //закрыть файлы 
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл 
	rename("temp", f_name);// переименовать temp
	return (i);//количество прочитанных
	}
int makes_file(const char* f_name) 
{ 
	fstream stream(f_name,ios::out|ios::trunc);//открыть для записи 
	if(!stream)return -1;//ошибка открытия файла 
	int n; 
	Times p; 
	cout<<"N?";
	cin>>n; 
	for(int i=0;i<n;i++ )
	{
		cin>>p;//ввод атрибутов объекта из стандартного потока
		 stream<<p<<"\n";//запись объекта в файловый
	} 
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}
int prints_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)return -1;//ошибка открытия файла 
	Times p;
	int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}
int add_file(const char* f_name, int k, Times pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name,ios::in);//открыть для чтения
	if(!stream)return -1;//ошибка открытия файла 
	Times p; int i=0, l=0; 
	while(stream>>p)
	{
		if (stream.eof())break; i++; if (i == k) {
			temp << pp;//записать в temp новую запись
			l++;
		} temp<<p;
	} 
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp",f_name); 
	return l;//количество добавленных
}
int add_end(const char* f_name, Times pp) {
	fstream stream(f_name, ios::app);//открыть для добавления 
	if(!stream)return -1;//ошибка открытия файла 
	stream<<pp; //записать новую запись 
	return 1; 
}
int change_file(const char* f_name) {
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)return -1;//ошибка открытия файла 
	Times p; int i = 0; Times qwe;
	qwe.set_min(1);
	qwe.set_sec(30);
	while (stream >> p)//пока нет конца файла выполняем чтение объекта 
	{
		if (stream.eof())break;
		i++;
		p=p - qwe;
		temp << p;
	}
		stream.close();
		temp.close();
		remove(f_name);
		rename("temp", f_name);
		return i;//количество элементов 
}