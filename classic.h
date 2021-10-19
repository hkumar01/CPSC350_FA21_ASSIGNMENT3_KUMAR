// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

// Classic class implements boundary rules for determining number of neighbors for each cell on the gameboard

#ifndef CLASSIC_H
#define CLASSIC_H

#include <iostream>

using namespace std;

class Classic
{
  public:
    Classic();
    ~Classic();
    int numberOfNeighbors(char **board, int row, int column, int curr_i_pos, int curr_j_pos);
};

#endif
