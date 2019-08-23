#include "ExHeader.h"
#include <iomanip>

int  ExHeader::DisplayBalance()
{

	std::ifstream inputFile;

	inputFile.open("balanceOutput.txt");

	inputFile >> *ptr_balance;

	inputFile.close();

	return *ptr_balance;
}


void ExHeader::AddBalance(int * addBal)
{

	std::ifstream inputFile;
	inputFile.open("balanceOutput.txt");
	inputFile >> *ptr_balance;
	*ptr_balance += *addBal;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("balanceOutput.txt");
	outputFile << *ptr_balance;
	outputFile.close();

}
