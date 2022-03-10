#include "TicTacToe.h"

// Constructor
TicTacToe::TicTacToe(int theTotalGames, double theTotalTime, double theSlowestTime, double theFastestTime, double theAverageTime, int theSlowestTimeMoveCount, int theFastestTimeMoveCount)
{
	totalGames = theTotalGames;
	totalTime = theTotalTime;
	slowestTime = theSlowestTime;
	fastestTime = theFastestTime;
	averageTime = theAverageTime;
	slowestTimeMoveCount = theSlowestTimeMoveCount;
	fastestTimeMoveCount = theFastestTimeMoveCount;
}

// Accessor
int TicTacToe::getTotalGames() const
{
	return totalGames;
}
double TicTacToe::getTotalTime() const
{
	return totalTime;
}
double TicTacToe::getSlowestTime() const
{
	return slowestTime;
}
double TicTacToe::getFastestTime() const
{
	return fastestTime;
}
double TicTacToe::getAverageTime() const
{
	return averageTime;
}
int TicTacToe::getSlowestTimeMoveCount() const
{
	return slowestTimeMoveCount;
}
int TicTacToe::getFastestTimeMoveCount() const
{
	return fastestTimeMoveCount;
}

// Mutator
void TicTacToe::setTotalGames(const int newTotalGames)
{
	totalGames = newTotalGames;
}
void TicTacToe::setTotalTime(const double newTotalTime)
{
	totalTime += newTotalTime;
}
void TicTacToe::setSlowestTime(const double newSlowestTIme)
{
	slowestTime = newSlowestTIme;
}
void TicTacToe::setFastestTime(const double newFastestTime)
{
	fastestTime = newFastestTime;
}
void TicTacToe::setAverageTime(const double newTotalGames, const double newTotalTime)
{
	averageTime = newTotalTime / newTotalGames;
}
void TicTacToe::setSlowestTimeMoveCount(const int newSlowestTimeMoveCount)
{
	slowestTimeMoveCount = newSlowestTimeMoveCount;
}
void TicTacToe::setFastestTimeMoveCount(const int newFastestTimeMoveCount)
{
	fastestTimeMoveCount = newFastestTimeMoveCount;
}

// Precondition: 
// Postcondition: The main process for TicTacToe
void TicTacToe::ticTacToeMenu()
{
	int numberOfGames = 0;
	int totalGameMoves;
	double endTime, time;
	bool winnerExist;
	bool playAgain = true;
	char choice;
	cout << "\tTic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game for two\n";
	cout << "\tplayers, X and O, who takes turns marking the spaces in a 3x3 grid. The player who\n";
	cout << "\tsucceeds in placing three of their marks in a horizontal, vertical, or diagonal\n";
	cout << "\trow wins the game.\n";
	cout << "\tThis tic-tac-toe program plays against the computer. Human player, X, will always\n";
	cout << "\tbe first. Time will be recorded for the fastest and the slowest game. Average time will\n";
	cout << "\tthen be calculated and displayed.\n\n";
	system("pause");

	do
	{
		// Begins the game here
		double startTime = clock();
		numberOfGames++;
		bool forfeit = false;
		setupBoard(winnerExist, totalGameMoves);
		do
		{
			// Player's move here
			inputMove(forfeit);
			totalGameMoves++;
			winnerExist = winCheck("User", totalGameMoves, forfeit);
			if (winnerExist == true) // breaks out of the game here if the user made a winning move
			{
				break;
			}
			// Computer's move here
			computersMove();
			totalGameMoves++;
			winnerExist = winCheck("Computer", totalGameMoves, forfeit);
		} while (!winnerExist);

		// Endgame records update
		endTime = clock();
		time = ((endTime - startTime) / double(CLOCKS_PER_SEC));
		TicTacToe::setTotalGames(numberOfGames);
		TicTacToe::setTotalTime(time);
		if (time < TicTacToe::getFastestTime())
		{
			TicTacToe::setFastestTime(time);
			TicTacToe::setFastestTimeMoveCount(totalGameMoves);
		}
		if (time > TicTacToe::getSlowestTime())
		{
			TicTacToe::setSlowestTime(time);
			TicTacToe::setSlowestTimeMoveCount(totalGameMoves);
		}

		choice = inputChar("\tDo you want to play again (Y - yes or N - no)? ", 'y', 'n');
		if (choice == 'N')
			playAgain = false;
	} while (playAgain);

	// More endgame record updates
	TicTacToe::setTotalGames(numberOfGames);
	TicTacToe::setAverageTime(totalGames, totalTime);
	// Prints out the updated records
	printRecords();

	system("pause");
	system("cls");
}

