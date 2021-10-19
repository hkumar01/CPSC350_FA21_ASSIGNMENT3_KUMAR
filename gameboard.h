// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 3

// Game class implements start-up configurations, game board creation, and all three game modes

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <string>
#include <fstream>
#include "classic.h"
#include "doughnut.h"
#include "mirror.h"

using namespace std;

class Gameboard : public Classic, public Doughnut, public Mirror
{
  public:
    Gameboard();
    ~Gameboard();
    void randomBoard();
    void fileBoard(string inputFile);
    char** board;
    void start();
    int row;
    int column;
    void playClassicMode(string pause, char** board);
    void runGame();
    string getFileName();
    void playDoughnutMode(string pause, char** board);
    void playMirrorMode(string pause, char** board);
  private:
    float popDensity;
    bool popDensityOk;
    float numGenerator;
    string boardSelection;
    string gamemodeSelection;
    string pause;
    int generationNumber = 0;
    bool isEmpty = false;
    bool stabilzed = false;
    int emptyCounter = 0;
    string fileName;
    string exitProgram = "";
};

#endif
