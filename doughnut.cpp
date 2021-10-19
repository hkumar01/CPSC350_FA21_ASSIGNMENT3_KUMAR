// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

#include "doughnut.h"

//constructor
Doughnut::Doughnut()
{

}

//destructor
Doughnut::~Doughnut()
{

}

// countNeighbors() function returns an integer for the nunmber of neighbors a certain cell has, based on the boundary conditions for the game mode
  // board is the original gameboard created when the program starts
  // row and column are dimensions of the board
  // curr_i_pos and curr_j_pos indicates which cell's neighbors are being counted
int Doughnut::countNeighbors(char **board, int row, int column, int curr_i_pos, int curr_j_pos)
{
  int counter = 0;
  char** newBoard = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    newBoard[i] = new char[column];
  }

// copy original board to newBoard to count neighbors for a specified cell
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      newBoard[i][j] = board[i][j];
    }
  }

  if (curr_i_pos == 0)
  {
    if (curr_j_pos == 0)
    {
// left corner of board
      if (newBoard[row - 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[row - 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos][column - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][column - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[row - 1][column - 1] == 'X')
      {
        counter++;
      }
    }
    else if (curr_j_pos == column - 1)
    {
// right corner of board
      if (newBoard[row - 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[row - 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos][0] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][0] == 'X')
      {
        counter++;
      }
      if (newBoard[row - 1][0] == 'X')
      {
        counter++;
      }
      if(newBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if(newBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter++;
      }
    }
    else
    {
// remaining cells from the top row of board
      if (newBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[row - 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[row - 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[row - 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
    }
  }
  else if (curr_i_pos == row - 1)
  {
    if (curr_j_pos == 0)
    {
// last row left corner of board
      if (newBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][column - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos][column - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[0][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[0][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[0][column - 1] == 'X')
      {
        counter++;
      }
    }
    else if (curr_j_pos == column - 1)
    {
// last row, right corner of board
      if (newBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[0][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[0][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[0][0] = 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][0] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos][0] = 'X')
      {
        counter++;
      }
    }
    else
    {
// remaining elements in last row of board
      if (newBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][ curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[0][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (newBoard[0][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (newBoard[0][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
    }
  }
  else if (curr_j_pos == column - 1)
  {
// right column of board
    if (newBoard[curr_i_pos + 1][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos - 1][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos][0] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][0] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos - 1][0] == 'X')
    {
      counter++;
    }
  }
  else if (curr_j_pos == 0)
  {
// left column of board
    if (newBoard[curr_i_pos - 1][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos - 1][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos][column - 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][column - 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos - 1][column - 1] == 'X')
    {
      counter++;
    }
  }
  else
  {
// all other elements in board that did not meet the previous conditions
    if (newBoard[curr_i_pos - 1][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos - 1][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (newBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
  }
// return number of neighbors for the specified cell 
  return counter;
}
