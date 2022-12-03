#include <iostream>
#include <vector>

#include "game.cpp"
using namespace std;


int main(){
  bool gameEnd = false;
  int numTurns = 0;
  
  Game currGame;
  currGame.preGameSetUp();
  currGame.gameSetup();
  
  while(gameEnd == false){
    gameEnd = currGame.gamePlay();
    numTurns++;
    
    if(gameEnd == true){
      currGame.addCurrGame(currGame);
      if(currGame.newGame() == false){
        currGame.previousGames();
        break;
      }
      else{
        numTurns = 0;
        gameEnd = false;
        currGame.gameSetup();
      }
    }
    //if game has ended in draw
    else if(numTurns == 9 && currGame.checkDraw() == true){
      currGame.addCurrGame(currGame);
      if(currGame.newGame() == false){
        currGame.previousGames();
        break;
      }
      else{
        numTurns = 0;
        currGame.gameSetup();
      }
    }
  }
}