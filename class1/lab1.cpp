#include <iostream>
using namespace std;
class T {
	int first;
	int second;
	int cost;
public:
	void Read()
	{
		cout << "Введите цену: ";
		cin >> first;
		cout << endl << "Введите кол-во: ";
		cin >> second;
		Init();
	}
	void Init()
	{
		if ((first <= 0) or (second <= 0))
		{
			cout << "Введено неправильное число, программа завершена!" << endl;
			abort();

		}
		else
		{
			cout << "Введены правильные числа, считаем..." << endl;
			cos();
		}
	}
	void cos() {
		cost = first * second;
	};

	void show() {
		cout << "cost=" << cost<<endl;

	}
};
void main() {
	setlocale(0,"rus");
	T array[5];
	for (int i = 0; i < 5; i++)
	{
		array[i].Read();
		array[i].cos();
		array[i].show();
	}
}
