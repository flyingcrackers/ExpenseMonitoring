#include "ExHeader.h"
#include <iomanip>

int ExHeader::ReturnRemDE()
{

	std::ifstream inputFile;

	inputFile.open("dailyExpense.txt");

	inputFile >> *ptr_remDE;

	inputFile.close();

	return *ptr_remDE;

}

void ExHeader::SetAlottedDE(int * alotDE)
{

	std::ifstream inputFile;
	inputFile.open("dailyExpense.txt");
	inputFile >> *ptr_remDE;
	*ptr_remDE += *alotDE;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("dailyExpense.txt");
	outputFile << *ptr_remDE;
	outputFile.close();

}

void ExHeader::RemDailyExpense(int * expense)
{

	std::ifstream inputFile;
	inputFile.open("dailyExpense.txt");
	inputFile >> *ptr_remDE;
	*ptr_remDE -= *expense;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("dailyExpense.txt");
	outputFile << *ptr_remDE;
	outputFile.close();

}
