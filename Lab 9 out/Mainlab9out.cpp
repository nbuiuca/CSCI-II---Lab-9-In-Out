//Nhan Bui
//Lab 9 out
#include <iostream>
#include <ctime>
#include "graph1.h"
#include "Wordgame.h"
using namespace std;
int main()
{
	int rand_no = 0;
	string fn;
	char repeat = 'y';
	WordGame WordGame;
	int totalScore = 0;
	int val = 0;

	//Display graphics
	displayGraphics();

	//Initialize random # generator
	srand(time(0));
	do
	{

		//Generate random #
		rand_no = rand() % 1149;

		cout << "Enter filename that contains words: "; //prompt file name
		cin >> fn;

		//Set the filename
		WordGame.setFileName(fn);

		//Set the word
		WordGame.setWord(rand_no);
		if (totalScore >= 0 && val != 0)
		{
			gout << setPos(100, 70) << setColor(0, 255, 0) << "Total Score: " << totalScore << endg;
		}


		//Draw the boxes
		WordGame.draw();

		//Play the game

		totalScore += WordGame.play();
		gout << setPos(100, 70) << setColor(0, 255, 0) << "Total Score:" << totalScore << endg;

		cout << "Repeat? (y/n): ";
		cin >> repeat;

		//Clear screen
		system("cls");
		clearGraphics();

		if (repeat == 'y' || repeat == 'Y')
		{
			val++;
		}

	} while ((repeat == 'y') || (repeat == 'Y'));
	return 0;
}
	
