#include <iostream>
#include <vector>

#include "Player.h"
#include "gameBoard.cpp"
#include "scoreBoard.cpp"
using namespace std;

class Game{
private:
Player player1;
Player player2;
char currPlayer;
GameBoard board;
ScoreBoard scores;



public:
void preGameSetUp();
void gameSetup();
void updatePos(int input);
bool checkEmpty(int input);
bool gamePlay();
bool checkWin();
bool checkDraw();
void updateScores();
bool newGame();
};