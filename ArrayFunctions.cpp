/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#include "ArrayFunctions.h"
// constructor
ArrayFunctions::ArrayFunctions(){
  m_windowsSize = 1;
  windows = new Window[m_windowsSize];
  m_studentsInArray = 0;
}

// overlaoded constructor
ArrayFunctions::ArrayFunctions(int maxSize){
  m_windowsSize = maxSize;
  windows = new Window[m_windowsSize];
  m_studentsInArray = 0;
}

// destructor
ArrayFunctions::~ArrayFunctions(){
  delete [] windows;
}

// makes the array of windows
void ArrayFunctions::makeArrayOfWindows(int newSize){
  int size = 1;
  setWindowSize(newSize);
  Window *tempWindows = new Window[newSize];
  memcpy ( tempWindows, windows, size * sizeof(int) );
  m_windowsSize = newSize;
  delete [] windows;
  windows = tempWindows;
}

// sets the number of windows
void ArrayFunctions::setWindowSize(int maxSize){
  m_windowsSize = maxSize;
}

// returns the number of windows
int ArrayFunctions::getWindowSize(){
  return m_windowsSize;
}

// returns the number of student in the array
int ArrayFunctions::getNumberStudentsInArray(){
  return m_studentsInArray;
}

// checks for at least one student still in the array
bool ArrayFunctions::areWindowsEmpty(){
  bool result = true;
  for(int i = 0; i < m_windowsSize; ++i){
    if(windows[i].getStudent().returnStudentID() != -1){
      result = false;
      break;
    }
    else{
      result = true;
    }
  }
  if(result == false){
    return false;
  }
  return true;
}

// checks if all windows are full
bool ArrayFunctions::areWindowsFull(){
  if(findFirstAvailableWindow() == -1){
    return true;
  }
  return false;
}

// returns first available window
int ArrayFunctions::findFirstAvailableWindow(){
  int openIndex = 0;
  for(int i = 0; i < m_windowsSize; ++i){
    if((windows[i].getStudent().returnStudentID() == -1)&&(windows[i].getStudent().returnArrivalTime() == -1)&&(windows[i].getStudent().returnWaitTime() == -1)){ // spot is empty
      openIndex = i;
      break;
    }
    else{
      openIndex = -1;
    }
  }
  return openIndex;
}

// checks each window if it is empty
void ArrayFunctions::checkIfWindowIsEmpty(){
  bool result = false;
  for(int i = 0; i < m_windowsSize; ++i){
    result = windows[i].isWindowEmpty();
  }
}
