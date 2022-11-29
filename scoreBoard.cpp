#include <iostream>

#include "scoreBoard.h"
using namespace std;

void ScoreBoard::printScores(int scoreP1, int scoreP2, string p1name, string p2name){
    cout << "--------------------------\n";
    cout << "\t\tSCOREBOARD\n";
    cout << "--------------------------\n";
    cout << "\t"<< p1name << "\t|\t\t" << scoreP1 << endl;
    cout << "--------------------------\n";
    cout << "\t"<< p2name << "\t|\t\t" << scoreP2 << endl;
    cout << "--------------------------\n" << endl;
}