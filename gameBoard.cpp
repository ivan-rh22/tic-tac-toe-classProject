#include <stdlib.h>
#include "gameBoard.h"
using namespace std;

void GameBoard::clearGame(){
  //sets values shown on the gameboard
  char vals [9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < 9; i++){
    values[i] = vals[i];
  }
}

void GameBoard::printBoard(){
  //clear screen before printing game board
  system("clear");
  //prints gameboard
  cout << "       |       |       \n";
  cout << "   " << values[0] << "   |   " << values[1] << "   |   " << values[2] << "   \n";
  cout << "_______|_______|_______\n";
  cout << "       |       |       \n";
  cout << "   " << values[3] << "   |   " << values[4] << "   |   " << values[5] << "   \n";
  cout << "_______|_______|_______\n";
  cout << "       |       |       \n";
  cout << "   " << values[6] << "   |   " << values[7] << "   |   " << values[8] << "   \n";
  cout << "       |       |       \n";
}

void GameBoard::updateGameBoard(int input, char currPlayer){
    values[input - 1] = currPlayer;
    printBoard();
}