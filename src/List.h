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
#endif //LIST_H
