/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

// ASK IF REMOVE NEEDS TO TAKE IN A PARAMETER!!

#ifndef LIST_H
#define LIST_H

#include "DoubleLinkedList.h"

template <class T>
class List{
  public:
    virtual void append(T d) = 0;
    virtual void prepend(T d) = 0;
    virtual T remove(T d) = 0;
    virtual bool isEmpty() = 0;
    virtual unsigned int getLength() = 0;
};

template <class T>
class MyList : public List<T>{
  public:
    MyList();
    ~MyList();
    void append(T d);
    void prepend(T d);
    T remove(T d);
    bool isEmpty();
    unsigned int getLength();
    ListNode<T>* firstNode();
  private:
    DoubleLinkedList<T> *myDoublyLinkedList;
};

// constructor
template <class T>
MyList<T>::MyList(){
  myDoublyLinkedList = new DoubleLinkedList<T>();
}

// destructor
template <class T>
MyList<T>::~MyList(){
  delete myDoublyLinkedList;
}

// adds data to the back of the list
template <class T>
void MyList<T>::append(T d){
  myDoublyLinkedList->insertBack(d);
}

// adds data to the front of the list
template <class T>
void MyList<T>::prepend(T d){
  myDoublyLinkedList->insertFront(d);
}

// removes the front of the list
template <class T>
T MyList<T>::remove(T d){
  return myDoublyLinkedList->removeFront();
}

// checks if the list is empty
template <class T>
bool MyList<T>::isEmpty(){
  return myDoublyLinkedList->isEmpty();
}

// returns the length of the list
template <class T>
unsigned int MyList<T>::getLength(){
  return myDoublyLinkedList->getSize();
}

// returns the front of the linked list
template <class T>
ListNode<T>* MyList<T>::firstNode(){
  return myDoublyLinkedList->firstNode();
}

#endif
