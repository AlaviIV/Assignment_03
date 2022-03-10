#include "nQueens.h"

// constructor
nQueens::nQueens(int theTotalGames, double theTotalTime, double theSlowestTime, double theFastestTime,
	double theAverageTime, int theSlowestTimeMoveCount, int theFastestTimeMoveCount)
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
int nQueens::getTotalGames() const
{
	return totalGames;
}
double nQueens::getTotalTime() const
{
	return totalTime;
}
double nQueens::getSlowestTime() const
{
	return slowestTime;
}
double nQueens::getFastestTime() const
{
	return fastestTime;
}
double nQueens::getAverageTime() const
{
	return averageTime;
}
int nQueens::getSlowestTimeMoveCount() const
{
	return slowestTimeMoveCount;
}
int nQueens::getFastestTimeMoveCount() const
{
	return fastestTimeMoveCount;
}

// Mutator
void nQueens::setTotalGames(const int newTotalGames)
{
	totalGames = newTotalGames;
}
void nQueens::setTotalTime(const double newTotalTime)
{
	totalTime += newTotalTime;
}
void nQueens::setSlowestTime(const double newSlowestTIme)
{
	slowestTime = newSlowestTIme;
}
void nQueens::setFastestTime(const double newFastestTime)
{
	fastestTime = newFastestTime;
}
void nQueens::setAverageTime(const double newTotalGames, const double newTotalTime)
{
	averageTime = newTotalTime / newTotalGames;
}
void nQueens::setSlowestTimeMoveCount(const int newSlowestTimeMoveCount)
{
	slowestTimeMoveCount = newSlowestTimeMoveCount;
}
void nQueens::setFastestTimeMoveCount(const int newFastestTimeMoveCount)
{
	fastestTimeMoveCount = newFastestTimeMoveCount;
}

