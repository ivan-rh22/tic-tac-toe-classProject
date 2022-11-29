#include "scoreBoard.h"
using namespace std;

void ScoreBoard::printScores(int scoreP1, int scoreP2, string p1name, string p2name){
    cout << "--------------------------\n";
    cout << "\tSCOREBOARD\n";
    cout << "--------------------------\n";
    cout << p1name << "\t|\t" << scoreP1 << endl;
    cout << "--------------------------\n";
    cout << p2name << "\t|\t" << scoreP2 << endl;
    cout << "--------------------------\n" << endl;
}