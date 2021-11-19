/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#ifndef METRICS_H
#define METRICS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

#include "Student.h"
#include "Queue.h"
#include "ArrayFunctions.h"
#include "Window.h"

class Metrics{
  public:
    // constructor
    Metrics();
    // destructor
    ~Metrics();
    // queue that holds the students that are done with the windows and line
    Queue<Student> *finishedStudents;
    // calculates the mean student wait time
    double calculateMeanStudentWaitTime();
    // calculates the median student wait time
    double calculateMedianStudentWaitTime();
    // returns the longest student wait time
    int findLongestStudentWaitTime();
    // returns the number of students waiting over 10 minutes
    int returnNumberOfStudents();
    // calculates the mean window idle time
    double calculateMeanWindowIdleTime(Window *windowArray);
    // returns the longest window idle time
    int returnLongestWindowIdleTime(Window *windowArray);
    // returns number of windows idle for over 5 minutes
    int returnNumberOfWindows(Window *windowArray);
    // runs the final calculations
    void runCalculations(Window *windowArray, int size);
  private:
    int m_windowSize;
};

#endif
