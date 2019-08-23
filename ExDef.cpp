#include "ExHeader.h"
#include <iomanip>


ExHeader::ExHeader()
{
	std::cout << "Expense Monitoring System\n"
		<< "Test Prototype\n"
		<< "Version 1.2\n"
		<< "Start date : July 30, 2019\n"
		<< "August 7, 2019, Day 7\n"
		<< "--------------------------\n";

	balance			  = 0;
	totalWdAmount	  = 0;
	cashOnHand		  = 0;
	totalExpense	  = 0;
	availConsBal	  = 0;
	alotDE			  = 0;
	remDE			  = 0;
	alotHO			  = 0;
	remHO			  = 0;
	alotRespo		  = 0;
	remRespo		  = 0;

	ptr_balance		  = &balance;
	ptr_totalWdAmount = &totalWdAmount;
	ptr_cashOnHand    = &cashOnHand;
	ptr_totalExpense  = &totalExpense;
	ptr_availConsBal  = &availConsBal;
	ptr_alotDE		  = &alotDE;
	ptr_remDE		  = &remDE;
	ptr_alotHO		  = &alotHO;
	ptr_remHO		  = &remHO;
	ptr_alotRespo	  = &alotRespo;
	ptr_remRespo	  = &remRespo;

}

ExHeader::~ExHeader() {}
