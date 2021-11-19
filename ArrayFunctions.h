/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#include "Student.h"
#include "Window.h"

class ArrayFunctions{
  public:
    // default constructor
    ArrayFunctions();
    // overloaded constructor
    ArrayFunctions(int maxSize);
    // destructor
    ~ArrayFunctions();
    // makes the array of windows
    void makeArrayOfWindows(int newSize);
    // sets the number of windows
    void setWindowSize(int maxSize);
    // returns the number of windows
    int getWindowSize();
    // returns the number of student in the array
    int getNumberStudentsInArray();
    // checks for at least one student still in the array
    bool areWindowsEmpty();
    // checks if all windows are full
    bool areWindowsFull();
    // returns first available window
    int findFirstAvailableWindow();
    // checks if a window is empty
    void checkIfWindowIsEmpty();
    // array that holds the students in the windows
    Window *windows;
    // instance of windows
    Window *w;
  private:
    // number of the windows
    int m_windowsSize;
    // number of students in array
    int m_studentsInArray;
};
#endif
