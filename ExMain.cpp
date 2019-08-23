#include "ExHeader.h";
#include <iostream>
#include <fstream>

int main() {
	int addBal         = 0;		int *ptr_addBal; 
	int balance        = 0;		int *ptr_balance;
	int choice         = 0;		int *ptr_choice;
	int expense        = 0;		int *ptr_expense;
	int wdAmount       = 0;		int *ptr_wdAmount;
	int totalWdAmount  = 0;		int *ptr_totalWdAmount;
	int cashOnHand     = 0;		int *ptr_cashOnHand;
	int consBal        = 0;		int *ptr_consBal;
	int typeExpense	   = 0;		int *ptr_typeExpense;
	int alotDE		   = 0;		int *ptr_alotDE;
	int alotHO		   = 0;		int *ptr_alotHO;
	int alotRespo	   = 0;		int *ptr_alotRespo;
	int remDE		   = 0;		int *ptr_remDE;
	int remHO		   = 0;		int *ptr_remHO;
	int remRespo	   = 0;		int *ptr_remRespo;

	ptr_addBal		   = &addBal;
	ptr_balance		   = &balance;
	ptr_choice		   = &choice;
	ptr_expense		   = &expense;
	ptr_wdAmount	   = &wdAmount;
	ptr_totalWdAmount  = &totalWdAmount;
	ptr_cashOnHand     = &cashOnHand;
	ptr_consBal        = &consBal;
	ptr_typeExpense    = &typeExpense;
	ptr_alotDE		   = &alotDE;
	ptr_alotHO		   = &alotHO;
	ptr_alotRespo	   = &alotRespo;
	ptr_remDE		   = &remDE;
	ptr_remHO		   = &remHO;
	ptr_remRespo	   = &remRespo;

	bool flagOption    = true;

	std::string prName = "";
	std::string date   = "";

	std::string *ptr_prName;
	std::string *ptr_date;

	ptr_prName = &prName;
	ptr_date = &date;

	ExHeader ex;

	while (flagOption) {

		std::cout << "Options :\n"
			<< "1.  Check bank balance\n"
			<< "2.  Add bank balance\n"
			<< "3.  View expenses\n"
			<< "4.  Add expense\n"
			<< "5.  Withdraw\n"
			<< "6.  Total withdraw\n"
			<< "7.  View remaining cash on hand\n"
			<< "8.  View remaining total consumable balance\n"
			<< "9.  Add consumable Daily Expense balance\n"
			<< "10. Add consumable Hangout balance\n"
			<< "11. Add consumable Respo balance\n"
			<< "12. View remaining Daily Expense balance\n"
			<< "13. View remaining Hangout balance\n"
			<< "14. View remaining Respo balance\n"
			<< "15. Exit\n"
			<< "Please enter choice : "; std::cin >> choice; std::cout << "\n";

		switch (choice) {

		case 1:

			*ptr_balance = ex.DisplayBalance ();
			std::cout << "Current balance : " << *ptr_balance << "\n\n";
			system("pause");
			break;

		case 2:

			std::cout << "Amount : "; 
			std::cin  >> addBal;

			ex.AddBalance	   (&addBal); 
			ex.AddAvailConsBal (&addBal);
			system("pause");
			break;

		case 3:

			std::cout << "Expenses :\n";
			ex.DisplayExpense();
			system("pause");
			break;

		case 4: // Outer case

			std::cout << "Add expense :\n\n";
			std::cout << "Type of expense :\n"
					  << "1. Daily Expense\n"
					  << "2. Hangouts\n"
					  << "3. Respo\n"
				      << "Enter option : ";
			std::cin  >> *ptr_typeExpense;

			std::cout << "Amount : ";
			std::cin  >> *ptr_expense; 

			std::cout << "Product/Service name : ";
			std::cin  >> *ptr_prName;

			std::cout << "Date : ";
			std::cin  >> *ptr_date;

			std::cout << "\n";
			
			switch (typeExpense) { // Inner case

			case 1:

				*ptr_cashOnHand = ex.RemCashOnHand      ();
				*ptr_consBal    = ex.ReturnAvailConsBal ();
				*ptr_remDE      = ex.ReturnRemDE        ();

				if (*ptr_cashOnHand > 0 && *ptr_consBal > 0 && *ptr_remDE > 0) {

					ex.CashOnHandEx    (&expense);
					ex.ExAvailConsBal  (&expense);
					ex.RemDailyExpense (&expense);
					ex.AddExpense	   (&expense, &prName, "Daily Expense", &date);
					std::cout << "Expense added successfully!\n\n";

				}

				else { std::cout << "Please check your balance!\n\n"; }
				
				break;

			case 2:

				*ptr_cashOnHand = ex.RemCashOnHand      ();
				*ptr_consBal    = ex.ReturnAvailConsBal ();
				*ptr_remHO      = ex.ReturnRemHO        ();

				if (cashOnHand > 0 && consBal > 0 && remHO > 0) {
					
					ex.CashOnHandEx   (&expense);
					ex.ExAvailConsBal (&expense);
					ex.RemHangouts    (&expense);
					ex.AddExpense     (&expense, &prName, "Hangouts", &date);

					std::cout << "Expense added successfully!\n\n";

				}

				else { std::cout << "Please check your balance!\n\n"; }
				
				break;

			case 3:

				*ptr_cashOnHand = ex.RemCashOnHand      ();
				*ptr_consBal    = ex.ReturnAvailConsBal ();
				*ptr_remRespo   = ex.ReturnRemRespo     ();

				if (cashOnHand > 0 && consBal > 0 && remRespo > 0) {

					ex.CashOnHandEx   (&expense);
					ex.ExAvailConsBal (&expense);
					ex.RemRespo       (&expense);
					ex.AddExpense	  (&expense, &prName, "Responsibs", &date);

					std::cout << "Expense added successfully!\n\n";

				}

				else { std::cout << "Please check your balance!\n\n"; }

				break;

			default:

				std::cout << "Invalid option!\n\n";

			}

			system("pause");

			break;

		case 5:

			std::cout << "Enter withdraw amount : ";
			std::cin  >> *ptr_wdAmount;

			*ptr_balance = ex.DisplayBalance();

			if (*ptr_balance > 0) {

				ex.Withdraw     (&wdAmount);
				ex.CashOnHandWd (&wdAmount);

			}

			else { std::cout << "Please check your balance!\n\n"; }

			system("pause");

			break;

		case 6:	

			*ptr_totalWdAmount = ex.DisplayTotalWithdraw();

			std::cout << "Total withdrawn amount : " << *ptr_totalWdAmount << "\n\n";

			system("pause");

			break;

		case 7:

			*ptr_cashOnHand = ex.RemCashOnHand();

			std::cout << "Remaining cash on hand : " << *ptr_cashOnHand << "\n\n";

			system("pause");

			break;

		case 8:

			*ptr_consBal = ex.ReturnAvailConsBal();

			std::cout << "Available consumable balance : " << *ptr_consBal << "\n\n";

			system("pause");

			break;

		case 9:

			std::cout << "Add consumable Daily Expense : ";
			std::cin >> *ptr_alotDE;

			ex.SetAlottedDE(&alotDE);

			std::cout << "\n";

			system("pause");

			break;

		case 10:

			std::cout << "Add consumable Hangout : ";
			std::cin >> *ptr_alotHO;

			ex.SetAlottedHO(&alotHO);

			std::cout << "\n";

			system("pause");

			break;

		case 11:

			std::cout << "Add consumable Respo : ";
			std::cin >> *ptr_alotRespo;

			ex.SetAlottedRespo(&alotRespo);

			std::cout << "\n";

			system("pause");

			break;

		case 12:

			*ptr_remDE = ex.ReturnRemDE();
			std::cout << "Remaining consumable Daily Expense : " << *ptr_remDE << "\n\n";

			system("pause");

			break;

		case 13:	

			*ptr_remHO = ex.ReturnRemHO();
			std::cout << "Remaining consumable Hangout : " << *ptr_remHO << "\n\n";

			system("pause");

			break;

		case 14:

			*ptr_remRespo = ex.ReturnRemRespo();
			std::cout << "Remaining consumable Respo : " << *ptr_remRespo << "\n\n";

			system("pause");

			break;

		case 15:

			std::cout << "Exit success!\n\n";

			flagOption = false;

			break;

		default:

			std::cout << "Invalid option!\n\n";

			system("pause");

		}

	}

	system("pause");

}
