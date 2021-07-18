#ifndef ELEMENT_H
#define ELEMENT_H


template <class T> class Element
{
private:
	Element<T>* pNext;
	T* item;
public:
	Element();
	~Element();

	void setNext(Element<T>* pNext) { this->pNext = pNext; }
	void setItem(T* item) { this->item = item; }
	Element<T>* getPNext() { return pNext; }
	T* getItem() { return item; }
};
template<class T>
Element<T>::Element()
{
	pNext = nullptr;
	item = nullptr;
}
template<class T>
Element<T>::~Element()
{
	pNext = nullptr;
	item = nullptr;
}


#endif //ELEMENT_H
