#include "Tasks.h"
#include "Battleship.h"
#include <iostream>
#include <cstdlib>

void mainMenu()
{
	while (true)
	{
		system("CLS");
		std::cout
			<< "Welcome to my Compulsory 3!\n\n"
			<< "1: Change the password\n"
			<< "2: Login Window\n"
			<< "3: Play Battleship\n"
			<< "4: Quit\n"
			<< "Select and option (1-4)\n";

			int choice{ 0 };
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				changePassword();
				break;
			case 2:
				login();
				break;
			case 3:
				battleship();
				break;
			case 4:
				exit(0);
			return;
			default:
				break;
			}
	}
	return;
}