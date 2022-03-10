#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include <ctime>
#include "input.h"
using namespace std;

class TicTacToe
{
private:
	const char playerMove = 'X';
	const char compMove = 'O';
	char board[3][3] = { 
		('\0', '\0', '\0'), 
		('\0', '\0', '\0') ,
		('\0', '\0', '\0') };
	int totalGames;
	double totalTime;
	double slowestTime;
	double fastestTime;
	double averageTime;
	int slowestTimeMoveCount;
	int fastestTimeMoveCount;

public:
	// Default Constructor
	TicTacToe() : totalGames(0), totalTime(0), slowestTime(-1), fastestTime(999999), averageTime(0), slowestTimeMoveCount(0), fastestTimeMoveCount(0) {}
    
	// Constructor
	TicTacToe(int theTotalGames, double theTotalTime, double theSlowestTime, double theFastestTime, double theAverageTime, int slowestTimeMoveCount, int fastestTimeMoveCount);

	// Accessor
	int getTotalGames() const;
	double getTotalTime() const;
	double getSlowestTime() const;
	double getFastestTime() const;
	double getAverageTime() const;
	int getSlowestTimeMoveCount() const;
	int getFastestTimeMoveCount() const;

	// Mutator
	void setTotalGames(const int newTotalGames);
	void setTotalTime(const double newTotalTime);
	void setSlowestTime(const double newSlowestTIme);
	void setFastestTime(const double newFastestTime);
	void setAverageTime(const double newTotalGames, const double newTotalTime);
	void setSlowestTimeMoveCount(const int newSlowestTimeMoveCount);
	void setFastestTimeMoveCount(const int newFastestTimeMoveCount);

	// Precondition: 
	// Postcondition: The main process for TicTacToe
	void ticTacToeMenu();

	// Precondition: 
	// Postcondition: Sets up a new game and resets the number of total game moves and existing winner
	void setupBoard(bool &winnerExist, int &totalGameMoves);

	// Precondition: 
	// Postcondition: Displays the current status of the game board
	void printBoard();

	// Precondition: 
	// Postcondition: Checks if there are any winners
	bool winCheck(string currentPlayer, int moves, bool forfeit);

	// Precondition: 
	// Postcondition: Inputs the users move
	void inputMove(bool &forfeit);

	// Precondition: 
	// Postcondition: Computer's move
	void computersMove();

	// Precondition: 
	// Postcondition: Returns true if the computer needs to make a defensive move
	bool computerDefend();

	// Precondition: Preferably used when computerDefend is true
	// Postcondition: The computer makes a defensive move
	void computerDefensiveMove();

	// Precondition: 
	// Postcondition: Returns true if the computer can make a game winning move
	bool computerOffense();

	// Precondition: Preferably used when computerOffense is true
	// Postcondition: Computer makes a game winning move
	void computerOffensiveMove();

	// Precondition: 
	// Postcondition: Prints out the record of the game from that session
	void printRecords();
};
#endif // !TICTACTOE_H