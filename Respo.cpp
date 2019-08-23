#include "ExHeader.h"
#include <iomanip>


int ExHeader::ReturnRemRespo()
{

	std::ifstream inputFile;

	inputFile.open("respo.txt");

	inputFile >> *ptr_remRespo;

	inputFile.close();

	return *ptr_remRespo;

}

void ExHeader::SetAlottedRespo(int * alotRespo)
{

	std::ifstream inputFile;
	inputFile.open("respo.txt");
	inputFile >> *ptr_remRespo;
	*ptr_remRespo += *alotRespo;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("respo.txt");
	outputFile << *ptr_remRespo;
	outputFile.close();

}

void ExHeader::RemRespo(int * expense)
{

	std::ifstream inputFile;
	inputFile.open("respo.txt");
	inputFile >> *ptr_remRespo;
	*ptr_remRespo -= *expense;
	inputFile.close();

	std::ofstream outputFile;
	outputFile.open("respo.txt");
	outputFile << *ptr_remRespo;
	outputFile.close();

}
