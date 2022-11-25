#include <iostream>
#include <vector>
#include <stdlib.h>

//#include "Player.h"
#include "gameLogic.h"


using namespace std;

//VARIABLES

Player player1;
Player player2;
char currPlayer;
bool game = true;
bool win = false;


void gameplay();

void scoreboard(){
    cout << "--------------------------\n";
    cout << "        SCOREBOARD        \n";
    cout << "--------------------------\n";
    cout << "   "<< player1.name << "       |      " << player1.score << endl;
    cout << "--------------------------\n";
    cout << "   "<< player2.name << "       |      " << player2.score << endl;
    cout << "--------------------------\n" << endl;
}


void gameBoard(){
    //print game board
    system("clear");
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

void updateGameBoard(int input){
    if( values[input-1] != 'X')
    values[input - 1] = currPlayer;
    gameBoard();
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

bool emptyCheck(int input){
    bool empty = false;
    if(values[input-1] != 'X' && values[input-1] != 'O'){
        updateGameBoard(input);
        empty = true;
    }
    else{
        cout << "Oops. Try again, that spot has already been taken." << endl;
        empty = false;
        gameplay();
    }
    return empty;
}

void gameplay(){
    int currPlayerInput;
    cout << currPlayer << " make your move" << endl;
    cin >> currPlayerInput;
    if(emptyCheck(currPlayerInput) == true){
        win = checkWin(currPlayer, player1, player2);
        if(win == false){
            //swith between players if spot was empty
            if(currPlayer == 'X'){
                currPlayer = 'O';
            }
            else{
                currPlayer = 'X';
            }
        }
    }
}

void clearGame(){
    //sets values shown on the gameboard
    char vals [9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 9; i++){
        values[i] = vals[i];
    }
    player1.playerMoves.clear();
    player2.playerMoves.clear();
}

void preGameSetup(){
    // intro
    cout << "Player 1 please enter your name: " << endl;
    cin >> player1.name;
    cout << "Welcome " << player1.name << endl;
    cout << "Player 2 please enter your name: " << endl;
    cin >> player2.name;
    cout << "Welcome " << player2.name << endl;
    cout << "\n------------------------\n" << endl;
}

void gameSetup(){
    //ensures that the game board is empty before starting the game
    clearGame();
    //choose what they want to play as
    int choice;
    cout << player1.name << " what would you like to play as:\n" << "press 1 for 'x'\n" << "press 2 for 'o'" << endl;
    cin >> choice;
    if (choice == 1){
        player1.playerToken = 'X';
        player2.playerToken = 'O';
        currPlayer = player1.playerToken;
    }
    else if (choice == 2){
        player1.playerToken = 'O';
        player2.playerToken = 'X';
        currPlayer = player2.playerToken;
    }
    else{
        cout << "Wrong input, try again" << endl;
    }
    //print gameboard before game starts
    gameBoard();
}



int main(){
    char wantNewGame;
    
    //sets name for each player
    preGameSetup();
    // player chooses their tooken
    gameSetup();
    
    int numTurns = 0;
    // keep game running until it returns false
    while (game == true){
        win = checkWin(currPlayer, player1, player2);
        if (win == true){
            cout << currPlayer << " wins!" << endl;
            //ask if they want to play another game
            cout << "Would you like to play another game?\n(Press 'y' for yes and 'n' for no)" << endl;
        // updates scores and asks user if they want to play another game
            if(currPlayer == 'X' && player1.playerToken == 'X'){
                //update score
                player1.score += 1;
                // takes input that determins if a new game will be played
                cin >> wantNewGame;
                //shows updated scoreboard
                scoreboard();
                // determines if a new game will be played
                if(wantNewGame == 'y'){
                    //restart game
                    gameSetup();
                    numTurns = 0;
                }
                else{
                    game = false;
                    break;
                }
            }
            else if(currPlayer == 'O' && player1.playerToken == 'O'){
                //update score
                player1.score += 1;
                //takes input that determines if a new game will be played
                cin >> wantNewGame;
                //shows updated scoreboard
                scoreboard();
                //determines if new game will be played
                if(wantNewGame == 'y'){
                    //restart game
                    gameSetup();
                    numTurns = 0;
                }
                else{
                    game = false;
                    break;
                }
            }
            else{
                //update score
                player2.score += 1;
                //takes input that determines if new game will be played
                cin >> wantNewGame;
                //shows updated scoreboard
                scoreboard();
                //determines if a new game will be played
                if(wantNewGame == 'y'){
                    //restart game
                    gameSetup();
                    numTurns = 0;
                }
                else{
                    game = false;
                    break;
                }
            }
        }
        
    // check if game ended in a draw
        if(numTurns == 9 && checkDraw(values) == true && win == false){
            cout << "Draw" << endl;
            cout << "Would you like to play another game?\n(Press 'y' for yes and 'n' for no)" << endl;
            
        // determine if new game will be played
            cin >> wantNewGame;
            if(wantNewGame == 'y'){
                //restart game
                gameSetup();
                numTurns = 0;
            }
            else{
                game = false;
                scoreboard();
                break;
            }
        }
        // this function runs the game
        gameplay();
        
        //keeps track of the number of turns
        numTurns++;
    }
}

