/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

using namespace std;

#include "Student.h"

class Window{
  public:
    // default constructor
    Window();
    // overloaded constructor
    Window(Student student);
    // destructor
    ~Window();
    // sets the student
    void setStudent(Student student);
    // gets the student
    Student getStudent();
    // returns the idle time
    int getIdleTime();
    // checks if window has a student
    bool isWindowEmpty();
  private:
    // window idle time
    int m_windowIdleTime;
    // student
    Student m_student;
};

#endif
