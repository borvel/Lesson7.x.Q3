#include "io.h"
#include <iostream>
#include <limits>

void ignore_line()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int input_guess(const int guess_number)
{
	while (true) {
		std::cout << "Guess #" << guess_number << ": ";
		int num{};
		std::cin >> num;
		ignore_line();
		if (!std::cin)
		{
			std::cin.clear();
			ignore_line();
		}
		if (num > 0 && num < 101)
			return num;
		else std::cerr << "That input is invalid, please try again\n";
	}
}

void print_end_game(bool result, int winning_num)
{
	if (result)
		std::cout << "Correct! You win!\n";
	else std::cout << "Sorry, you lose.The correct number was " << winning_num << ".\n";
}

bool play_again()
{
	while (true)
	{
		std::cout << "Would you like to play again (y/n)?: ";
		char ans{};
		std::cin >> ans;

		ignore_line();
		if (!std::cin)
		{
			std::cin.clear();
			ignore_line();
		}

		switch (ans)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		}
	}
}

void print_lower()
{
	std::cout << "Your guess is too low.\n";
}

void print_higher()
{
	std::cout << "Your guess is too high.\n";
}

void print_welcome()
{
	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess.\n";
}