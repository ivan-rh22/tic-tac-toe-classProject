#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
//header files
#include "game.h"
using namespace std;

void Game::preGameSetUp(){
  cout << "Player 1 please enter your name: " << endl;
  cin >> player1.name;
  cout << "Player 2 please enter your name: " << endl;
  cin >> player2.name;
  cout << "Welcome " << player1.name << " and " << player2.name << endl;

  scores.printScores(player1.score, player2.score, player1.name, player2.name);
}

void Game::gameSetup(){
  //ensures that the game board is empty before starting the game
  board.clearGame();
  //clears vectors that store positions for each player before the game
  player1.playerMoves.clear();
  player2.playerMoves.clear();
  //choose what they want to play as
  int choice;
  cout << player1.name << " what would you like to play as:\n" << "press 1 for 'x'\n" << "press 2 for 'o'" << endl;
  cin >> choice;
  while(choice > -1){
    if (choice == 1){
      player1.playerToken = 'X';
      player2.playerToken = 'O';
      currPlayer = player1.playerToken;
      break;
    }
    else if (choice == 2){
      player1.playerToken = 'O';
      player2.playerToken = 'X';
      currPlayer = player2.playerToken;
      break;
    }
    else{
      system("clear");
      cout << "Wrong input, try again" << endl;
      cout << player1.name << " what would you like to play as:\n" << "press 1 for 'x'\n" << "press 2 for 'o'" << endl;
      cin >> choice;
    }
  }
  board.printBoard();
}

bool Game::checkEmpty(int input){
  bool empty = false;
  if(board.values[input-1] != 'X' && board.values[input-1] != 'O'){
    updatePos(input);
    empty = true;
  }
  else{
    cout << "Oops. Try again, that spot has already been taken." << endl;
    empty = false;
    gamePlay();
  }
  return empty;
}

void Game::updatePos(int input){
  board.updateGameBoard(input, currPlayer);
  if(currPlayer == 'X' && player1.playerToken == 'X'){
    player1.playerMoves.push_back(input);
  }
  else if (currPlayer == 'O' && player1.playerToken == 'O'){
    player1.playerMoves.push_back(input);
  }
  else{
    player2.playerMoves.push_back(input);
  }
}

bool Game::gamePlay(){
  bool endGame;
  int currPlayerInput;
  
  cout << currPlayer << " make your move" << endl;
  cin >> currPlayerInput;
  //check if spot is empty
  if(checkEmpty(currPlayerInput) == true){
    endGame = checkWin();
    if(currPlayer == 'X'){
      currPlayer = 'O';
    }
    else if(currPlayer == 'O'){
      currPlayer = 'X';        
    }
  }
  return endGame;
}

bool Game::checkWin(){
  bool win = false;
  bool matchFound = false;
  const int posGroups = 8;
  const int valsPerGroup = 3;
  int i = 0;
  int v = 0;
    
  // using as a placeholder for the current set of values being checked
  vector<int> moves;

  // determine which player is being checked and brings out their correspondin inputs
  if(currPlayer == 'X' && player1.playerToken == 'X'){
     moves = player1.playerMoves;
  }
  else if(currPlayer == 'O' && player1.playerToken == 'O'){
    moves = player1.playerMoves;
  }
  else{
    moves = player2.playerMoves;
  }
    
  // sorts array of moves (least to greatest) that the current player has made
  sort(moves.begin(), moves.end());
    
  // possible solutions
  int solutions [posGroups][valsPerGroup] = {{1, 2, 3}, {1, 4, 7}, {1, 5, 9}, {2, 5, 8}, {3, 5, 7}, {3, 6, 9}, {4, 5, 6}, {7, 8, 9}};
    
  // only checks if there is enough values to compare
  if(moves.size() >= 3){
    // loop to compare each set to the current amount of values
    while(matchFound == false){
      //find array that matches first val with the current 'v' value
      if(moves.at(v) != solutions[i][0] && i < 8){
        i++;
      }
      else if (moves.at(v) == solutions[i][0]){
      // these values will serves as placeholders for the values that will be compared
        int val1 = solutions[i][0];
        int val2 = solutions[i][1];
        int val3 = solutions[i][2];
        // check if these values exist in the 'moves' vector
        if(count(moves.begin(), moves.end(), val1) && count(moves.begin(), moves.end(), val2) && count(moves.begin(), moves.end(), val3)){
          matchFound = true;
          win = true;
          break;
        }
        // if the set does not match we try with the next set only if the first vals match
        else if(moves.at(v) == solutions[i+1][0] && i < 8){
          i++;
        }
        // if the first vals do not match we try starting from the second value in moves vector
        else if(v < moves.size() - 1){
          i = 0;
          v++;
        }
        else{
          break;
        }
      }
      else if(i == 8 && v < moves.size() - 1){
        i = 0;
        v++;
      }
      // if none of the above are true we break the loop
      else{
        break;
      }
    }
  }
  if(win == true){
    system("clear");
    updateScores();
    scores.printScores(player1.score, player2.score, player1.name, player2.name);
    cout << currPlayer << " wins!" << endl;
  }
  return win;
}

bool Game::checkDraw(){
  char values[9];
  for(int i = 0; i < 9; i++){
    values[i] = board.values[i];
  }
  bool draw = true;
  for(int i = 0; i < 9; i++){
    if(values[i] == 'X' || values[i] == 'O'){
      draw = true;
    }
    else{
      draw = false;
      break;
    }
  }
  if(draw == true){
    cout << "DRAW" << endl;
  }
  return draw;
}

void Game::updateScores(){
  if(currPlayer == 'X' && player1.playerToken == 'X'){
    //update score
    player1.score += 1;
  }
  else if(currPlayer == 'O' && player1.playerToken == 'O'){
    //update score
    player1.score += 1;
  }
  else{
    //update score
    player2.score += 1;
  }
}

// GAMES class
bool Game::newGame(){
  char newGameChoice;
  bool choice;
  cout << "Would you like to play another game?\n(Press 'y' for yes and 'n' for no)" << endl;
  cin >> newGameChoice;
  
  if(newGameChoice == 'y')
    choice = true;
  else{
    choice = false;
    system("clear");
    cout << "\t\tGAME OVER" << endl;
    scores.printScores(player1.score, player2.score, player1.name, player2.name);
  }
  return choice;
}