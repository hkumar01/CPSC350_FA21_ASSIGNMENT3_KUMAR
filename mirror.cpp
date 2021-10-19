// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

#include "Mirror.h"

//constructor
Mirror::Mirror()
{

}

//destructor
Mirror::~Mirror()
{

}

// mirrorCountNeighbors() function returns an integer for the nunmber of neighbors a certain cell has, based on the boundary conditions for the game mode
// board is the original gameboard created when the program starts
// row and column are dimensions of the board
// curr_i_pos and curr_j_pos indicates which cell's neighbors are being counted
int Mirror::mirrorCountNeighbors(char **board, int row, int column, int curr_i_pos, int curr_j_pos)
{
  int counter = 0;

  char** copyBoard = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    copyBoard[i] = new char[column];
  }

// copy original board to copyBoard
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      copyBoard[i][j] = board[i][j];
    }
  }

  if (curr_i_pos == 0)
  {
    if (curr_j_pos == 0)
    {
// left corner of board
      if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
      {
        counter += 3;
      }
      if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter += 2;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter += 2;
      }
    }
    else if (curr_j_pos = column - 1)
    {
// right corner of board
      if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
      {
        counter += 3;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter += 2;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 2;
      }
    }
    else
    {
// remaining elements in top row of board
      if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter += 2;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 2;
      }
      if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
      {
        counter++;
      }
    }
  }
  else if (curr_i_pos == row - 1)
  {
    if (curr_j_pos == 0)
    {
// bottom row left corner of board
      if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
      {
        counter += 3;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter += 2;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter += 2;
      }
    }
    else if (curr_j_pos == column - 1)
    {
// bottom row right corner of board
      if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
      {
        counter += 3;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter += 2;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 2;
      }
    }
    else
    {
// remaining elements in bottom row
      if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter += 2;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos + 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
      {
        counter++;
      }
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 2;
      }
    }
  }
  else if (curr_j_pos == column - 1)
  {
// right column of board
    if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
    {
      counter += 2;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
    {
      counter += 2;
    }
  }
  else if (curr_j_pos == 0)
  {
// left column of board
    if (copyBoard[curr_i_pos][curr_j_pos] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
    {
      counter += 2;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos - 1][curr_j_pos + 1] == 'X')
    {
      counter++;
    }
    if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
    {
      counter +=2;
    }
  }
  else
  {
// remaining elements on gameboard
    if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos - 1][curr_j_pos + 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
    {
      counter += 1;
    }
  }
// return number of neighbors for specified cell 
  return counter;
}
