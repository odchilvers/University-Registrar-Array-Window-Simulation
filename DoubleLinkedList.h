/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <exception>

using namespace std;

template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    ListNode<T> *next;
    ListNode<T> *prev;
    T data;
};

// default constructor
template <class T>
ListNode<T>::ListNode(){

}

// overloaded constructor
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

// destructor
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}

template <class T>
class DoubleLinkedList{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    int find(T value);
    bool isEmpty();
    unsigned int getSize();
    T deleteAtPos(int pos);
    ListNode<T>* firstNode();
};

// default constructor
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

// destructor
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
  ListNode<T> *curr = front;
  while(curr != 0){
    ListNode<T> *node = curr->next;
    delete curr;
    curr = node;
  }
  front = 0;
}

// inserts data at the front of the linked list
template <class T>
void DoubleLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    back = node;
  }
  else{
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

// inserts data at the back of the linked list
template <class T>
void DoubleLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    front = node;
  }
  else{
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

// removes the data at the front
template <class T>
T DoubleLinkedList<T>::removeFront(){
  if(isEmpty()){
    throw runtime_error("Error: Empty - Can not remove");
  }
  ListNode<T> *temp = front;
  if(front->next == NULL){
    back = NULL;
  }
  else{
    front->next->prev = NULL;
  }
  front = front->next;
  T data = temp->data;
  temp->next = NULL;
  --size;
  delete temp;
  return data;
}

// removes data from the back
template <class T>
T DoubleLinkedList<T>::removeBack(){
  if(isEmpty()){
    throw runtime_error("Error: Empty - Can not remove");
  }
  ListNode<T> *temp = back;
  if(back->prev = NULL){
    front = NULL;
  }
  else{
    back->prev->next = NULL;
  }
  back = back->prev;
  T data = temp->data;
  temp->prev = NULL;
  --size;
  delete temp;
  return data;
}

// finds a certain values
template <class T>
int DoubleLinkedList<T>::find(T value){
  int pos = -1;
  ListNode<T> *curr = front;
  while(curr != NULL){
    ++pos;
    if(curr->data == value){
      break;
    }
    curr = curr->next;
  }
  if(curr == NULL){
    pos = -1;
  }
  return pos;
}

// checked if the linked list is empty
template <class T>
bool DoubleLinkedList<T>::isEmpty(){
  return (size == 0);
}

// returns the size of the linked list
template <class T>
unsigned int DoubleLinkedList<T>::getSize(){
  return size;
}

// deletes node at position
template <class T>
T DoubleLinkedList<T>::deleteAtPos(int pos){
  if(isEmpty()){
    throw runtime_error("Error: Empty - Can not delete");
  }
  int nodePosition = 0;

  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(nodePosition != pos){
    prev = curr;
    curr = curr->next;
    ++nodePosition;
  }

  prev->next = curr->next;
  curr->next = NULL;
  T d = curr->data;
  --size;
  delete curr;
  return d;
}

// returns the front of the linked list
template <class T>
ListNode<T>* DoubleLinkedList<T>::firstNode(){
  return front;
}

#endif
