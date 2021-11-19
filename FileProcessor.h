/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "Queue.h"
#include "Student.h"

using namespace std;

class FileProcessor{
  public:
    // constructor
    FileProcessor();
    // destructor
    ~FileProcessor();
    // checks if file exists and reads from file
    int readFromFile(string inputFile);
    // queue that holds the students from file in that order
    Queue<Student> *tempStudentLine;
  private:
    // queue that holds the inputs from the file
    Queue<string> *inputs;
};
#endif
