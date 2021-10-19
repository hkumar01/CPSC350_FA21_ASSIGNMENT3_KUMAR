// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

#include "gameboard.h"

// constructor
Gameboard::Gameboard()
{
  row = 0;
  column = 0;
  popDensity = 0.0;
}

//destructor
Gameboard::~Gameboard()
{
  delete board;
}

// start() function initalizes program and executes game based on user configurations
// if the user selects to input a file and the file is invalid, the program will terminate
void Gameboard::start()
{
  while(true)
  {
    cout << endl;
    cout << "Welcome to Game of Life. Type simulation settings (spelling matters, capitals do not)" << endl;
    cout << endl;
    cout << "Would you like to start with a random game board or input a file? Type: (Random/File)"<< endl;

    cin >> boardSelection;
    if ((boardSelection == "Random") || (boardSelection == "random") || (boardSelection == "File") || (boardSelection == "file"))
    {
        if ((boardSelection == "Random") || (boardSelection == "random"))
        {
          randomBoard();
        }
        else if ((boardSelection == "File") || (boardSelection == "file"))
        {
          cout << "Enter a file name: " << endl;
          cin >> fileName;

          ifstream fileStream;

          fileStream.open(fileName);
          if (!fileStream.is_open())
          {
            cout << "Cannot open file. Exiting." << endl;
            exit(EXIT_FAILURE);
          }
          fileStream.close();
          fileBoard(fileName); //adjust this function to prompt for file within the function and do file checking in it
        }
    }
    else
    {
      continue;
    }

    cout << "Select game mode. Type: (Classic/Doughnut/Mirror)" << endl;
    cin >> gamemodeSelection;

    if ((gamemodeSelection == "Classic")|| (gamemodeSelection == "classic") || (gamemodeSelection == "Doughnut") || (gamemodeSelection == "doughnut")
    || (gamemodeSelection == "Mirror") || (gamemodeSelection == "mirror"))
    {
    }
    else
    {
      continue;
    }

    cout << "Pause between each generation or output to a file? Type: (Pause) if desired, or click any key and Enter." << endl;
    cin >> pause;

    if ((pause == "Pause") || (pause == "pause"))
    {
    }

    break;
  }
}

// runGame() function will select the game mode to execute based on user selection
void Gameboard::runGame()
{
  if (gamemodeSelection == "Classic" || gamemodeSelection == "classic")
  {
    playClassicMode(pause, board);
  }
  else if (gamemodeSelection == "Doughnut" || gamemodeSelection == "doughnut")
  {
    playDoughnutMode(pause, board);
  }
  else if (gamemodeSelection == "Mirror" || gamemodeSelection == "mirror")
  {
    playMirrorMode(pause, board);
  }
}

// randomBoard() creates a random board by prompting user for the height and width and population density between 0.0 and 1.0
// initalizes char** board
void Gameboard::randomBoard()
{
  cout << "Enter the length of the game board." << endl;
  cin >> row;

  cout << "Enter the width of the game board." << endl;
  cin >> column;

  popDensityOk = false;

  while (!popDensityOk)
  {
    cout << "Enter the population density as a decimal between 0.0 and 1.0." << endl;
    cin >> popDensity;

    if ((popDensity <= 0.0) || (popDensity >= 1.0 ))
    {
      popDensityOk = false;
    }
    else
    {
      popDensityOk = true;
    }
  }

  board = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    board[i] = new char[column];
  }

  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      numGenerator = rand() % 100;
      numGenerator /= 100;

      if (popDensity <= numGenerator)
      {
        board[i][j] = 'X';
      }
      else
      {
        board[i][j] = '-';
      }
    }
  }
}

// fileBoard() initalizes char** board based on the height and width sizes specified in the file and the game board in the file
void Gameboard::fileBoard(string inputFile)
{
  ifstream filestream;
  string currentSentence = "";
  int lineCounter = 0;
  int k = 0;

  filestream.open(inputFile);

  if (!filestream.is_open())
  {
    cout << "Cannot open file. Exiting." << endl;
    exit(EXIT_FAILURE);
  }

  while ((!filestream.eof()) && (!filestream.fail()))
  {
    string temp = "";

    if (lineCounter == 0)
    {
      getline(filestream, temp);
      row = stoi(temp);
    }

    else if (lineCounter == 1)
    {
      getline(filestream, temp);
      column = stoi(temp);

      board = new char*[row];

      for (int i = 0; i < row; ++i)
      {
        board[i] = new char[column];
      }
    }

    else
    {
      getline(filestream, temp);

      for (int i = 0; i < temp.size(); ++i)
      {
        if (temp[i] == '-')
        {
          board[k][i] = '-';
        }
        else if (temp[i] == 'X')
        {
          board[k][i] = 'X';
        }
      }
      k++;
    }
    ++lineCounter;
  }
  filestream.close();
}

