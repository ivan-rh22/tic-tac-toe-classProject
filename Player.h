#include <iostream>
#include <vector>

using namespace std;

class Player {
public:
    string name;
    int score;
    char playerToken;
    vector <int> playerMoves; 

Player(){
  score = 0;
}
};