// Precondition: 
// Postcondition: Sets up a new game and resets the number of total game moves and existing winner
void TicTacToe::setupBoard(bool &winnerExist, int &totalGameMoves)
{
	winnerExist = false;
	totalGameMoves = 0;
	// Fill the 2d array with empty spots
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
	printBoard();
}

// Precondition: 
// Postcondition: Displays the current status of the game board
void TicTacToe::printBoard() 
{
	system("CLS");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t   1     2     3   \n";
	cout << "\t\t\t\t+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t      1 |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |\n";
	cout << "\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t      2 |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |\n";
	cout << "\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t      3 |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |\n";
	cout << "\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t+-----+-----+-----+\n";
};

// Precondition: 
// Postcondition: Checks if there are any winners
bool TicTacToe::winCheck(string currentPlayer, int totalGameMoves, bool forfeit)
{
	for (int i = 0; i < 3; i++)
	{
		// Checking if the rows match
		if ((board[i][0] != ' ') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			printBoard();
			cout << "\t" << currentPlayer << " is the winner!\n\n";
			return true;
		}
		// Checking if the columns match
		else if ((board[0][i] != ' ') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			printBoard();
			cout << "\t" << currentPlayer << " is the winner!\n\n";
			return true;
		}
		else if (forfeit)
		{
			printBoard();
			cout << "\t" << currentPlayer << " forfeit!\n\n";
			return true;
		}
		else
			continue;
	}
	// Checking if the diagonals match
	if ((board[0][0] != ' ') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		printBoard();
		cout << "\t" << currentPlayer << " is the winner!\n\n";
		return true;
	}
	else if (((board[0][2] != ' ') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])))
	{
		printBoard();
		cout << "\t" << currentPlayer << " is the winner!\n\n";
		return true;
	}
	else if (totalGameMoves == 9) // There cannot be more that 9 moves because there are only 9 available spaces
	{
		printBoard();
		cout << "\tThe game is a draw.\n\n";
		return true;
	}
	else
		printBoard();
		return false;
}

// Precondition: 
// Postcondition: Inputs the users move
void TicTacToe::inputMove(bool &forfeit)
{
	int row, col;
	row = inputInteger("\t\tPlease enter Row Numbers (or 0 to forfeit): ", 0, 3);
	if (row == 0)
	{
		forfeit = true;
		return;
	}
	col = inputInteger("\t\tPlease enter Column Number (or 0 to forfeit): ", 0, 3);
	if (col == 0)
	{
		forfeit = true;
		return;
	}
	row--;
	col--;
	if (row < 3 && col < 3)
	{
		if (board[row][col] == ' ')
		{
			board[row][col] = playerMove;
		}
		else
		{
			cout << "\t\tThis space is already fill\n";
			inputMove(forfeit);
		}
	}
	else
	{
		cout << "\t\tPlease enter a valid space number\n";
		inputMove(forfeit);
	}
}

// Precondition: 
// Postcondition: Computer's move
void TicTacToe::computersMove()
{
	bool moveMade = false;
	if (computerOffense())
	{
		computerOffensiveMove();
		moveMade = true;
	}
	else if (computerDefend())
	{
		computerDefensiveMove();
		moveMade = true;
	}
	// Takes the center space if it's open and the computer cannot make any offensive or defensive move
	else if (board[1][1] == ' ')
	{
		board[1][1] = compMove;
		moveMade = true;
	}
	// Computer makes a move on the first available spot of the 2d array
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = compMove;
					moveMade = true;
					break;
				}
			}
			if (moveMade)
				break;
		}
	}
}

