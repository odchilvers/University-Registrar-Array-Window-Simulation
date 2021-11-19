/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
  public:
    // default constructor
    Student();
    // overlaoded constructor
    Student(int studentID, int arrivalTime, int waitTime);
    // destructor
    ~Student();
    // returns student ID
    int returnStudentID();
    // returns arrival time
    int returnArrivalTime();
    // returns start time
    int returnStartTime();
    // returns wait time
    int returnWaitTime();
    // return total wait time
    int returnTotalWaitTime();
    // returns end time
    int returnEndTime();
    // returns index position
    int returnWindowIndex();
    // sets the start time in the array and updates the endtime in the array
    void setStartTime(int startTime);
    // updates endtime of the student in the array
    void setEndTime();
    // updates index of the student in the array
    void setWindowIndex(int windowIndex);
    // updates endtime of the student in the array
    void setEndTime(int endTime);
    // increments the wait time of the student
    void incrementWaitTime();
  private:
    // student ID of the student
    int m_studentID;
    // arrival time that the student arrives
    int m_arrivalTime;
    // start time that the student arrives in window
    int m_startTime;
    // wait time that the student has to take in the window
    int m_waitTime;
    // end time and when student leaves
    int m_endTime;
    // window index of the student
    int m_windowIndex;
    // total time student had to wait in the queue
    int m_totalWaitTime;
};

#endif
