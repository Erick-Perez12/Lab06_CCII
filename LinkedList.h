#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include "Node.h"
#include "iterator2.h"
using namespace std;

template <typename T>
class LinkedList;

template<typename T>
std::ostream& operator<<( std::ostream &salida1,const LinkedList<T>& C);

template <typename T>
class LinkedList {
        int size;
        Node<T> *head;
        Node<T> *fin;
    public:

        LinkedList();
        LinkedList(T);
        LinkedList(const LinkedList &);

        ~LinkedList();

        void pushBack(T);
        void pushFront(T);
        void insert_pos(T,int);
        Iterator2<T> Mybegin();
        Iterator2<T> Myend();
        void print();
        void popBack();
        void popFront();
        void delete_pos(T);
        LinkedList(LinkedList<T>& source);
        LinkedList<T>& operator=(LinkedList<T>& source);
       // LinkedList( LinkedList<T>&& source);
        //LinkedList<T>& operator=(LinkedList<T>&& source);

        friend std::ostream& operator<<<T>( std::ostream &salida1,const LinkedList& C);
        
};

template<typename T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
    this->fin = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T value) {
    this->size = 1;
    this->head = new Node<T>(value);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &o) {
    this->size = 0;
    this->head = nullptr;
    Node<T>* actual_o = o.head;
    while(actual_o)
    {
        this->pushBack(actual_o->getValue());
        actual_o = actual_o->getNext();
    }
}

template<typename T>
std::ostream &operator<<(std::ostream &salida1, const LinkedList<T> &C){
    Node<T>* aux = C.head;
    while (aux != nullptr){
        salida1<<"["<<aux->getValue()<<"]";
        aux = aux->getNext();
    }
    return salida1;
}
template <typename T>
void LinkedList<T>::pushFront(T value){
    head = new Node<T>(value, head);
    size++;
}

template<typename T>
void LinkedList<T>::pushBack(T value) {
    Node<T> *newNode = new Node<T>(value);
    Node<T> *tmp = head;
    if(head==nullptr){
        head = newNode;
    } else {
            while  (tmp->getNext() != nullptr)
            {
                tmp = tmp->getNext();
            }
            newNode->setNext(tmp->getNext());
            tmp->setNext(newNode);
    }
    size++;
}
template<typename T>
void LinkedList<T>::insert_pos(T value,int pos){
    if(pos<size+1){
        Node<T> *newNode= new Node<T>(value);
        Node<T> *tmp =head;
        for (int i=0;i<=pos-2;i++){
            tmp=tmp->getNext();
        }
        newNode -> setNext(tmp->getNext() ); 
        tmp->setNext(newNode);
    }
    else{
        cout<<"No";
    }
    size++;
}

template<typename T>
Iterator2<T> LinkedList<T>::Mybegin(){
    return Iterator2<T>(head);
}
template <typename T>
Iterator2<T> LinkedList<T>::Myend(){ 
    return Iterator2<T>(fin);
}

template<typename T>
void LinkedList<T>::print(){
    Node<T>* aux = head;
    int i=1;
    cout<<"lista enlazada";
    while (aux != nullptr){
        cout<<"["<<aux->getValue()<<"]";
        aux = aux->getNext();
        i++;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *actual;
    while (head!=nullptr){
        actual = head->getNext();
        delete head;
        head = actual;
    }
    delete head;
}

template<typename T>
void LinkedList<T>::popFront() {
    if(head){
        Node<T> *actual=head;
        head = head -> getNext(); 
        delete actual;
        size--;
    }
}

template<typename T>
void LinkedList<T>::popBack(){
    int tam=size-1;
        Node<T> *aux, *actual=head;
        if (tam!=0){
            int i=0;
            while(i<tam){
                aux = actual; actual = actual->getNext();
                i++;
            }
            aux -> setNext( actual->getNext() ); 
            delete actual;
        }
        else{
            head = head -> getNext(); 
            delete actual;
        }
        size--;
}

template<typename T>
void LinkedList<T>::delete_pos(T pos) {
    if(pos<size){
        Node<T> *aux, *actual=head;
        if (pos!=0){
            int i=0;
            while(i<pos){
                aux = actual; actual = actual->getNext();
                i++;
            }
            aux -> setNext( actual->getNext() ); 
            delete actual;
        }
        else{
            head = head -> getNext(); 
            delete actual;
        }
        size--;
    }
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>& source)
{
    this->head=nullptr;
    this->fin=nullptr;
    this->size=source.size;
    for(Iterator2<T> i= source.head;i != source.fin;i++){
        this->pushBack(*i);
    }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& source)
{
    LinkedList copia=source;
    std::swap(*this,copia);

	return *this;
}
/*
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& source){
    this->head=nullptr;
    this->fin=nullptr;
    this->size=source.size;
    for(Iterator2<T> j= source.head;j != source.fin;j++){
        this->pushBack(*j);
    }
}
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& source)
{
    LinkedList movi = source;
    *this=std::move(movi);
    return *this;
}*/
//#include "LinkedList.cpp"
#endif