// Precondition: 
// Postcondition: Returns true if the computer needs to make a defensive move
bool TicTacToe::computerDefend()
{
	for (int i = 0; i < 3; i++)
	{
		// Checking horizontally
		if (((board[i][0] == playerMove) && (board[i][1] == playerMove) && (board[i][2] == ' '))
			|| ((board[i][0] == playerMove) && (board[i][2] == playerMove) && (board[i][1] == ' '))
			|| ((board[i][1] == playerMove) && (board[i][2] == playerMove)) && (board[i][0] == ' '))
		{
			return true;
		}
		// Checking vertically
		else if (((board[0][i] == playerMove) && (board[1][i] == playerMove) && (board[2][i] == ' '))
			|| ((board[0][i] == playerMove) && (board[2][i] == playerMove) && (board[1][i] == ' '))
			|| ((board[1][i] == playerMove) && (board[2][i] == playerMove)) && (board[0][i] == ' '))
		{
			return true;
		}
	}
	// Checking diagonally
	if ((((board[0][0] == playerMove) && (board[1][1] == playerMove)) && (board[2][2] == ' '))
		|| (((board[0][0] == playerMove) && (board[2][2] == playerMove)) && (board[1][1] == ' '))
		|| (((board[1][1] == playerMove) && (board[2][2] == playerMove)) && (board[0][0] == ' ')))
	{
		return true;
	}
	else if ((((board[0][2] == playerMove) && (board[1][1] == playerMove)) && (board[2][0] == ' '))
		|| (((board[0][2] == playerMove) && (board[2][0] == playerMove)) && (board[1][1] == ' '))
		|| (((board[1][1] == playerMove) && (board[2][0] == playerMove)) && (board[0][2] == ' ')))
	{
		return true;
	}
	return false;
}

// Precondition: Preferably used when computerDefend is true
// Postcondition: The computer makes a defensive move
void TicTacToe::computerDefensiveMove()
{
	for (int i = 0; i < 3; i++)
	{
		// Horizontal defensive moves
		if ((board[i][0] == playerMove) && (board[i][1] == playerMove) && (board[i][2] == ' '))
		{
			board[i][2] = compMove; break;
		}
		else if ((board[i][0] == playerMove) && (board[i][2] == playerMove) && (board[i][1] == ' '))
		{
			board[i][1] = compMove; break;
		}
		else if ((board[i][1] == playerMove) && (board[i][2] == playerMove) && (board[i][0] == ' '))
		{
			board[i][0] = compMove; break;
		}
		// Vertical defensive moves
		else if ((board[0][i] == playerMove) && (board[1][i] == playerMove) && (board[2][i] == ' '))
		{
			board[2][i] = compMove; break;
		}
		else if ((board[0][i] == playerMove) && (board[2][i] == playerMove) && (board[1][i] == ' '))
		{
			board[1][i] = compMove; break;
		}
		else if ((board[1][i] == playerMove) && (board[2][i] == playerMove) && (board[0][i] == ' '))
		{
			board[0][i] = compMove; break;
		}
		// Diagonal defensive moves
		else if ((board[0][0] == playerMove) && (board[1][1] == playerMove) && (board[2][2] == ' '))
		{
			board[2][2] = compMove; break;
		}
		else if ((board[0][0] == playerMove) && (board[2][2] == playerMove) && (board[1][1] == ' '))
		{
			board[1][1] = compMove; break;
		}
		else if ((board[1][1] == playerMove) && (board[2][2] == playerMove) && (board[0][0] == ' '))
		{
			board[0][0] = compMove; break;
		}
		else if ((board[0][2] == playerMove) && (board[1][1] == playerMove) && (board[2][0] == ' '))
		{
			board[2][0] = compMove; break;
		}
		else if ((board[0][2] == playerMove) && (board[2][0] == playerMove) && (board[1][1] == ' '))
		{
			board[1][1] = compMove; break;
		}
		else if ((board[1][1] == playerMove) && (board[2][0] == playerMove) && (board[0][2] == ' '))
		{
			board[0][2] = compMove; break;
		}
	}
}

