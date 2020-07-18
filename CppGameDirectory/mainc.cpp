#include <iostream>
#include <string>
#include<vector>


struct myGames//Struct data type to build a new game
{
	std::string genre, name;
	int yearReleased, score;
};

class gameMaker //A class data type that contains methods, and the data structure to hold the structs of myGames.
{
private:
	std::vector<myGames> gameVec;//Data structure to hold the games
	int headP, tailP, count;//Optional pointers in case they are needed.

public:
	gameMaker() :headP(0), tailP(gameVec.size() - 1), count(0), gameVec(0)//Initializers to initialize gamemaker before it's called. Includes optional pointers for later usage.
	{}

	void addToVec(myGames* game) //Function to, as the name states, add the struct to the vector of structs.
	{
		gameVec.push_back(*game);//Push back the passed struct to the array.
		std::cout << "The game has been added to vector\n\n";//Relay to user it was added.
		mainMenu();//Back to main menu.
	}

	void readGames() //Lists games in array, which offers a much cheaper way of showing the directory of an element.
	{
		if (gameVec.size() != 0)//If there are elements in the array...
		{
			for (int i= 0; i < gameVec.size(); i++) // Cycling through them.
			{
				std::cout << "Game Name: " << gameVec[i].name << "\n" // print everything for each index.
					<< "Game Genre: " << gameVec[i].genre << "\n"
					<< "Game Year: " << gameVec[i].yearReleased << "\n"
					<< "Game Score: " << gameVec[i].score << "\n"
					<< "Game Index: "
					<< i << "\n\n";

				mainMenu(); //Back to Main Menu
			}
		}
		else
		{
			std::cout << "There are no games here!\n"; // Else display an error message.
			return;//Go Back to the menu.
		}
	}

	void removeAuxFunc(std::string str, int i) //Devcided to use recursion here instead of another loop, thus why this function is labeled 'removeAuxFunc'
	{
		if (gameVec[i].name == str)//if the name at the specified element matches the one at the specific position
		{
			gameVec.erase(gameVec.begin() + i); //Erase the element
			std::cout << str << " has been removed.\n";//Inform user it was removed.
			mainMenu();//Main menu.
		}
		else if (i == gameVec.size())// Otherwise if it reaches the end
		{
			std::cout << "Game could be not be found.\n";//inform user it was not in the vector.
			mainMenu();
			
		}
		else
		{
			removeAuxFunc(str, i++);//Otherwise do some recurshion, call the function but progess i.
		}
	}

	void removeGame()//Self explanatory.  Recieves a name of a game to remove and passes it to the auxilary function.
	{
		std::string gameToRemove;
		std::cout << "Enter a game to remove.\n";
		std::getline(std::cin, gameToRemove);
		removeAuxFunc(gameToRemove, 0);
	}

	void addGame()
	{
		myGames* tmpGame = new myGames; // new temporary struct

		while (1) // infinite loop but can use break to escape it.
		{
			int yearTemp, scoreTemp; // A few temp variables.
			std::string genreTemp, nameTemp;

			std::cout << "Enter a year.\n";
			std::cin >> yearTemp;
			if (std::cin.fail()) // If the input fails or does not match the type...
			{
				std::cout << "incorrect entry\n"; //Tell user.
				std::cin.clear();//Clear input
				std::cin.ignore(100, '\n');//Pause to prevent infinite loop.
				std::cin >> yearTemp;//Request input again.
			}
			else { tmpGame->yearReleased = yearTemp; }//If it's good, store it.

			std::cout << "Enter your score for the game.\n";
			std::cin >> scoreTemp;
			if (std::cin.fail())//Same as above.
			{
				std::cout << "incorrect entry\n";
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cin >> scoreTemp;
			}
			else { if (scoreTemp > 10) { scoreTemp = 10; } tmpGame->score = scoreTemp; }//Set score to 10 to prevent user from putting in a higher number.
			std::cin.ignore();
			std::cout << "Enter a genre. \n";
			std::getline(std::cin, genreTemp);
			tmpGame->genre = genreTemp;//Same as above, get input, store it.

			std::cout << "Enter the name of the game.\n";
			std::getline(std::cin, nameTemp);
			tmpGame->name = nameTemp;
			addToVec(tmpGame);

		}

	}

	void mainMenu()//Menu that encases a switch to ask for user to select an option, informs of invalid input if nothing matches.
	{
		bool exit = false;
		int menuSwitch = 0;
		std::cout << "Input a number corresponding to the options below to continue.\nType 'exit' to continue\n";
		std::cout << "1)Add Game\n2)Remove Game\n3)Display Games\nInput: ";
		while (exit == false)
		{
			std::cin >> menuSwitch;
			std::cin.ignore();
			switch (menuSwitch)
			{
			case 1:
				addGame();
				break;

			case 2:
				removeGame();
				break;

			case 3:

				readGames();
				break;

			default:
				std::cout << "No valid input detected";
				break;
			}
		}
	}
};


int main() {
	std::cout << "=========================================================\n";
	std::cout << "|	          YOUR    PERSONAL                      |\n";
	std::cout << "|                     GAME                              |\n";
	std::cout << "|                   DIRECTORY                           |\n";
	std::cout << "=========================================================\n";
	gameMaker maker;

	//new gameMaker class, call the main menu method.
	maker.mainMenu();

}