// getFileName() prompts user for file, checks if the file will open, then returns the filename
// if file is invalid then the program exits
string Gameboard::getFileName()
{
  string fileName;
  cout << "Enter a file name to output." << endl;
  cin >> fileName;

  ifstream fileStream;

  fileStream.open(fileName);

  if (!fileStream.is_open())
  {
    cout << "Cannot open file. Exiting." << endl;
    exit(EXIT_FAILURE);
  }

  fileStream.close();
  return fileName;
}

// plays Mirror game mode, takes string pause as parameter to check if the user wants a break between generations
// pass the original gameboard board as parameter
void Gameboard::playMirrorMode(string pause, char** board)
{
  Gameboard *helper = new Gameboard();

// create secondBoard to count neighbors are gameboard and make changes
  char **secondBoard = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    secondBoard[i] = new char[column];
  }

// third gameboard holds the second to last generation to check for oscilation
  char **sameBoardChecker = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    sameBoardChecker[i] = new char[column];
  }

  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      secondBoard[i][j] = board[i][j];
      sameBoardChecker[i][j] = board[i][j];
    }
  }

// output file
  string fileName = helper->getFileName();

  ofstream outFS;
  outFS.open(fileName);

// loop over every cell in the gameboard while checking for if board is empty, stabilized, or oscilation occurs
  while ((isEmpty == false) || (stabilzed == false))
  {
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        int numNeighbors = 0;
// call mirrorCountNeighbors() from mirror class to check each cell and check neighbors based on boundary rules
// pass secondBoard, board dimensions, and current position the loop is [i][j]
// count empty cells
        numNeighbors = helper->mirrorCountNeighbors(secondBoard, row, column, i, j);
        if (numNeighbors <= 1)
        {
          board[i][j] = '-';
          emptyCounter++;
        }
        else if (numNeighbors == 2)
        {
          if (secondBoard[i][j] == '-')
          {
            board[i][j] = '-';
            emptyCounter++;
          }
          else if (secondBoard[i][j] == 'X')
          {
            board[i][j] = 'X';
          }
        }
        else if (numNeighbors == 3)
        {
          if (secondBoard[i][j] == '-')
          {
            board[i][j] = 'X';
          }
          else if (secondBoard[i][j] == 'X')
          {
            board[i][j] = 'X';
          }
        }
        else if (numNeighbors >= 4)
        {
          board[i][j] = '-';
          emptyCounter++;
        }
      }
    }

// oscilation check, every other generation sameBoardChecker is updated and always holds the second to last gameboard
    if (generationNumber % 2 == 0)
    {
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < column; ++j)
        {
          sameBoardChecker[i][j] = secondBoard[i][j];
        }
      }
    }

    generationNumber++;

// output to file
    outFS << endl;
    cout << endl;
    outFS << "Generation Number: " << generationNumber << endl;
    cout << "Generation Number: " << generationNumber << endl;
    outFS << endl;
    cout << endl;

    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        cout << secondBoard[i][j] << " ";
        outFS << secondBoard[i][j] << " ";
      }
      cout << endl;
      outFS << endl;
    }

// if user selected pause then the game will pause between generations and prompt the user to press a key to continue
    if (pause == "pause" || pause == "Pause")
    {
      string pauseStr = "";
      cout << "Press any key and enter to continue." << endl;
      cin >> pauseStr;
    }

    int numCellsOnBoard = 0;
    int totalNumCells = row * column;

// count number of cells equal between board and secondBoard
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        if (board[i][j] == secondBoard[i][j])
        {
          numCellsOnBoard++;
        }
      }
    }

// count number of cells equal between the current generation and the second to last generation, indicating oscilation
    int cellCount = 0;
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        if (board[i][j] == sameBoardChecker[i][j])
        {
          cellCount++;
        }
      }
    }

// if all cells are equal between current and second to last generation then exit loop and terminate program
// oscilation
    if (cellCount == totalNumCells)
    {
      stabilzed = true;
      outFS << "World is stabilzed." << endl;
      cout << "World is stabilzed, press any key, then click enter to exit." << endl;
      cin >> exitProgram;
      break;
    }

// if all cells are equal for consecutive generations, exit loop and terminate program
    if (numCellsOnBoard == totalNumCells)
    {
      stabilzed = true;
      outFS << "World is stabilzed." << endl;
      cout << "World is stabilzed, press any key, then click enter to exit." << endl;
      cin >> exitProgram;
      break;
    }

// if all cells are dead, exit loop and termiante program
    if (emptyCounter == totalNumCells)
    {
      isEmpty = true;
      outFS << "World is empty." << endl;
      cout << "World is empty, press any key, then click enter to exit." << endl;
      cin >> exitProgram;
      break;
    }

