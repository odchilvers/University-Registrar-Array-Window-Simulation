/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/
#include "Metrics.h"

// constructor
Metrics::Metrics(){
  finishedStudents = new Queue<Student>();
  m_windowSize = 0;
}

// destructor
Metrics::~Metrics(){
  delete finishedStudents;
}

// runs the final calculations
void Metrics::runCalculations(Window *windowArray, int size){
  m_windowSize = size;
  calculateMeanStudentWaitTime();
  calculateMedianStudentWaitTime();
  findLongestStudentWaitTime();
  returnNumberOfStudents();
  calculateMeanWindowIdleTime(windowArray);
  returnLongestWindowIdleTime(windowArray);
  returnNumberOfWindows(windowArray);
}

// calculates the mean student wait time
double Metrics::calculateMeanStudentWaitTime(){
  int studentWaitTime = 0;
  double meanStudentWaitTime = 0.0;
  int numberOfStudents = finishedStudents->getSize();
  for(int i = 0; i < numberOfStudents; ++i){
    Student currentStudent = finishedStudents->dequeue();
    studentWaitTime = currentStudent.returnTotalWaitTime();
    meanStudentWaitTime += studentWaitTime;
    finishedStudents->enqueue(currentStudent);
  }
  meanStudentWaitTime = meanStudentWaitTime / numberOfStudents;
  cout << "Mean Student Wait Time: " << meanStudentWaitTime << endl;
}

// calculates the median student wait time
double Metrics::calculateMedianStudentWaitTime(){
  double medianStudentWaitTime = 0.0;
  int numberOfStudents = finishedStudents->getSize();
  int numbers [numberOfStudents] = { };
  for(int i = 0; i < numberOfStudents; ++i){
    Student currentStudent = finishedStudents->dequeue();
    numbers[i] = currentStudent.returnTotalWaitTime();
    finishedStudents->enqueue(currentStudent);
  }
  int num = sizeof(numbers) / sizeof(numbers[0]);
  sort(numbers, numbers + num);
  if((numberOfStudents % 2) != 0){ // if the number of students is odd
    medianStudentWaitTime = (double)numbers[numberOfStudents/2];
  }
  else{ // number of students is even
    medianStudentWaitTime = (double)(numbers[(numberOfStudents - 1)/2] + numbers[numberOfStudents/2])/2;
  }
  cout << "Median Student Wait Time: " << medianStudentWaitTime << endl;
}

// returns the longest student wait time
int Metrics::findLongestStudentWaitTime(){
  int studentWaitTime = 0;
  int longestStudentWaitTime = 0;
  int numberOfStudents = finishedStudents->getSize();
  for(int i = 0; i < numberOfStudents; ++i){
    Student currentStudent = finishedStudents->dequeue();
    studentWaitTime = currentStudent.returnTotalWaitTime();
    if(studentWaitTime > longestStudentWaitTime){
      longestStudentWaitTime = studentWaitTime;
    }
    finishedStudents->enqueue(currentStudent);
  }
  cout << "Longest Student Wait Time: " << longestStudentWaitTime << endl;
}

// returns the number of students waiting over 10 minutes
int Metrics::returnNumberOfStudents(){
  int numStudents = 0;
  int studentWaitTime = 0;
  int numberOfStudents = finishedStudents->getSize();
  for(int i = 0; i < numberOfStudents; ++i){
    Student currentStudent = finishedStudents->dequeue();
    studentWaitTime = currentStudent.returnTotalWaitTime();
    if(studentWaitTime > 10){
      ++numStudents;
    }
    finishedStudents->enqueue(currentStudent);
  }
  cout << "Number Of Students That Waited Over 10 Minutes: " << numStudents << endl;
}

// calculates the mean window idle time
double Metrics::calculateMeanWindowIdleTime(Window *windowArray){
  double meanWindowIdleTime = 0.0;
  int windowIdleTime = 0;
  int windowSize = m_windowSize;
  for(int i = 0; i < (windowSize); ++i){
    windowIdleTime = windowArray[i].getIdleTime();
    meanWindowIdleTime += (windowIdleTime-1);
  }
  meanWindowIdleTime = meanWindowIdleTime / windowSize;
  cout << "Mean Window Idle Time: " << meanWindowIdleTime << endl;
}

// returns the longest window idle time
int Metrics::returnLongestWindowIdleTime(Window *windowArray){
  int longestWindowIdleTime = 0;
  int windowIdleTime = 0;
  int windowSize = m_windowSize;
  for(int i = 0; i < windowSize; ++i){
    windowIdleTime = (windowArray[i].getIdleTime()-1);
    if(windowIdleTime > longestWindowIdleTime){
      longestWindowIdleTime = windowIdleTime;
    }
  }
  cout << "Longest Window Idle Time: " << longestWindowIdleTime << endl;
}

// returns number of windows idle for over 5 minutes
int Metrics::returnNumberOfWindows(Window *windowArray){
  int numWindows = 0;
  int windowIdleTime = 0;
  int windowSize = m_windowSize;
  for(int i = 0; i < windowSize; ++i){
    windowIdleTime = (windowArray[i].getIdleTime()-1);
    if(windowIdleTime > 5){
      ++numWindows;
    }
  }
  cout << "Number Of Windows That Were Idle For Over 5 Minutes: " << numWindows << endl;
}
