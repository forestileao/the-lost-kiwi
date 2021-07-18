#ifndef LIST_H
#define LIST_H

#include "Element.h"

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
		pLast->setProx(temp);
		pLast = temp;
	}
	len++;
}

template<class T>
void List<T>::pop(T* item)
{
	Element<T>* temp = pFirst;
	Element<T>* tempBack = nullptr;

	while (temp->getItem() != item)
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
		tempBack->setProx(nullptr);
		pLast = tempBack;
	} // In the middle of the list
	else
		tempBack->setProx(temp->getPNext());

	delete temp;
	len--;
}

#endif //LIST_H

