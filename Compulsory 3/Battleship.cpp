#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Battleship.h"
#include <cctype> 
#include <conio.h>

bool gameWon = false;
bool gameLost = false;

const int M = 6;
const int N = 6;
const char BLANK{ ' ' };
const char SHIP{ 'S' };
const char MISS{ 'M' };
const char HIT{ 'H' };
int shipsLeft;
player Player;


void makeEmptyBoard(char board[M][N])
{
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = BLANK;
		}
	}
}

int randomRow()
{
	int randomNumber = rand() % M ;
//	std::cout << randomNumber;
	return randomNumber;
}

int randomColumn()
{
	int randomNumber = rand() % N;
//	std::cout << randomNumber;
	return randomNumber;
}

void writeLetters()
{
	char letter{ 'A' };
	std::cout << "\t\t |";
	for (int i = 0; i < N; i++)
	{
		std::cout << letter++ << "|";;
	}
	std::cout << "\n";
}

void makeBoard(int numberOfShips, char board[M][N])
{
	int row = randomRow();
	int column = randomColumn();

	for (int i = 0; i < numberOfShips; i++)
	{
		if (board[row][column] == BLANK)
		{
			board[row][column] = SHIP;
		}
		row = randomRow();
		column = randomColumn();
	}

}

void printBoard(char board[M][N])
{
	int rowNumber{ M };

	std::cout << "\n\n";
	for (int i = 0; i < M; i++)
	{
		std::cout << "\t\t" << rowNumber-- << "|";
		for (int j = 0; j < N; j++)
		{
			std::cout << board[i][j] << "|";
		}
		std::cout << "\n";

	}
	std::cout << "\t\t -------------\n";
	writeLetters();
}

void printPlayerBoard(char board[M][N])
{
	int rowNumber{ M };

	std::cout << "\n\n";
	for (int i = 0; i < M; i++)
	{
		std::cout << "\t\t" << rowNumber-- << "|";
		for (int j = 0; j < N; j++)
		{
			if (board[i][j]==SHIP)
			{
			std::cout << BLANK << "|";
			} 
			else
			{
				std::cout << board[i][j] << "|";

			}
			
		}
		std::cout << "\n";

	}
	std::cout << "\t\t -------------\n";
	writeLetters();

}

void Welcome()
{
	std::cout << "\n\n\t    Welcome to Battleships!";
}

void printStats()
{
	std::cout
	<<"\n\t   Number of shots left: " << Player.numberOfShots
	<<"\n\t   Number of hits: " << Player.numberOfHits
	<<"\n\t   Number of ships left: " << shipsLeft << "\n";

}
void shoot(char board[M][N])
{
	std::string shot;
	int shotRowsInput;
	int shotRows;
	char shotColumnsInput;
	int shotColumns;

	std::cout
		<< "\n        What cell do you want to shoot?\n\t\t(Example: 2C)\n";
	do 
	{
		std::cout << "\n\t\t       ";

		std::cin >> shot;
		shotRowsInput = shot[0]-48;
		shotRows = M - shotRowsInput;
		shotColumnsInput = shot[1];
		shotColumnsInput = toupper(shotColumnsInput);
		shotColumns = (int)shotColumnsInput - 65;

		if (shotRows > M || shotRows < 0 || shotColumns > N || shotColumns < 0)
		{
			std::cout << "\nUnsupported input, please try again: ";
		}

	} while (shotRows > M || shotRows < 0 || shotColumns > N || shotColumns < 0);
	if (board[shotRows][shotColumns]==SHIP)
	{
		board[shotRows][shotColumns] = HIT;
		Player.numberOfHits++;
		Player.numberOfShots--;
	} 
	else if (board[shotRows][shotColumns] == BLANK)
	{
	board[shotRows][shotColumns] = MISS;
	Player.numberOfShots--;
	}
	else if (board[shotRows][shotColumns] == HIT)
	{
		Player.numberOfShots--;
	}
	
}

void battleship()
{
	srand(time(nullptr));
	char board[M][N];
	int numberOfShips{ 6};

	Player.numberOfShots = 20;
	makeEmptyBoard(board);
	makeBoard(numberOfShips, board);

	while (gameWon == false && gameLost == false)
	{
		system("CLS");
		shipsLeft = numberOfShips - Player.numberOfHits;
//		printBoard(board);
		Welcome();
		printPlayerBoard(board);
		printStats();
		shoot(board);
		if (Player.numberOfHits==numberOfShips)
		{
			gameWon = true;
		}
		else if (Player.numberOfShots == 0)
		{
			gameLost = true;
		}
	}
	system("CLS");

	if (gameWon)
	{
		std::cout << "\n\n\n\t\tYou won! Congratulations!\n\tPress a key to exit to the main menu: ";
		char something = _getch();
	} 
	else if (gameLost)
	{
		std::cout << "You lost!\nPress a key to exit to the main menu: ";
		char something = _getch();
	}

	return;
}