// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

// Doughnut class implements boundary rules for determining number of neighbors for each cell on the gameboard 

#ifndef DOUGHNUT_H
#define DOUGHNUT_H

#include <iostream>

using namespace std;

class Doughnut
{
  public:
    Doughnut();
    ~Doughnut();
    int countNeighbors(char **board, int row, int column, int curr_i_pos, int curr_j_pos);
};

#endif
