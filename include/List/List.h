#ifndef LIST_H
#define LIST_H

#include <clocale>
#include "Element.h"
/*
 *  List Based on Template List made by Jean Simão:
 *  Website Link: https://pessoal.dainf.ct.utfpr.edu.br/jeansimao/
 * */
template <class T> class List
{
private:
	Element<T>* pFirst;
	Element<T>* pLast;

	int len;

public:
	List();
	~List();

	int getLen() { return len; }
	T* getItem(int pos);
	void push(T* item);
	void pop(T* item);

	Element<T>* operator[](int i);
};

template<class T>
List<T>::~List()
{
	pFirst = nullptr;
	pLast = nullptr;
	len = 0;
}

template<class T>
List<T>::List():
	len(0)
{
	pFirst = nullptr;
	pLast = nullptr;
}

template<class T>
T* List<T>::getItem(int pos)
{
	Element<T>* temp = pFirst;

	if (pos == 0)
		return temp->getItem();
	for (int i = 0; i < pos; i++)
		temp = temp->getPNext();

	return temp->getItem();
}

template<class T>
void List<T>::push(T* item)
{
	if (pFirst == nullptr)
	{
		pFirst = new Element<T>;
		pFirst->setItem(item);
		pLast = pFirst;
	}
	else
	{
		Element<T>* temp = new Element<T>;
		temp->setItem(item);
		pLast->setNext(temp);
		pLast = temp;
	}
	len++;
}

template<class T>
void List<T>::pop(T* item)
{
	Element<T>* temp = pFirst;
	Element<T>* tempBack = nullptr;

	while (temp && temp->getItem() != item)
	{
		tempBack = temp;
		temp = temp->getPNext();
	}

	// First element in the list
	if (temp == pFirst)
		pFirst = temp->getPNext();
		// Last element in the list
	else if (temp == pLast)
	{
		tempBack->setNext(nullptr);
		pLast = tempBack;
	} // In the middle of the list
	else if (temp)
		tempBack->setNext(temp->getPNext());

	if (temp)
	    len--;
	delete temp;
}

template<class T>
Element<T>* List<T>::operator[](int i)
{
	return this->getItem(i);
}

#endif //LIST_H

