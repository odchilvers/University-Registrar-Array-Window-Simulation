/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#include "FileProcessor.h"

// constructor
FileProcessor::FileProcessor(){
  inputs = new Queue<string>();
  tempStudentLine = new Queue<Student>();
}

// destructor
FileProcessor::~FileProcessor(){
  delete inputs;
  delete tempStudentLine;
}

// checks if file exists and reads from file
int FileProcessor::readFromFile(string inputFile){
  ifstream inputUserFile(inputFile);
  if(inputUserFile.fail()){
    throw runtime_error("Error: Improper input file input");
  }
  string line;
  int numLines = 0;
  int arrivalTime = 0;
  int numStudentsAtTime = 0;
  int windowSize = 0;
  int waitTime = 0;
  int studentIDNum = 1;
  // reads from file to get necessary information
  while(getline(inputUserFile,line)){
    // checks that the input given is a positive number
    if(line.length() == 2){
      if(isdigit(line[0]) == 0){ // c is not a digit
        throw runtime_error("Error - Inputs must be a positive number!");
      }
    }
    else{
      for(int i = 0; i < line.length()-1; ++i){
        if(isdigit(line[i]) == 0){ // c is not a digit
          throw runtime_error("Error - Inputs must be a positive number!");
        }
      }
    }
    inputs->enqueue(line); // adds the line input into a queue that holds inputs
    ++numLines;
  }
  // makes window and populates the students
  for(int i = 0; i < numLines; ++i){
    if(i == 0){ // 1st number is the size of how many windows
      stringstream stToInt(inputs->dequeue());
      stToInt >> windowSize;
      ++i;
    }
    if(i == 1){ // 2nd number is the time that the first set of student arrive at
      stringstream strToInt(inputs->dequeue());
      strToInt >> arrivalTime; // set to be the arrival time of the first set of students
      ++i;
    }
    stringstream stringToInt(inputs->dequeue());
    stringToInt >> numStudentsAtTime;
    for(int j = 0; j < numStudentsAtTime; ++j){ // gets the wait times for the number of students
      ++i;
      stringstream striToInt(inputs->dequeue());
      striToInt >> waitTime;
      Student student(studentIDNum,arrivalTime,waitTime); // make student with the wait time
      tempStudentLine->enqueue(student); // enqueues the student into the queue of students
      ++studentIDNum;
    }
    if(i != (numLines-1)){ // arrival time of other set of students
      stringstream sToInt(inputs->dequeue());
      sToInt >> arrivalTime;
      ++i;
    }
  }
  return windowSize;
  // Closes the file
  inputUserFile.close();
}