// Precondition: 
// Postcondition: Returns true if the computer can make a game winning move
bool TicTacToe::computerOffense()
{
	for (int i = 0; i < 3; i++)
	{
		// Checking horizontally
		if (((board[i][0] == compMove) && (board[i][1] == compMove) && (board[i][2] == ' ')) 
			|| ((board[i][0] == compMove) && (board[i][2] == compMove) && (board[i][1] == ' '))
			|| ((board[i][1] == compMove) && (board[i][2] == compMove)) && (board[i][0] == ' '))
		{
			return true;
		}
		// Checking vertically
		else if (((board[0][i] == compMove) && (board[1][i] == compMove) && (board[2][i] == ' '))
			|| ((board[0][i] == compMove) && (board[2][i] == compMove) && (board[1][i] == ' '))
			|| ((board[1][i] == compMove) && (board[2][i] == compMove)) && (board[0][i] == ' '))
		{
			return true;
		}
	}
	// Checking diagonally
	if ((((board[0][0] == compMove) && (board[1][1] == compMove)) && (board[2][2] == ' '))
		|| (((board[0][0] == compMove) && (board[2][2] == compMove)) && (board[1][1] == ' '))
		|| (((board[1][1] == compMove) && (board[2][2] == compMove)) && (board[0][0] == ' ')))
	{
		return true;
	}
	else if ((((board[0][2] == compMove) && (board[1][1] == compMove)) && (board[2][0] == ' '))
		|| (((board[0][2] == compMove) && (board[2][0] == compMove)) && (board[1][1] == ' '))
		|| (((board[1][1] == compMove) && (board[2][0] == compMove)) && (board[0][2] == ' ')))
	{
		return true;
	}
	return false;
}

// Precondition: Preferably used when computerOffense is true
// Postcondition: Computer makes a game winning move
void TicTacToe::computerOffensiveMove()
{
	{
		for (int i = 0; i < 3; i++)
		{
			// Horizontal offensive moves
			if ((board[i][0] == compMove) && (board[i][1] == compMove) && (board[i][2] == ' '))
			{
				board[i][2] = compMove; break;
			}
			else if ((board[i][0] == compMove) && (board[i][2] == compMove) && (board[i][1] == ' '))
			{
				board[i][1] = compMove; break;
			}
			else if ((board[i][1] == compMove) && (board[i][2] == compMove) && (board[i][0] == ' '))
			{
				board[i][0] = compMove; break;
			}
			// Vertical offensive moves
			else if ((board[0][i] == compMove) && (board[1][i] == compMove) && (board[2][i] == ' '))
			{
				board[2][i] = compMove; break;
			}
			else if ((board[0][i] == compMove) && (board[2][i] == compMove) && (board[1][i] == ' '))
			{
				board[1][i] = compMove; break;
			}
			else if ((board[1][i] == compMove) && (board[2][i] == compMove) && (board[0][i] == ' '))
			{
				board[0][i] = compMove; break;
			}
			// Diagonal offensive moves
			else if ((board[0][0] == compMove) && (board[1][1] == compMove) && (board[2][2] == ' '))
			{
				board[2][2] = compMove; break;
			}
			else if ((board[0][0] == compMove) && (board[2][2] == compMove) && (board[1][1] == ' '))
			{
				board[1][1] = compMove; break;
			}
			else if ((board[1][1] == compMove) && (board[2][2] == compMove) && (board[0][0] == ' '))
			{
				board[0][0] = compMove; break;
			}
			else if ((board[0][2] == compMove) && (board[1][1] == compMove) && (board[2][0] == ' '))
			{
				board[2][0] = compMove; break;
			}
			else if ((board[0][2] == compMove) && (board[2][0] == compMove) && (board[1][1] == ' '))
			{
				board[1][1] = compMove; break;
			}
			else if ((board[1][1] == compMove) && (board[2][0] == compMove) && (board[0][2] == ' '))
			{
				board[0][2] = compMove; break;
			}
		}
	}
}

// Precondition: 
// Postcondition: Prints out the record of the game from that session
void TicTacToe::printRecords()
{
	cout << "\n\t-------------------------------------------------\n";
	cout << "\tTotal number of games:\t\t" << TicTacToe::getTotalGames() << "\n";
	cout << "\tTotal game time this session:\t" << TicTacToe::getTotalTime() << "s\n\n";
	cout << "\tFastest game time:\t" << TicTacToe::getFastestTime() << "s with " << TicTacToe::getFastestTimeMoveCount() << " move(s)\n";
	cout << "\tSlowest game time:\t" << TicTacToe::getSlowestTime() << "s with " << TicTacToe::getSlowestTimeMoveCount() << " move(s)\n";
	cout << "\tAverage game time:\t" << TicTacToe::getAverageTime() << "s\n";
	cout << "\t-------------------------------------------------\n\n";
}