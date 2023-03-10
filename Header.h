#ifndef __Header__
#define __Header__

#ifdef _DEBUG
	#include<crtdbg.h>
	#define _CRTDBG_MAP_ALLOC
	#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include<iostream>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<clocale>
using namespace std;

template<class T>
class Node // ����� ����������� ������� ������
{
private:
	Node* prev; // ��������� �� �������������� ������� ���������
	Node* next; // ��������� �� ��������� ������� ���������
	T data;
public:
	Node(); // ����������� �� ���������
	Node(T data = NULL, Node<T>* left = nullptr, Node<T>* right = nullptr); // ����������� � �����������

	~Node(); // ����������

	T Data() { return data; }
	Node<T>* Prev() { return prev; }
	Node<T>* Next() { return next; }

	void Data(T data) { this->data = data; }
	void Prev(Node<T>* left) { this->prev = left; }
	void Next(Node<T>* right) { this->next = right; }
};

template<class T>
class DbLinkList // ����� ����������� ������������ ��������� - ���������� ������
{
private:
	Node<T>* head; // ��������� �� ������� ����� ������� � ���������
	Node<T>* tail; // ��������� �� ������� ������ ������� � ���������
	int size; // ���������� ��������� � ���������
public:
	DbLinkList(); // ����������� �� ���������

	~DbLinkList(); // ����������

	void push_front(const T& data); // ���������� ������ �������� � ������ 
	void push_back(const T& data); // ���������� ������ �������� � �����
	void insert(const T& data, const int& pos); // ���������� �������� � ������������ �������

	void pop_front(); // �������� ������� �������� ���������
	void pop_back(); // �������� ���������� �������� ���������
	void remove(const int& pos); // �������� ������������� ��������
	void erase(const T& data); // �������� �������� �� �������� (������ ���������)
	void clear(); // �������� ���� ��������� ���������

	T front() { return head->Data(); }
	T back() { return tail->Data(); }
	T operator[](const int& num); // �������� �������� �� �������
	T Size() { return size; } // ������ ���-�� ��������� � ���������
	void reverse(); // �������������� ������

	template<class V>
	friend ostream& operator<<(ostream& path, const DbLinkList<V>& data); // ��������� ����� 
	template<class V>
	friend ofstream& operator<<(ofstream& path, const DbLinkList<V>& data); // ��������� ����� � ����
};

#include"Node.cpp"
#include"DbLinkList.cpp"

#endif