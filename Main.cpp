/*
Olivia Chilvers
2366117
ochilvers@chapman.edu
CPSC 350-01
Assignment 5
*/
#include "Simulation.h"

int main (int argc, char** argv){
  try{
    // checks number of arguments in command line
    if(argc < 2){
      cout << "Invalid number of arguments: Please enter location of a text file" << endl;
      return -1;
    }else{
      Simulation *s = new Simulation();
      string inputFile = argv[1];
      // runs the simulation of the game
      s->runSimulation(inputFile);
      delete s;
    }
  }
  catch(runtime_error &except){ // catches any errors
    cerr << except.what() << endl;
  }
    return 0;
}
