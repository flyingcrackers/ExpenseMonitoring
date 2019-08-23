#include "ExHeader.h"
#include <iomanip>

int  ExHeader::RemCashOnHand()
{

	std::ifstream inputFile;

	inputFile.open("COHOutput.txt");

	inputFile >> *ptr_cashOnHand;

	inputFile.close();

	return *ptr_cashOnHand;

}

void ExHeader::CashOnHandEx(int * expense)
{

	std::ifstream inputFile;
	inputFile.open("COHOutput.txt");
	inputFile >> *ptr_cashOnHand;
	*ptr_cashOnHand -= *expense;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("COHOutput.txt");
	outputFile << *ptr_cashOnHand;
	outputFile.close();

}

void ExHeader::CashOnHandWd(int * wdAmount)
{

	std::ifstream inputFile;
	inputFile.open("COHOutput.txt");
	inputFile >> *ptr_cashOnHand;
	*ptr_cashOnHand += *wdAmount;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("COHOutput.txt");
	outputFile << *ptr_cashOnHand;
	outputFile.close();

}
