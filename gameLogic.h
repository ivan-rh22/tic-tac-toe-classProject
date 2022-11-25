#include <iostream>
#include <algorithm>

using namespace std;

class Player {
public:
    string name;
    int score;
    char playerToken;
    vector <int> playerMoves; 
};

//VARIABLES TO SET GAMEBOARD
char values[9];
const int posGroups = 8;
const int valsPerGroup = 3;


// checks if the game has ended in a draw
bool checkDraw(char values[9]){
    bool draw = true;
    for(int i = 0; i < 9; i++){
        if(values[i] == 'X' || values[i] == 'O'){
            draw = true;
        }
        else{
            draw = false;
            return draw;
        }
    }
    return draw;
}

//function to check if a player has won
bool checkWin(char currPlayer, Player p1, Player p2){
    bool win = false;
    bool matchFound = false;
    int i = 0;
    int v = 0;
    
    // using as a placeholder for the current set of values being checked
    vector<int> moves;

    // determine which player is being checked and brings out their correspondin inputs
    if(currPlayer == 'X' && p1.playerToken == 'X'){
        moves = p1.playerMoves;
    }
    else if(currPlayer == 'O' && p1.playerToken == 'O'){
        moves = p1.playerMoves;
    }
    else{
        moves = p2.playerMoves;
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
            else if(i == 8){
                i = 0;
                v++;
            }
            // if none of the above are true we break the loop and win
            else{
                break;
            }
        }
    }
    return win;
}