// reflect changes made on board during neighbor check onto secondBoard and loop again 
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        secondBoard[i][j] = board[i][j];
      }
    }
  }
  //delete helper;
  delete secondBoard;
  delete sameBoardChecker;
  outFS.close();
}

// runs the doughnut game mode and takes in a string pause parameter to check if user wants pauses between generations
// passes original gameboard as parameter
void Gameboard::playDoughnutMode(string pause, char** board)
{
  Gameboard *helper = new Gameboard();

// secondBoard used to count neighbors and make changes on the original board
  char **secondBoard = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    secondBoard[i] = new char[column];
  }

//sameBoardChecker is a third gameboard used to help check for oscilation
  char **sameBoardChecker = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    sameBoardChecker[i] = new char[column];
  }

  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      secondBoard[i][j] = board[i][j];
      sameBoardChecker[i][j] = board[i][j];
    }
  }

// output file
  string fileName = helper->getFileName();

  ofstream outFS;
  outFS.open(fileName);

//loop is used to iterate over the entire gamboard and count neighbors, update board as needed while checking for stabilization and oscilation
  while ((isEmpty == false) || (stabilzed == false))
  {
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        int numNeighbors = 0;
// calls countNeighbors() function from doughnut class
// passes the second (copy) board, board dimensions, and current position on the gameboard board [i][j]
// count all dead cells
        numNeighbors = helper->countNeighbors(secondBoard, row, column, i, j);
        if (numNeighbors <= 1)
        {
          board[i][j] = '-';
          emptyCounter++;
        }
        else if (numNeighbors == 2)
        {
          if (secondBoard[i][j] == '-')
          {
            board[i][j] = '-';
            emptyCounter++;
          }
          else if (secondBoard[i][j] == 'X')
          {
            board[i][j] = 'X';
          }
        }
        else if (numNeighbors == 3)
        {
          if (secondBoard[i][j] == '-')
          {
            board[i][j] = 'X';
          }
          else if (secondBoard[i][j] == 'X')
          {
            board[i][j] = 'X';
          }
        }
        else if (numNeighbors >= 4)
        {
          board[i][j] = '-';
          emptyCounter++;
        }
      }
    }

    // used to check for oscilation
    // update sameBoardChecker() every 2 generations
    if (generationNumber % 2 == 0)
    {
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < column; ++j)
        {
          sameBoardChecker[i][j] = secondBoard[i][j];
        }
      }
    }

    generationNumber++;

// output to file
    outFS << endl;
    cout << endl;
    outFS << "Generation Number: " << generationNumber << endl;
    cout << "Generation Number: " << generationNumber << endl;
    outFS << endl;
    cout << endl;

    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        cout << secondBoard[i][j] << " ";
        outFS << secondBoard[i][j] << " ";
      }
      cout << endl;
      outFS << endl;
    }

// if user wants pauses between each generation during output, they will be prompted to press a key to output the next generation
    if (pause == "pause" || pause == "Pause")
    {
      string pauseStr = "";
      cout << "Press any key and enter to continue." << endl;
      cin >> pauseStr;
    }

    int numCellsOnBoard = 0;
    int totalNumCells = row * column;

// counts the number of cells equal in both board and secondBoard
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        if (board[i][j] == secondBoard[i][j])
        {
          numCellsOnBoard++;
        }
      }
    }

// oscilation check
// check the amount of cells equal in both board and sameBoardChecker which is holding the second to last generation
    int cellCount = 0;
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        if (board[i][j] == sameBoardChecker[i][j])
        {
          cellCount++;
        }
      }
    }

// if all the cells are equal between the second to last and current game board then there is a sign of oscilation, terminate loop and program
    if (cellCount == totalNumCells)
    {
      stabilzed = true;
      outFS << "World is stabilzed." << endl;
      cout << "World is stabilzed, press any key, then click enter to exit." << endl;
      cin >> exitProgram;
      break;
    }

// if all cells are equal in consecutive generations then exit loop and terminate program
    if (numCellsOnBoard == totalNumCells)
    {
      stabilzed = true;
      outFS << "World is stabilzed." << endl;
      cout << "World is stabilzed, press any key, then click enter to exit." << endl;
      cin >> exitProgram;
      break;
    }

// if all cells on gameboard are dead then exit loop and terminate program
    if (emptyCounter == totalNumCells)
    {
      isEmpty = true;
      outFS << "World is empty." << endl;
      cout << "World is empty, press any key, then click enter to exit." << endl;
      cin >> exitProgram;
      break;
    }

// transfer all the changes on board from the neighbor check onto secondBoard and loop again
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        secondBoard[i][j] = board[i][j];
      }
    }
  }
  //delete helper;
  delete secondBoard;
  delete sameBoardChecker;
  outFS.close();
}

