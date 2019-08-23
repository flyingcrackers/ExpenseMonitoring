#include "ExHeader.h"
#include <iomanip>

int  ExHeader::DisplayTotalWithdraw()
{

	std::ifstream inputFile;

	inputFile.open("withdrawOutput.txt");

	inputFile >> *ptr_totalWdAmount;

	inputFile.close();

	return *ptr_totalWdAmount;

}

void ExHeader::Withdraw(int * wdAmount)
{
	std::ifstream inputFile;
	inputFile.open("balanceOutput.txt");
	inputFile >> *ptr_balance;
	*ptr_balance -= *wdAmount;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("balanceOutput.txt");
	outputFile << *ptr_balance;
	outputFile.close();

	std::ifstream inputFile2;
	inputFile2.open("withdrawOutput.txt");
	inputFile2 >> *ptr_totalWdAmount;
	*ptr_totalWdAmount += *wdAmount;
	inputFile2.close();

	std::ofstream outputFile2;
	outputFile2.open("withdrawOutput.txt");
	outputFile2 << *ptr_totalWdAmount;
	outputFile2.close();
}
