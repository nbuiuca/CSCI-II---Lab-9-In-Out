#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include "graph1.h"
#include "Wordgame.h"

WordGame::WordGame() {
	fileName = "";
	word = "";
}
string WordGame::getFileName() {
	return fileName;
}
void WordGame::setFileName(string fn) {
	this->fileName = fn;
}
void WordGame::setWord(int rand_no)
{
	int counter = 0;
	fstream file;
	file.open(fileName, ios::in);

	if (!file.is_open())
	{
		cout << "Error, cannot open the file! Try again";
		exit(-1);
	}

	while (true)
	{
		//Read a word

		file >> word;

		//Check the end of file

		if (file.eof())
		{
			break;
		}
		counter++;

		if (counter == rand_no)
		{
			break;
		}
	}
}

string WordGame::getWord()
{
	return word;
}

//Draws empty rectangles for two seconds

void WordGame::draw()
{
	int i = 0;
	int x = 100;
	int y = 200;

	for (i = 0; i < strlen(word.c_str()); i++)
	{
		drawRect(x, y, 32, 32);

		x += 36;
	}

	Sleep(2000);
}

// Play game accoring to the description

int WordGame::play()
{
	int i = 0;
	int x = 100;
	int y = 200;
	int count = 0;
	int guess = 0;
	int mem1 = 0;
	int mem2 = strlen(word.c_str()) - 1;
	int score = 0;
	string input;
	string nameword = "";
	string tail = ".bmp";
	string total = "";

	//Displays the first letter and vowels

	for (i = 0; i < strlen(word.c_str()); i++)
	{
		if (i == 0)
		{
			nameword = word[i];
			total = nameword + tail;

			displayBMP(&total[0], x, y);

			count++;
		}

		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
		{
			nameword = word[i];
			total = nameword + tail;

			displayBMP(&total[0], x + i * 36, y);
			count++;

			if (i == 0)
			{
				count--;
			}
		}
	}

	guess = strlen(word.c_str()) - count;

	//Display hints from left and right alternatively

	for (i = 0; i < guess; i++)
	{
		gout << setPos(100, 120) << setColor(0, 255, 0) << "Guess number: " << (i + 1) << endg;

		cout << "Guess #" << i + 1 << endl;
		cout << "What is the word? ";
		cin >> input;

		if (input == word)
		{
			score = (guess - (i)) * 10;

			gout << setPos(100, 100) << setColor(0, 255, 0) << "!!!CORRECT!!!" << endg;
			gout << setPos(100, 120) << setColor(0, 255, 0) << "Number of Guesses: " << i + 1 << endg;
			gout << setPos(100, 140) << setColor(0, 255, 0) << "Score: " << score << endg;

			break;

		}
		else
		{
			if (i % 2 == 0)
			{
				for (int j = mem1; j < strlen(word.c_str()); j++)
				{
					if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u' || j == 0)
					{
						mem1++;
					}
					else
					{
						gout << setPos(100, 100) << setColor(0, 255, 0) << "!!!INCORRECT!!!" << endg;
						gout << setPos(100, 120) << setColor(0, 255, 0) << "Guess number: " << (i + 1) << endg;
						nameword = word[j];
						total = nameword + tail;

						displayBMP(&total[0], x + j * 36, y);
						mem1++;

						break;
					}
				}
			}
			if (i % 2 == 1)
			{
				for (int j = mem2; j >= 0; j--)
				{
					if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u' || j == 0)
					{
						mem2--;
					}
					else
					{
						gout << setPos(100, 100) << setColor(0, 255, 0) << "!!!INCORRECT!!!" << endg;
						gout << setPos(100, 120) << setColor(0, 255, 0) << "Guess number: " << (i + 1) << endg;

						nameword = word[j];
						total = nameword + tail;

						displayBMP(&total[0], x + j * 36, y);
						mem2--;
						break;
					}
				}
			}
		}
		if (i + 1 == guess)
		{
			score = 0;

			gout << setPos(100, 100) << setColor(0, 255, 0) << "!!!GAME OVER!!!" << endg;
			gout << setPos(100, 120) << setColor(0, 255, 0) << "Correct answer: " << word << endg;
			gout << setPos(100, 140) << setColor(0, 255, 0) << "Score: " << score << endg;
		}
	}
	return score;
}