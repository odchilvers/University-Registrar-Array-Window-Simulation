/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/

#include "Simulation.h"

// default constructor
Simulation::Simulation(){
  fp = new FileProcessor();
  m = new Metrics();
  af = new ArrayFunctions();
  studentLine = new Queue<Student>();
  windows = new Window[0];
  m_numStudentsInLine = 0;
}

// destructor
Simulation::~Simulation(){
  delete fp;
  delete m;
  delete af;
  delete studentLine;
  delete [] windows;
}

// runs the simulation of the game
void Simulation::runSimulation(string inputFile){
  int windowSize = makeSetUp(inputFile);
  af->makeArrayOfWindows(windowSize);
  af->setWindowSize(windowSize);
  // initializes array to students
  for(int i = 0; i < windowSize; ++i){
    Student student(-1,-1,-1);
    Window window = Window(student);
    af->windows[i] = window;
  }
  int time = 0;
  // runs until windows and queue are empty
  bool isOver = false;
  int numStudentsInLine = 0;
  while(isOver == false){
    for(int i = 0; i < studentLine->getSize(); ++i){ // iterates through every student in the queue
      Student currentStudent = studentLine->dequeue();
      studentLine->enqueue(currentStudent);
    }
    // iterates through the temporary line of students to see their arrival time
    checkStudentArrivalTimes(time);
    // check in the array if there is a student that has an endtime that is equal to the current clock tick time
    checkStudentEndTimes(time);
    // if there is a student in the queue, and there is an open window, send the student to the window
    while((m_numStudentsInLine != 0) && !(af->areWindowsFull())){
      Student currentStudent = studentLine->dequeue(); // removes student from the queue
      if(currentStudent.returnStudentID() != -1){
        currentStudent.setStartTime(time); // sets the start time that the student entered the queue to what the current time is
        int openIndex = af->findFirstAvailableWindow(); // first openIndex
        currentStudent.setWindowIndex(openIndex); // set index that student is at
        af->windows[openIndex].setStudent(currentStudent); // puts the student into the available window
        --m_numStudentsInLine;
      }
    }
    // checks after adding any necessary student if a window is still empty and increments the idle time of the window
    af->checkIfWindowIsEmpty();
    // checks if any students are still in the queue
    checkStudentsInQueue();
    // check if simulation is over
    isOver = isSimulationOver();
    if(isOver == 1){
      break;
    }
    ++time;
  }
    // gets the calculations after the entire simulation
    getCalculations(af->windows);
}

// sets up the windows and queue of students
int Simulation::makeSetUp(string inputFile){
  // sets up the windows and queue of students
  int size = fp->readFromFile(inputFile);
  return size;
}

// checks what students' arrival times are
void Simulation::checkStudentArrivalTimes(int time){
  Student currentStudent(-1,-1,-1);
  int size = fp->tempStudentLine->getSize();
  // iterates through the temporary line of students to see their arrival time
  for(int i = 0; i < size; ++i){
    currentStudent = fp->tempStudentLine->dequeue();
    // checks if there is a student with an arrival time that is equal to the clock tick time
    if(currentStudent.returnArrivalTime() == time){
      studentLine->enqueue(currentStudent); // put student into the queue
      ++m_numStudentsInLine;
    }
    else{
      fp->tempStudentLine->enqueue(currentStudent); // adds the student back in the line
    }
  }
}

// checks for what students' endtimes are
void Simulation::checkStudentEndTimes(int time){
  Student tempStudent(-1,-1,-1);
  tempStudent.setEndTime(-1);
  int size = af->getWindowSize();
  // iterates through the temporary array of students to see their end time
  for(int i = 0; i < size; ++i){
    Student currentStudent = af->windows[i].getStudent();
    // checks if there is a student with an end time that is equal to the clock tick time
    if(currentStudent.returnEndTime() == time){
      // remove student from the window array and put them into the finished students queue
      int windowIndex = currentStudent.returnWindowIndex();
      af->windows[windowIndex].setStudent(tempStudent); // removes from the index where the student to be removed needs to be removed
      m->finishedStudents->enqueue(currentStudent); // adds the current student that is done to the finished students queue
    }
  }
}

// checks if simulation is over
bool Simulation::isSimulationOver(){
  bool areWindowsEmpty = af->areWindowsEmpty();
  int studentLineSize = studentLine->getSize();
  int tempStudentLineSize = fp->tempStudentLine->getSize();
  // if all windows are empty, and the queue of students is empty, and the queue of students waiting to enter the queue is empty
  if((areWindowsEmpty == true) && (studentLineSize == 0) && (tempStudentLineSize == 0)){
    return true; // simulation is over
  }
  else{
    return false; // simulation is not over
  }
}

// checks if there is students in the queue
void Simulation::checkStudentsInQueue(){
  int size = studentLine->getSize();
  for(int i = 0; i < size; ++i){ // iterates through every student in the queue
    Student currentStudent = studentLine->dequeue();
    currentStudent.incrementWaitTime(); // if there is a student in the line, increment their time waiting in line
    studentLine->enqueue(currentStudent);
  }
}

// gets the calculations
void Simulation::getCalculations(Window *windowArray){
  int size = af->getWindowSize();
  m->runCalculations(windowArray, size); // runs the calculations of the stats
}
