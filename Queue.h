/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "List.h"

using namespace std;

template <class T>
class Queue{
  public:
    Queue();
    ~Queue();
    void enqueue(T data);
    T dequeue();
    T peek();
    bool isEmpty();
    unsigned int getSize();

  private:
    MyList<T> *myList;
    size_t mSize;
    ListNode<T> *front;
    ListNode<T> *rear;
    unsigned int size;
};

// default constructor
template <class T>
Queue<T>::Queue(){
  mSize = 128;
  myList = new MyList<T>();
  front = NULL;
  rear = NULL;
  size = 0;
}

// destructor
template <class T>
Queue<T>::~Queue(){
  delete myList;
}

// inserts to the rear of the queue
template <class T>
void Queue<T>::enqueue(T data){
  myList->append(data);
  ++size;
}

// removes the element from the front of the list
template <class T>
T Queue<T>::dequeue(){
  if(isEmpty()){
    throw runtime_error("Error: Empty - Can not dequeue");
  }
  front = myList->firstNode();
  T temp = myList->remove(front->data);
  --size;
  return temp;
}

// looks at what is at the front of the list
template <class T>
T Queue<T>::peek(){
  if(isEmpty()){
    throw runtime_error("Error: Empty - Can not peek");
  }
  front = myList->firstNode(); // gets the first node of the linked list
  return front->data;
}

// checks if queue is empty
template <class T>
bool Queue<T>::isEmpty(){
  return (size == 0);
}

// returns the size of the queue
template <class T>
unsigned int Queue<T>::getSize(){
  return size;
}

#endif
