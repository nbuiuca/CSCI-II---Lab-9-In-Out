//Nhan Bui
//Lab 9 in
#include <iostream>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "Gamelab9in.h"

using namespace std;


Game::Game()
{
	fileName = "";
	word = "";
}


string Game::getFileName()
{
	return fileName;
}
void Game::setFileName(string fn)
{
	fileName = fn;

}
void Game::setWord(int rand_no)
{
	int counter = 0;
	fstream file;
	file.open(fileName, ios::in);
	if (!file.is_open())
	{
		cout << "Error, cannot open file. Try again\n";
		exit(-1);
	}
	while (true)
	{
		//Read a word
		file >> word;
		//if reach end of the file
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
	file.close();

}
string Game::getWord()
{
	return word;

}
void Game::draw()
{
	int i = 0;
	string nameword = "";
	string tail = ".bmp";
	string total = "";

	for (i = 0; i < strlen(word.c_str()); i++)
	{
		nameword = word[i];
		total = nameword + tail;

		displayBMP(&total[0], 100 + i * 36, 250);
	}
}


