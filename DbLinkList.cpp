#ifndef __List__
#define __List__

#include"Header.h"

// Реализация методов класса DbLinkList:
template<class T>
DbLinkList<T>::DbLinkList()
{
	size = NULL;
	head = nullptr;
	tail = nullptr;
}

template<class T>
DbLinkList<T>::~DbLinkList()
{
	clear();
}

template<class T>
void DbLinkList<T>::push_front(const T& data)
{
	Node<T>* tmp = new Node<T>(data);
	if (!head)
		head = tail = tmp;
	else
	{
		tmp->Next(head);
		head->Prev(tmp);
		head = tmp;
	}
	size++;
}

template<class T>
void DbLinkList<T>::push_back(const T& data)
{
	Node<T>* tmp = new Node<T>(data);
	if (!tail)
		head = tail = tmp;
	else
	{
		tmp->Prev(tail);
		tail->Next(tmp);
		tail = tmp;
	}
	size++;
}

template<class T>
void DbLinkList<T>::insert(const T& data, const int& pos)
{
	if (pos <= 0)
		push_front(data);
	else if (pos >= size)
		push_back(data);
	else
	{
		Node<T>* tmp = new Node<T>(data);
		Node<T>* cur = head;
		int i = 0;
		while (i < pos - 1)
		{
			cur = cur->Next();
			i++;
		}
		tmp->Prev(cur);
		tmp->Next(cur->Next());
		cur->Next(tmp);
		cur = tmp->Next();
		cur->Prev(tmp);
		size++;
	}
}

template<class T>
void DbLinkList<T>::pop_front()
{
	if (size < 2)
		clear();
	else
	{
		Node<T>* tmp = head->Next();
		delete head;
		head = tmp;
		head->Prev(NULL);
		size--;
	}
}

template<class T>
void DbLinkList<T>::pop_back()
{
	if (size < 2)
		clear();
	else
	{
		Node<T>* tmp = tail->Prev();
		delete tail;
		tail = tmp;
		tail->Next(NULL);
		size--;
	}
}

template<class T>
void DbLinkList<T>::remove(const int& pos)
{
	if (pos <= 0)
		pop_front();
	else if (pos >= size - 1)
		pop_back();
	else
	{
		Node<T>* left, *right, *cur = head;
		int i = 0;
		while (i < pos)
		{
			cur = cur->Next();
			i++;
		}
		left = cur->Prev();
		right = cur->Next();
		left->Next(right);
		right->Prev(left);
		delete cur;
		size--;
	}
}

template<class T>
void DbLinkList<T>::erase(const T& data)
{
	if (head != NULL)
	{
		int i = 0;
		Node<T>* cur = head;
		while (cur != NULL)
		{
			if (cur->Data() == data)
			{
				remove(i);
				break;
			}
			else
			{
				cur = cur->Next();
				i++;
			}
		}

	}
}

template<class T>
void DbLinkList<T>::clear()
{
	Node<T>* tmp = NULL;
	while (size > 0)
	{
		tmp = head->Next();
		delete head;
		head = tmp;
		size--;
	}
	tail = NULL;
}

template<class T>
T DbLinkList<T>::operator[](const int& num)
{
	T res = NULL;
	if (size < 1)
		res = NULL;
	else if (num <= 0)
		res = front();
	else if (num >= this->size)
		res = back();
	else
	{
		Node<T>* tmp = this->head;
		for (int i = 0; i < num; i++)
		{
			tmp = tmp->Next();
		}
		res = tmp->Data();
	}
	return res;
}

template<class T>
void DbLinkList<T>::reverse()
{
	Node<T>* tmp, *cur = head;
	while (cur != NULL)
	{
		tmp = cur->Next();
		cur->Next(cur->Prev());
		cur->Prev(tmp);
		cur = cur->Prev();
	}
	cur = head;
	head = tail;
	tail = cur;
}

template<class V>
ostream& operator<<(ostream& path, const DbLinkList<V>& lst)
{
	path << "Коллекция: " << endl << "{ ";
	if (lst.head == NULL)
	{
		path << "Empty }" << endl;
	}
	else
	{
		Node<V>* tmp = lst.head;
		for (int i = 0; i < lst.size; i++)
		{
			path << tmp->Data();
			tmp = tmp->Next();
			if (tmp != NULL)
				path << ", ";
		}
		path << " }." << endl;
	}
	return path;
}

template<class V>
ofstream& operator<<(ofstream& path, const DbLinkList<V>& lst)
{
	path << "Коллекция: " << endl << "{ ";
	if (lst.head == NULL)
	{
		path << "Empty }" << endl;
	}
	else
	{
		Node<V>* tmp = lst.head;
		for (int i = 0; i < lst.size; i++)
		{
			path << tmp->Data();
			tmp = tmp->Next();
			if (tmp != NULL)
				path << ", ";
		}
		path << " }." << endl;
	}
	return path;
}

#endif