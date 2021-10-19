// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

#include "classic.h"

//constructor
Classic::Classic()
{

}

//destructor
Classic::~Classic()
{

}

// numberOfNeighbors() function returns an integer for the nunmber of neighbors a certain cell has, based on the boundary conditions for the game mode
// board is the original gameboard created when the program starts
// row and column are dimensions of the board
// curr_i_pos and curr_j_pos indicates which cell's neighbors are being counted
int Classic::numberOfNeighbors(char **board, int row, int column, int curr_i_pos, int curr_j_pos)
{
  int counter = 0;
  char** copyBoard = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    copyBoard[i] = new char[column];
  }

// copy elements from board to copyBoard
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      copyBoard[i][j] = board[i][j];
    }
  }

  if (curr_i_pos == 0)
  {
    //top left corner of game board
    //checking neighbors of position (0,0) of the 2D array gameboard (left corner)
    if (curr_j_pos == 0)
    {
      if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter += 1;
      }
    }
    // top right corner of game board
    else if (curr_j_pos == column - 1)
    {
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter += 1;
      }
    }
    //top row of game board
    else
    {
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos + 1][curr_j_pos + 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter += 1;
      }
    }
  }
  // last row left corner of game board
  else if (curr_i_pos == row - 1)
  {
    if (curr_j_pos == 0)
    {
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
    }
    //last row right corner of game board
    else if (curr_j_pos == column - 1)
    {
      if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
    }
    //bottom row of game board
    else
    {
      if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos - 1][ curr_j_pos + 1] == 'X')
      {
        counter += 1;
      }
      if (copyBoard[curr_i_pos][curr_j_pos + 1] == 'X')
      {
        counter += 1;
      }
    }
  }
  // left column of game board
  else if (curr_j_pos == 0)
  {
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
  }
  // right column of board
  else if (curr_j_pos == column - 1)
  {
    if (copyBoard[curr_i_pos - 1][curr_j_pos] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos - 1][curr_j_pos - 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos][curr_j_pos - 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos - 1] == 'X')
    {
      counter += 1;
    }
    if (copyBoard[curr_i_pos + 1][curr_j_pos] == 'X')
    {
      counter += 1;
    }
  }
  // remaining elements on the board
  else
  {
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
// return number of neighbors for the specified cell 
  return counter;
}