// runs the classic game mode and takes in a string pause parameter to check if user wants pauses between generations
// passes original gameboard as parameter
void Gameboard::playClassicMode(string pause, char** board)
{
    Gameboard *file = new Gameboard();

// newBoard used to count neighbors and make changes on the original board
    char **newBoard = new char*[row];

    for (int i = 0; i < row; ++i)
    {
      newBoard[i] = new char[column];
    }

    //sameBoardChecker is a third gameboard used to help check for oscilation
    char **sameBoardChecker = new char*[row];

    for (int i = 0; i < row; ++i)
    {
      sameBoardChecker[i] = new char[column];
    }

//copy original board to newBoard and sameBoardChecker
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
      {
        newBoard[i][j] = board[i][j];
        sameBoardChecker[i][j] = board[i][j];
      }
    }

// output file
    string fileName = file->getFileName();

    ofstream outFS;
    outFS.open(fileName);

//loop is used to iterate over the entire gamboard and count neighbors, update board as needed while checking for stabilization and oscilation
    while ((isEmpty == false) || (stabilzed == false))
    {
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < column; ++j)
        {
          int numNeighbors = 0;
// use classic class function to count number of neighbors based on which cell is being examined
          numNeighbors = file->numberOfNeighbors(newBoard, row, column, i, j);
//update board based on the number of neighbors
// if the cell being examined is dead then add one to emptyCounter
          if (numNeighbors <= 1)
          {
            board[i][j] = '-';
            emptyCounter++;
          }
          else if (numNeighbors == 2)
          {
            if (newBoard[i][j] == '-')
            {
              board[i][j] = '-';
              emptyCounter++;
            }
            else if (newBoard[i][j] == 'X')
            {
              board[i][j] = 'X';
            }
          }
          else if (numNeighbors == 3)
          {
            if (newBoard[i][j] == '-')
            {
              board[i][j] = 'X';
            }
            else if (newBoard[i][j] == 'X')
            {
              board[i][j] = 'X';
            }
          }
          else if (numNeighbors >= 4)
          {
            board[i][j] = '-';
            emptyCounter++;
          }
        }
      }

// used to check for oscilation
// update sameBoardChecker() every 2 generations
      if (generationNumber % 2 == 0)
      {
        for (int i = 0; i < row; ++i)
        {
          for (int j = 0; j < column; ++j)
          {
            sameBoardChecker[i][j] = newBoard[i][j];
          }
        }
      }

      generationNumber++;

// ouputting to file
      outFS << endl;
      cout << endl;
      outFS << "Generation Number: " << generationNumber << endl;
      cout << "Generation Number: " << generationNumber << endl;
      outFS << endl;
      cout << endl;

      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < column; ++j)
        {
          cout << newBoard[i][j] << " ";
          outFS << newBoard[i][j] << " ";
        }
        cout << endl;
        outFS << endl;
      }
// if user wants breaks between outputting each generation then this check will prompt the user to press a key to continue to next generation
      if (pause == "pause" || pause == "Pause")
      {
        string pauseStr = "";
        cout << "Press any key and enter to continue." << endl;
        cin >> pauseStr;
      }

      int numCellsOnBoard = 0;
      int totalNumCells = row * column;

// if board and newBoard are the same status on both boards then the generation stabilized
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < column; ++j)
        {
          if (board[i][j] == newBoard[i][j])
          {
            numCellsOnBoard++;
          }
        }
      }

// if most updated board is same as sameBoardChecker() in the same location, which holds the board from two previous generations, then increase cellCount by 1
      int cellCount = 0;
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < column; ++j)
        {
          if (board[i][j] == sameBoardChecker[i][j])
          {
            cellCount++;
          }
        }
      }

// if all cells between board and sameBoardChecker are the same then there is oscilation and the generation stabilized
      if (cellCount == totalNumCells)
      {
        stabilzed = true;
        outFS << "World is stabilzed." << endl;
        cout << "World is stabilzed, press any key, then click enter to exit." << endl;
        cin >> exitProgram;
        break;
      }

// if newBoard and board are equal in every cell location then two consecutive generations are the same and the generation stabilized
      if (numCellsOnBoard == totalNumCells)
      {
        stabilzed = true;
        outFS << "World is stabilzed." << endl;
        cout << "World is stabilzed, press any key, then click enter to exit." << endl;
        cin >> exitProgram;
        break;
      }

//if the gameboard is empty then all cells in the generation died and the program terminates
      if (emptyCounter == totalNumCells)
      {
        isEmpty = true;
        outFS << "World is empty." << endl;
        cout << "World is empty, press any key, then click enter to exit." << endl;
        cin >> exitProgram;
        break;
      }

// if none of the checks are met then transfer the changes on board from the neighbor checks to newBoard and loop again
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < column; ++j)
        {
          newBoard[i][j] = board[i][j];
        }
      }
    }
    //delete file;
    delete newBoard;
    delete sameBoardChecker;
    outFS.close();
}
