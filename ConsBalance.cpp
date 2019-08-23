#include "ExHeader.h"
#include <iomanip>

int  ExHeader::ReturnAvailConsBal()
{

	std::ifstream inputFile;

	inputFile.open("ACBOutput.txt");

	inputFile >> *ptr_availConsBal;

	inputFile.close();

	return *ptr_availConsBal;

}

void ExHeader::ExAvailConsBal(int * expense)
{

	std::ifstream inputFile;
	inputFile.open("ACBOutput.txt");
	inputFile >> *ptr_availConsBal;
	*ptr_availConsBal -= *expense;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("ACBOutput.txt");
	outputFile << *ptr_availConsBal;
	outputFile.close();
}


void ExHeader::AddAvailConsBal(int * addBal)
{

	std::ifstream inputFile;
	inputFile.open("ACBOutput.txt");
	inputFile >> *ptr_availConsBal;
	*ptr_availConsBal += *addBal;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("ACBOutput.txt");
	outputFile << *ptr_availConsBal;
	outputFile.close();

}
