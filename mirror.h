// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

// Mirror class implements boundary rules for determining number of neighbors for each cell on the gameboard

#ifndef MIRROR_H
#define MIRROR_H

#include <iostream>

using namespace std;

class Mirror
{
  public:
    Mirror();
    ~Mirror();
    int mirrorCountNeighbors(char **board, int row, int column, int curr_i_pos, int curr_j_pos);
};

#endif
