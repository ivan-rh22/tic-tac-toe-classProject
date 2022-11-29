#include <iostream>
#include <vector>

#include "game.h"
using namespace std;



int main(){
  vector<Game> gamesPlayed;

  bool gameEnd = false;
  int numTurns = 0;
  
  Game currGame;
  currGame.preGameSetUp();
  currGame.gameSetup();
  
  while(gameEnd == false){
    gameEnd = currGame.gamePlay();
    numTurns++;
    
    if(gameEnd == true){
      if(currGame.newGame() == false){
        break;
      }
      else{
        numTurns = 0;
        gameEnd = false;
        gamesPlayed.push_back(currGame);
        currGame.gameSetup();
      }
    }
    //if game has ended in draw
    else if(numTurns == 9 && currGame.checkDraw() == true){
      if(currGame.newGame() == false){
        break;
      }
      else{
        numTurns = 0;
        gamesPlayed.push_back(currGame);
        currGame.gameSetup();
      }
    }
  }
}