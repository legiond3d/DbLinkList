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
class Node // класс реализующий элемент списка
{
private:
	Node* prev; // указатель на предшествующий элемент коллекции
	Node* next; // указатель на следующий элемент коллекции
	T data;
public:
	Node(); // конструктор по умолчанию
	Node(T data = NULL, Node<T>* left = nullptr, Node<T>* right = nullptr); // конструктор с параметрами

	~Node(); // деструктор

	T Data() { return data; }
	Node<T>* Prev() { return prev; }
	Node<T>* Next() { return next; }

	void Data(T data) { this->data = data; }
	void Prev(Node<T>* left) { this->prev = left; }
	void Next(Node<T>* right) { this->next = right; }
};

template<class T>
class DbLinkList // класс реализующий динамическую структуру - двусвязный список
{
private:
	Node<T>* head; // указатель на крайний левый элемент в коллекции
	Node<T>* tail; // указатель на крайний правый элемент в коллекции
	int size; // количество элементов в коллекции
public:
	DbLinkList(); // конструктор по умолчанию

	~DbLinkList(); // деструктор

	void push_front(const T& data); // добавление нового элемента в начало 
	void push_back(const T& data); // добавление нового элемента в конец
	void insert(const T& data, const int& pos); // добавление элемента в произвольную позицию

	void pop_front(); // удаление первого элемента коллекции
	void pop_back(); // удаление последнего элемента коллекции
	void remove(const int& pos); // удаление произвольного элемента
	void erase(const T& data); // удаление элемента по значению (первое включение)
	void clear(); // удаление всех элементов коллекции

	T front() { return head->Data(); }
	T back() { return tail->Data(); }
	T operator[](const int& num); // просмотр элемента по индексу
	T Size() { return size; } // геттер кол-ва элементов в коллекции
	void reverse(); // разворачивание списка

	template<class V>
	friend ostream& operator<<(ostream& path, const DbLinkList<V>& data); // потоковый вывод 
	template<class V>
	friend ofstream& operator<<(ofstream& path, const DbLinkList<V>& data); // потоковый вывод в файл
};

#include"Node.cpp"
#include"DbLinkList.cpp"

#endif