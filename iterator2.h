#ifndef __ITERATOR2__H__
#define __ITERATOR2__H__
#include "LinkedList.h"

template<typename T>
class Iterator2{
    private:
    Node<T> *Pos;

public:
    Iterator2(Node<T> *ptr) : Pos(ptr) {}
    Iterator2 operator++(int);
    Iterator2& operator++();
    bool operator==(const Iterator2 &o);
    bool operator!=(const Iterator2 &o);
    T operator*();
};

template <typename T>
Iterator2<T> Iterator2<T>::operator++(int)
{
    Iterator2 temp = *this;
    Pos = Pos->getNext();
    return temp;
}

template<typename T>
Iterator2<T>& Iterator2<T>::operator++()
{   
    Pos = Pos->getNext();
    return *this;
}

template <typename T>
bool Iterator2<T>::operator ==(const Iterator2 &o)
{
    return Pos == o.Pos;
}

template <typename T>
bool Iterator2<T>::operator!=(const Iterator2 &o)
{
    return Pos != o.Pos;
}

template <typename T>
T Iterator2<T>::operator*()
{
    return Pos->getValue();
}

#endif
