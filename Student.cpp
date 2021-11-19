/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#include "Student.h"

// default constructor
Student::Student(){
  m_studentID = -1;
  m_arrivalTime = -1;
  m_startTime = -1;
  m_waitTime = -1;
  m_endTime = -1;
  m_windowIndex = -1;
  m_totalWaitTime = 0;
}

// overlaoded constructor
Student::Student(int studentID, int arrivalTime, int waitTime){
  m_studentID = studentID;
  m_arrivalTime = arrivalTime;
  m_startTime = arrivalTime;
  m_waitTime = waitTime;
  m_endTime = m_startTime + m_waitTime;
  m_windowIndex = -1;
  m_totalWaitTime = 0;
}

// destructor
Student::~Student(){
  // automatically called since no dynamic allocation
}

// returns student ID
int Student::returnStudentID(){
  return m_studentID;
}

// returns arrival time
int Student::returnArrivalTime(){
  return m_arrivalTime;
}

// returns start time
int Student::returnStartTime(){
  return m_startTime;
}

// return wait time
int Student::returnWaitTime(){
  return m_waitTime;
}

// return total wait time
int Student::returnTotalWaitTime(){
  return m_totalWaitTime;
}

// returns end time
int Student::returnEndTime(){
  return m_endTime;
}

// returns end time
int Student::returnWindowIndex(){
  return m_windowIndex;
}

// sets the start time and updates endtime in the array
void Student::setStartTime(int startTime){
  m_startTime = startTime;
  // updates end time in the array
  setEndTime();
}

// updates endtime of the student in the array
void Student::setEndTime(){
  m_endTime = m_startTime + m_waitTime;
}

// updates endtime of the student in the array
void Student::setEndTime(int endTime){
  m_endTime = endTime;
}

// updates the index of the student position
void Student::setWindowIndex(int windowIndex){
  m_windowIndex = windowIndex;
}

// increments the student wait time
void Student::incrementWaitTime(){
  ++m_totalWaitTime;
}
