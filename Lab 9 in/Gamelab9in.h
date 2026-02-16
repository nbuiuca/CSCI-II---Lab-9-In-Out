//Lab 9in 
//Nhan Bui
#ifndef GAME_H
#define GAME_H
#include <string>|
using namespace std;
class Game
{
private:
    string fileName;
    string word;


public:
    Game();
    string getFileName();
    void setFileName(string fn);
    void setWord(int rand_no);
    string getWord();
    void draw();
};

#endif

