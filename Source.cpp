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

	do // ����� ������� ������� � �������������
	{
		cout << endl << "������� ������ � ����������:" << endl;
		cout << "1) ���������� ��������� � ������ ������;" << endl;
		cout << "2) ���������� ��������� � ����� ������;" << endl;
		cout << "3) ���������� ��������� �� �������;" << endl;
		cout << "4) �������� �������� � ����� ������;" << endl;
		cout << "5) �������� �������� � ������ ������;" << endl;
		cout << "6) �������� �������� �� �������;" << endl;
		cout << "7) �������� �������� �� ��������;" << endl;
		cout << "8) ������� ������;" << endl;
		cout << "9) ��������� �������� ������ �� �������;" << endl;
		cout << "10) ������� ���� ������;" << endl;
		cout << "11) ���������� ������ (�������� �������);" << endl;
		cout << "0) ����� �� ���������." << endl;
		try
		{
			cout << endl << "������� ����� �������:" << endl;
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
			cout << endl << "������������ ����! ��������� ����." << endl;
			throw;
		}
		switch (index)
		{
			case 0:
				cout << endl << "��������������� ����� �� ���������." << endl;
				break;
			case 1:
				cout << endl << "���������� ��������� � ������ ������:" << endl;
				cout << "������� ��������:" << endl;
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
				cout << endl << "���������� ��������� � ����� ������:" << endl;
				cout << "������� ��������:" << endl;
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
				cout << endl << "���������� ��������� �� �������:" << endl;
				cout << "������� ������� � ��������������� �� ��������:" << endl;
				do
				{
					cout << "������� ������: ";
					cin >> ind;
					if (!cin)
						break;
					cout << "������� ��������: ";
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
				cout << endl << "�������� �������� � ����� ������:" << endl;
				cout << lst;
				lst.pop_back();
				cout << lst;
				break;
			case 5:
				cout << endl << "�������� �������� � ������ ������:" << endl;
				cout << lst;
				lst.pop_front();
				cout << lst;
				break;
			case 6:
				cout << endl << "�������� �������� �� �������:" << endl;
				cout << "������� ������:";
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
				cout << endl << "�������� �������� �� ��������:" << endl;
				cout << "������� ��������:";
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
				cout << endl << "������� ������:" << endl;
				lst.clear();
				break;
			case 9:
				cout << endl << "��������� �������� ������ �� �������:" << endl;
				cout << "������� ������: " << endl;
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
				cout << endl << "������ �� ���������:" << endl;
				cout << lst;
				cout << "������ ����� ��������� ������� ��������:" << endl;
				lst.reverse();
				cout << lst;
				break;
		}
	} while (index != 0);

	/*
	// ������ ������� ������� � �������������
	cout << "���������� ������: " << endl;
	do
	{
		cin >> data;
		lst.push_back(data);
	} while (data != 0);
	lst.pop_back();
	cout << lst;

	cout << "�������� ������� �� �������: " << endl;
	cout << "Index = ";
	cin >> index;
	cout << " Element = ";
	cin >> data;
	cout << endl;
	lst.insert(data, index);
	cout << lst;

	cout << "������� ������� �� �������: " << endl;
	cout << "Index = ";
	cin >> index;
	cout << endl;
	lst.remove(index);
	cout << lst;

	cout << "������� ������� �� ��������: " << endl;
	cout << "Element = ";
	cin >> data;
	cout << endl;
	lst.erase(data);
	cout << lst;

	cout << "����������� ����!" << endl;
	lst.reverse();
	cout << lst;
	*/

	lst.~DbLinkList(); // ���� ������� ����������

	#ifdef _DEBUG
		//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		//_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
		_CrtMemDumpStatistics(&_ms);
		_CrtMemDumpAllObjectsSince(&_ms);
	#endif // DEBUG

	return 0;
}

#endif