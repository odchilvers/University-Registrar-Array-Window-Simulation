/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#include "Window.h"

// constructor
Window::Window(){
  Student s(-1,-1,-1);
  m_windowIdleTime = 0;
  m_student = s;
}

// overloaded constructor
Window::Window(Student student){
  m_windowIdleTime = 0;
  m_student = student;
}

// destructor
Window::~Window(){

}

// sets the student
void Window::setStudent(Student student){
  m_student = student;
}

// returns the student
Student Window::getStudent(){
  return m_student;
}

// returns the idle time
int Window::getIdleTime(){
  return m_windowIdleTime;
}

// checks if window has a student
bool Window::isWindowEmpty(){
  // if window is empty
  if(m_student.returnStudentID() == -1){
    m_windowIdleTime += 1; // increment idle time
    return true;
  }
}
