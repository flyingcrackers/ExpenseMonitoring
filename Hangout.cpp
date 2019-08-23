#include "ExHeader.h"
#include <iomanip>

int ExHeader::ReturnRemHO()
{

	std::ifstream inputFile;

	inputFile.open("hangOut.txt");

	inputFile >> *ptr_remHO;

	inputFile.close();

	return *ptr_remHO;
}

void ExHeader::SetAlottedHO(int * alotHO)
{

	std::ifstream inputFile;
	inputFile.open("hangOut.txt");
	inputFile >> *ptr_remHO;
	*ptr_remHO += *alotHO;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("hangOut.txt");
	outputFile << *ptr_remHO;
	outputFile.close();

}

void ExHeader::RemHangouts(int * expense)
{

	std::ifstream inputFile;
	inputFile.open("hangOut.txt");
	inputFile >> *ptr_remHO;
	*ptr_remHO -= *expense;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("hangOut.txt");
	outputFile << *ptr_remHO;
	outputFile.close();

}
