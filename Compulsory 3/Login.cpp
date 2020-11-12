#include "Tasks.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

const int passRows{ 4 };
const int passColumns{ 4 };
bool firstRun{ true };

char passwordArray[passRows][passColumns]
{
{'A', 'B', 'C', 'D'},
{'E', 'F', 'G', 'H',},
{'I', 'J', 'K', 'L'},
{'M', 'N', 'O', 'P'}
};
std::vector <int> position{ 0,0 };

char passwordAnswer[10]{ passwordArray[position[0]][position[1]] };

std::string inputPassword = "ABCDHLPONM";
std::string password;
int guesses{ 0 };

void writePasswordToFile()
{
	std::ofstream passwordFile{ "Password.txt" };

	if (!passwordFile)
	{
		std::cerr << "Uh oh, Password.txt could not be opened for writing!" << std::endl;

	}

	else
	{
		passwordFile << inputPassword;
	}

	passwordFile.close();
}

void getPasswordFromFile()
{
	std::ifstream passwordFile{ "Password.txt" };

	if (!passwordFile)
	{
		std::cerr << "Uh oh, Password.txt could not be opened for reading!" << std::endl;
	}

	while (passwordFile)
	{
		std::string GetPassword;
		passwordFile >> password;
	}

	passwordFile.close();
}

void changePassword()
{
	while (true)
	{
		system("CLS");
		std::cout << "Input your new password. It must be max 10 characters long, and from A to P: ";
		std::cin >> inputPassword;
		transform(inputPassword.begin(), inputPassword.end(), inputPassword.begin(), ::toupper);

		if (inputPassword.length()>10)
		{
			system("CLS");
			std::cout << "Too long password, try again.\n";
			system("PAUSE");
		}
		
		else
		{
			for (int i = 0; i < inputPassword.length(); i++)
			{
				if (inputPassword[i]>='A' && inputPassword[i]<='P')
				{
					system("CLS");
					std::cout << "Password successfully changed.\n";
					std::cout << "New password is: " << inputPassword << "\n";
					system("PAUSE");
					mainMenu();
				}

				else
				{
					system("CLS");
					std::cout << "Password contains unsupported characters. Please try again.\n";
					system("PAUSE");
				}

			}
		}

	}



}

void PasswordMove()
{
	bool success{ true };
	success = true;
		char input = _getch();
		switch (input)
		{
		case 'w':
			if (position[0] != 0)
			{
				position[0]--;
				break;
			}
			else
			{
				success = false;
				break;
			}
			
		case 'a':
			if (position[1] != 0)
			{
				position[1]--;
				break;
			}
			else
			{
				success = false;
				break;
			}
		case 's':
			if (position[0] != 3)
			{
				position[0]++;
				break;
			}
			else
			{
				success = false;
				break;
			}
		case 'd':
			if (position[1] != 3)
			{
				position[1]++;
				break;
			}
			else
			{
				success = false;
				break;
			}
			break;
		default:
			break;

		
		}
		
		if (success==true)
		{

			guesses++;
			passwordAnswer[guesses] = passwordArray[position[0]][position[1]];
			passwordArray[position[0]][position[1]] = 'X';

		}
		else
		{
			std::cout << "\n\n\t\tOut of bounds. Please try again.";
			system("PAUSE");
		}

		
}

void displayLogin()
{
	std::cout
		<< "\n\n\n\t\t\t\t    Compulsory 3: Login window\n\n"
		<< "\t\t-----------------------------------------------------------------\n";

		for (int i = 0; i < passRows; i++)
		{
			std::cout << "\t\t";
			for (int j = 0; j < passColumns; j++ )
			{
				std::cout << "|\t" << passwordArray[i][j] << "\t";

			}
			std::cout << "|\n\t\t|---------------------------------------------------------------|\n";

		}

	
}

void resetBoard()
{
	for (int i = 0; i < 10; i++)
	{
		passwordAnswer[i] = 'A';

	}
	position[0] = 0;
	position[1] = 0;

	guesses = 0;
	char letter{ 'A' };
	for (int i = 0; i < passRows; i++)
	{
		for (int j = 0; j < passColumns; j++)
		{
			passwordArray[i][j] = letter;
			letter++;
		}
	}

}

void checkCorrect()
{
	int correctGuesses{ 0 };
	for (int i = 0; i < password.length(); i++)
	{
		if (passwordAnswer[i]==password[i])
		{
			correctGuesses++;
		}
	}

	if (correctGuesses==password.length())
	{
		for (int i = 0; i < passRows; i++)
		{
			for (int j = 0; j < passColumns; j++)
			{
				passwordArray[i][j] = 'X';
			}
		}

		system("CLS");
		displayLogin();
		std::cout << "\n\t\t\t\t\tCorrect password!\n\t\t\t\tPress a key to go to the main menu! ";
		char something = _getch();
		mainMenu();
	}




}

void login()
{

	writePasswordToFile();
	firstRun = false;
	resetBoard();
	passwordArray[position[0]][position[1]] = 'X';
	getPasswordFromFile();
	while (true)
	{
		system("CLS");
		displayLogin();
		std::cout << "\n\t\tPassword guessed:";

		for (int i = 0; i <= guesses; i++)
		{
			std::cout << " " << passwordAnswer[i];

		}
		PasswordMove();
		checkCorrect();

	}
	

/*
	std::vector<int> passwordVector{ 1,2,3 };

	for (int i = 0; i < passwordVector.size(); i++)
	{

	}*/
}

