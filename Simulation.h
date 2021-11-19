/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>

#include "FileProcessor.h"
#include "Metrics.h"
#include "ArrayFunctions.h"

using namespace std;

class Simulation{
  public:
    // default constructor
    Simulation();
    // destructor
    ~Simulation();
    // file processor
    FileProcessor *fp;
    // instance of windows
    Metrics *m;
    // instance of array functions
    ArrayFunctions *af;
    // instance of window
    Window *windows;
    // runs the entire simulation of the queue
    void runSimulation(string inputFile);
    // sets up the windows and queue of students
    int makeSetUp(string inputFile);
    // checks what students' arrival times are
    void checkStudentArrivalTimes(int time);
    // checks for what students' endtimes are
    void checkStudentEndTimes(int time);
    // checks if simulation is over
    bool isSimulationOver();
    // checks if students are still in the queue and increments their wait time
    void checkStudentsInQueue();
    // gets the calculations
    void getCalculations(Window *windowArray);
  private:
    // queue that holds the students in line based on their arrival time
    Queue<Student> *studentLine;
    // number of student currently in the queue
    int m_numStudentsInLine;
};
#endif
