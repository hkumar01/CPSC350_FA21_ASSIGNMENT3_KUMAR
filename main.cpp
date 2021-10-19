// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

//Game start-up and operation takes place in main 

#include <iostream>
#include "gameboard.h"

using namespace std;

int main(int argc, char** argv)
{
  Gameboard *test = new Gameboard();
  test->start();
  test->runGame();

  test->~Gameboard();

  return 0;
}