// Precondition: 
// Postcondition: The main process for nQueens
void nQueens::nQueensMain()
{
	int numberOfGames = 0;
	int totalGameMoves;
	double startTime, endTime, time;
	bool playAgain = true;
	bool forfeit;
	char choice;
	int row, col, numberOfQueens, option;

	cout << "\n\tThe n-queens puzzle is the problem of placing n chess queens on an nxn chessboard";
	cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
	cout << "\n\tqueens share the same row, column, or diagonal.Solutions exist for all natural";
	cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";
	do 
	{
		int dim = inputInteger("\n\n\tEnter the dimensions of the board: ", true);
		row = dim;
		col = dim;

		// creating the dynamic 2d array
		char** board = new char* [row]; // double astrisk cause its a pointer to a pointer
		for (int i = 0; i < row; i++)
		{
			board[i] = new char[col];
		}
		// making the board into empty spaces
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				board[i][j] = ' ';
			}
		}
		// New game begins here 
		startTime = clock();
		numberOfGames++;
		totalGameMoves = 0;
		forfeit = false;
		numberOfQueens = 0;
		do
		{
			// printing board
			cout << "\n\n\t";
			for (int j = 0; j < col; j++)
			{
				cout << "--";
			}
			cout << "-" << '\n';
			for (int i = 0; i < row; i++)
			{
				cout << "\t";
				for (int j = 0; j < col; j++)
				{
					cout << "|" << board[i][j];
				}
				cout << "|" << '\n' << "\t";
				for (int j = 0; j < col; j++)
				{
					cout << "--";
				}
				cout << "-" << '\n';
			}
			// checks if the user won
			if (numberOfQueens == dim)
			{
				cout << "\n\tCongrats! You won the game of nQueens!";
				break;
			}
			if (forfeit)
			{
				cout << "\n\tUser has forfeited the game.";
				break;
			}
			// option selection
			gameOptionsOutput();
			option = inputChar("\n\tOption: ");

			if (option == '0')
				break;
			switch (option)
			{
			case 'A': // option to add a queen on the board
			{
				int i, j;
				bool isSafe = true;
				int queenRow = inputInteger("\n\tEnter the row for the new Queen (or 0 to forfeit): ", 0, row);
				if (queenRow == 0)
				{
					forfeit = true;
					system("cls");
					break;
				}
				queenRow--;
				int queenCol = inputInteger("\tEnter the column for the new Queen (or 0 to forfeit): ", 0, col);
				if (queenCol == 0)
				{
					forfeit = true;
					system("cls");
					break;
				}				
				queenCol--;
				// checking if it's safe to place a queen
				// checking vertically
				if (isSafe)
				{
					for (i = 0; i < col; i++)
					{
						if (board[i][queenCol] == 'Q')
						{
							isSafe = false;
							break;
						}
					}

				}
				// checking horizontally
				if (isSafe)
				{
					for (j = 0; j < row; j++)
					{
						if (board[queenRow][j] == 'Q')
						{
							isSafe = false;
							break;
						}
					}
				}
				// checking diagonally (top left)
				if (isSafe)
				{
					bool temp = true;
					i = queenRow;
					j = queenCol;
					do
					{
						if ((i < 0) || (j < 0))
							temp = false;
						else if (board[i][j] == 'Q')
						{
							isSafe = false;
							break;
						}
						else
							i--, j--;
					} while (temp);
				}
				// checking diagonally (bottom right)
				if (isSafe)
				{
					bool temp = true;
					i = queenRow;
					j = queenCol;
					do
					{
						if ((i > (row - 1)) || (j > (col - 1)))
							temp = false;
						else if (board[i][j] == 'Q')
						{
							isSafe = false;
							break;
						}
						else 
							i++, j++;
					} while (temp);
				}
				// checking diagonally (top right)
				if (isSafe)
				{
					bool temp = true;
					i = queenRow;
					j = queenCol;
					do
					{
						if ((i < 0) || (j > (col - 1)))
							temp = false;
						else if (board[i][j] == 'Q')
						{
							isSafe = false;
							break;
						}
						i--, j++;
					} while (temp);
				}
				// checking diagonally (bottom left)
				if (isSafe)
				{
					bool temp = true;
					i = queenRow;
					j = queenCol;
					do
					{
						if ((i > (row - 1)) || (j < 0))
							temp = false;
						else if (board[i][j] == 'Q')
						{
							isSafe = false;
							break;
						}
						i++, j--;
					} while (temp);
				}
				system("cls");
				if (isSafe)
				{
					board[queenRow][queenCol] = 'Q';
					numberOfQueens++;
				}
				else
					cout << "\n\tNot safe to place a queen on that position.";
				totalGameMoves++;
			} break;
			case 'B': // option to remove an existing queen on the board
			{
				int queenRow = inputInteger("\n\tEnter the existing Queen's row (or 0 to forfeit): ", 0, row);
				if (queenRow == 0)
				{
					forfeit = true;
					system("cls");
					break;
				}
				queenRow--;
				int queenCol = inputInteger("\tEnter the existing Queen's column (or 0 to forfeit): ", 0, col);
				if (queenCol == 0)
				{
					forfeit = true;
					system("cls");
					break;
				}
				queenCol--;
				system("cls");
				// checking if a queen exists on that position
				if (board[queenRow][queenCol] == ' ') 
					cout << "\tError: A Queen does not exist on that position.";
				else
				{
					board[queenRow][queenCol] = ' ';
					numberOfQueens--;
				}
				totalGameMoves++;
			} break;
			default: cout << "\tERROR - Invalid option. Please re-enter.\n"; break;
			}
		} while (true);

		// deleting the array to free up memory
		for (int i = 0; i < row; i++)
		{
			delete[] board[i];
		}
		delete[] board;
		board = NULL;


		// Endgame records update
		endTime = clock();
		time = ((endTime - startTime) / double(CLOCKS_PER_SEC));
		nQueens::setTotalGames(numberOfGames);
		nQueens::setTotalTime(time);
		if (time < nQueens::getFastestTime())
		{
			nQueens::setFastestTime(time);
			nQueens::setFastestTimeMoveCount(totalGameMoves);
		}
		if (time > nQueens::getSlowestTime())
		{
			nQueens::setSlowestTime(time);
			nQueens::setSlowestTimeMoveCount(totalGameMoves);
		}

		choice = inputChar("\n\n\tDo you want to play again (Y - yes or N - no)? ", 'y', 'n');
		if (choice == 'N')
			playAgain = false;
	} while (playAgain);
	// More endgame record updates
	nQueens::setTotalGames(numberOfGames);
	nQueens::setAverageTime(totalGames, totalTime);
	// Prints out the updated records
	printRecords();

	system("pause");
	system("cls");
}

void nQueens::gameOptionsOutput()
{
	cout << "\n\n\t\tGame Options";
	cout << "\n\t---------------------------";
	cout << "\n\tA> Place a queen";
	cout << "\n\tB> Remove an existing queen";
	cout << "\n\t---------------------------";
	cout << "\n\t0> Forfeit and return";
	cout << "\n\t---------------------------";
}

void nQueens::printRecords()
{
	cout << "\n\t-------------------------------------------------\n";
	cout << "\tTotal number of games:\t\t" << nQueens::getTotalGames() << "\n";
	cout << "\tTotal game time this session:\t" << nQueens::getTotalTime() << "s\n\n";
	cout << "\tFastest game time:\t" << nQueens::getFastestTime() << "s with " << nQueens::getFastestTimeMoveCount() << " move(s)\n";
	cout << "\tSlowest game time:\t" << nQueens::getSlowestTime() << "s with " << nQueens::getSlowestTimeMoveCount() << " move(s)\n";
	cout << "\tAverage game time:\t" << nQueens::getAverageTime() << "s\n";
	cout << "\t-------------------------------------------------\n\n";
}