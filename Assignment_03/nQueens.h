#pragma once
#ifndef NQUEENS_H
#define NQUEENS_H

#include <iostream>
#include <string>
#include <ctime>
#include "input.h"
using namespace std;

class nQueens
{
private:
	const char playerMove = 'Q';
	int totalGames;
	double totalTime;
	double slowestTime;
	double fastestTime;
	double averageTime;
	int slowestTimeMoveCount;
	int fastestTimeMoveCount;
public:
	// Default Constructor
	nQueens() : totalGames(0), totalTime(0), slowestTime(-1), fastestTime(999999), averageTime(0), slowestTimeMoveCount(0), fastestTimeMoveCount(0) {}

	// Constructor
	nQueens(int theTotalGames, double theTotalTime, double theSlowestTime,
		double theFastestTime, double theAverageTime, int slowestTimeMoveCount, int fastestTimeMoveCount);

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
	// Postcondition: The main process for nQueens
	void nQueensMain();

	// Precondition: 
	// Postcondition: Prints out the game options
	void gameOptionsOutput();

	// Precondition: 
	// Postcondition: Prints out the record of the game from that session
	void printRecords();
};
#endif // !NQUEENS_H