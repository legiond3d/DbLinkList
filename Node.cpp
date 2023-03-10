#ifndef __Node__
#define __Node__

#include"Header.h"

template<class T>
Node<T>::Node()
{
	this->data = NULL;
	this->prev = NULL;
	this->next = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* left, Node<T>* right)
{
	this->data = data;
	this->prev = left;
	this->next = right;
}

template<class T>
Node<T>::~Node()
{
	this->data = NULL;
	this->prev = NULL;
	this->next = NULL;
}

#endif
