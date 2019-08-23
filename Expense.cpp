#include "ExHeader.h"
#include <iomanip>

int  ExHeader::ReturnTotalExpense()
{
	std::ifstream expAmt;

	expAmt.open("expAmt.txt");

	int storeAmt = 0;

	int *ptr_storeAmt;
	ptr_storeAmt = &storeAmt;

	while (expAmt >> *ptr_storeAmt) { expAmtVec.push_back(*ptr_storeAmt); }

	expAmt.close();

	for (int i = 0; i < expAmtVec.size(); i++) {

		*ptr_totalExpense += expAmtVec[i];

	}

	expAmtVec.clear();

	return * ptr_totalExpense;

}

void ExHeader::AddExpense(int * expense, std::string * prName, std::string typeExpStr, std::string * dateStr)
{

	std::ofstream expenseStream;

	expenseStream.open("expDate.txt",   std::ios::app);
	expenseStream << *dateStr <<    "\n";
	expenseStream.close();

	expenseStream.open("expType.txt",   std::ios::app);
	expenseStream << typeExpStr << "\n";
	expenseStream.close();

	expenseStream.open("expPrName.txt", std::ios::app);
	expenseStream << *prName <<     "\n";
	expenseStream.close();

	expenseStream.open("expAmt.txt",    std::ios::app);
	expenseStream << *expense <<    "\n";
	expenseStream.close();

}

void ExHeader::DisplayExpense()
{

	std::ifstream expDate;
	expDate.open("expDate.txt");
	std::string expDateStr;
	std::string *ptr_expDateStr;
	ptr_expDateStr = &expDateStr;

	while (std::getline(expDate, *ptr_expDateStr)) { expDateVec.push_back(*ptr_expDateStr); }

	expDate.close();

	std::ifstream expType;

	expType.open("expType.txt");

	std::string expTypeStr;
	std::string *ptr_expTypeStr;
	ptr_expTypeStr = &expTypeStr;

	while (std::getline(expType, *ptr_expTypeStr)) { expTypeVec.push_back(*ptr_expTypeStr); }

	expType.close();

	std::ifstream expPrName;

	expPrName.open("expPrName.txt");

	std::string expPrNameStr;
	std::string *ptr_expPrNameStr;
	ptr_expPrNameStr = &expPrNameStr;

	while (std::getline(expPrName, *ptr_expPrNameStr)) { expPrNameVec.push_back(*ptr_expPrNameStr); }

	expPrName.close();

	std::ifstream expAmt;

	expAmt.open("expAmt.txt");

	int storeAmt = 0;
	int *ptr_storeAmt;
	ptr_storeAmt = &storeAmt;

	while (expAmt >> *ptr_storeAmt) { expAmtVec.push_back(*ptr_storeAmt); }

	expAmt.close();

	if (expAmtVec.size() > 0) {

		for (int i = 0; i < expAmtVec.size(); i++) {

			std::cout << expDateVec   [i] << "\t"
					  << expTypeVec   [i] << "\t"
					  << expPrNameVec [i] << "\t"
					  << expAmtVec    [i] << "\n";	 

		}
	}

	else { std::cout << "No expenses yet!\n\n"; }

	expAmtVec.clear    ();
	expPrNameVec.clear ();
	expTypeVec.clear   ();
}
