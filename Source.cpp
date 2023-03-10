#ifndef __Source__
#define __Source__

#include"Header.h"

int main()
{
	#ifdef _DEBUG
		_CrtMemState _ms;
		_CrtMemCheckpoint(&_ms);
	#endif // DEBUG


	setlocale(LC_ALL, "Rus");

	DbLinkList<int> lst;
	int data = -1;
	int index = -1;
	int ind = -1;

	do // новый вариант диалога с пользователем
	{
		cout << endl << "Функции работы с коллекцией:" << endl;
		cout << "1) Добавление элементов в начало списка;" << endl;
		cout << "2) Добавление элементов в конец списка;" << endl;
		cout << "3) Добавление элементов по индексу;" << endl;
		cout << "4) Удаление элемента с конца списка;" << endl;
		cout << "5) Удаление элемента с начала списка;" << endl;
		cout << "6) Удаление элемента по индексу;" << endl;
		cout << "7) Удаление элемента по значению;" << endl;
		cout << "8) Очистка списка;" << endl;
		cout << "9) Получение элемента списка по индексу;" << endl;
		cout << "10) Вывести весь список;" << endl;
		cout << "11) Развернуть список (обратный порядок);" << endl;
		cout << "0) Выход из программы." << endl;
		try
		{
			cout << endl << "Введите номер функции:" << endl;
			cin >> index;
			if (index < 0 || index > 11 || !cin)
			{
				index = 'q';
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		catch (...)
		{
			cout << endl << "Некорректный ввод! Повторите ввод." << endl;
			throw;
		}
		switch (index)
		{
			case 0:
				cout << endl << "Инициализирован выход из программы." << endl;
				break;
			case 1:
				cout << endl << "Добавление элементов в начало списка:" << endl;
				cout << "Введите элементы:" << endl;
				do
				{
					cin >> data;
					if (cin)
						lst.push_front(data);
					else
						break;
				} while (true);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << lst;
				break;
			case 2:
				cout << endl << "Добавление элементов в конец списка:" << endl;
				cout << "Введите элементы:" << endl;
				do
				{
					cin >> data;
					if (cin)
						lst.push_back(data);
					else
						break;
				} while (true);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << lst;
				break;
			case 3:
				cout << endl << "Добавление элементов по индексу:" << endl;
				cout << "Введите индексы и соответствующие им значения:" << endl;
				do
				{
					cout << "Введите индекс: ";
					cin >> ind;
					if (!cin)
						break;
					cout << "Введите значение: ";
					cin >> data;
					if (cin)
						lst.insert(data, ind);
					else
						break;
				} while (true);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << lst;
				break;
			case 4:
				cout << endl << "Удаление элемента с конца списка:" << endl;
				cout << lst;
				lst.pop_back();
				cout << lst;
				break;
			case 5:
				cout << endl << "Удаление элемента с начала списка:" << endl;
				cout << lst;
				lst.pop_front();
				cout << lst;
				break;
			case 6:
				cout << endl << "Удаление элемента по индексу:" << endl;
				cout << "Введите индекс:";
				cin >> ind;
				if (cin)
				{
					cout << lst;
					lst.remove(ind);
					cout << lst;
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			case 7:
				cout << endl << "Удаление элемента по значению:" << endl;
				cout << "Введите значение:";
				cin >> data;
				if (cin)
				{
					cout << lst;
					lst.erase(data);
					cout << lst;
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			case 8:
				cout << endl << "Очистка списка:" << endl;
				lst.clear();
				break;
			case 9:
				cout << endl << "Получение элемента списка по индексу:" << endl;
				cout << "Введите индекс: " << endl;
				cin >> ind;
				if (cin)
					cout << "lst[" << ind << "] = " << lst[ind] << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			case 10:
				cout << lst;
				break;
			case 11:
				cout << endl << "Список до изменений:" << endl;
				cout << lst;
				cout << "Список после изменения порядка объектов:" << endl;
				lst.reverse();
				cout << lst;
				break;
		}
	} while (index != 0);

	lst.~DbLinkList(); // явно вызовем деструктор

	#ifdef _DEBUG
		_CrtMemDumpStatistics(&_ms);
		_CrtMemDumpAllObjectsSince(&_ms);
	#endif // DEBUG

	return 0;
}

#endif
