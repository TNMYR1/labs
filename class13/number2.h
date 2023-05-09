#pragma once
void Show(priority_queue<Time> q);

void Insert(priority_queue<Time>& q);

void DelElem(priority_queue<Time>& q);

void plusMinMax(priority_queue<Time>& q);




void number2()			
{					
	setlocale(0, "rus");
	Time temp;			
	priority_queue<Time> pq;	
	int size;
	cout << "Введите количество элементов в очереди: "; cin >> size;
	for (int i = 0; i < size; i++)
		pq.push(temp.randomGener());
	cout << "Полученная очередь:" << endl;
	Show(pq);
	cout << "Добавим значение очереди:" << endl;
	Insert(pq);
	cout << "Полученный очередь:" << endl;
	Show(pq);
	cout << "Удалим элемент по значению." << endl;
	DelElem(pq);
	cout << "Полученный очередь:" << endl;
	Show(pq);
	cout << "Добавим сумму min и max элементов к каждому элементу." << endl;
	plusMinMax(pq);
	cout << "Полученный очередь:" << endl;
	Show(pq);
	return;
}



void Show(priority_queue<Time> q)
{
	int j = 0;
	while (!q.empty())
	{
		cout << j++ << ". " << q.top() << endl;
		q.pop();
	}
}


void Insert(priority_queue<Time>& q)
{
	priority_queue<Time> temp(q);
	Time mid = 0;
	while (!temp.empty())
	{
		mid = mid + temp.top();
		temp.pop();
	}
}

void DelElem(priority_queue<Time>& q)
{
	Time key, k;
	priority_queue<Time> temp;
	cout << "Введите ключ для поиска: "; cin >> key;
	while (!q.empty())
	{
		k = q.top();
		if (key == k)
			q.pop();
		else

		{
			temp.push(k);
			q.pop();
		}
	}
	q.swap(temp);
}

void plusMinMax(priority_queue<Time>& q)
{
	Time k;
	Time loc_min = q.top(), loc_max = 0;
	priority_queue<Time> temp(q);
	while (!temp.empty())
	{
		k = temp.top();
		if (loc_max < k)
		{
			loc_max = k;
			temp.pop();
		}
		else if (loc_min > k)
		{
			loc_min = k;
			temp.pop();
		}
		else temp.pop();
	}
	cout << "min element: " << loc_min << endl;
	cout << "max element: " << loc_max << endl;
	temp.swap(q);
	while (!temp.empty())
	{
		k = temp.top();
		q.push(k + loc_min - loc_max);
		temp.pop();
	}
}