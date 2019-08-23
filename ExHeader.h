#pragma once

#include < vector >
#include <iostream>
#include < string >
#include <fstream>

class ExHeader
{

private:
	int						 balance;
	int						 totalWdAmount;
	int						 cashOnHand;
	int						 totalExpense;
	int						 availConsBal;
	int						 alotDE;
	int						 remDE;
	int						 alotHO;
	int						 remHO;
	int						 alotRespo;
	int						 remRespo;

	int						 *ptr_balance;
	int						 *ptr_totalWdAmount;
	int						 *ptr_cashOnHand;
	int						 *ptr_totalExpense;
	int						 *ptr_availConsBal;
	int						 *ptr_alotDE;
	int						 *ptr_remDE;
	int						 *ptr_alotHO;
	int						 *ptr_remHO;
	int						 *ptr_alotRespo;
	int						 *ptr_remRespo;

	std::vector<int>		 expVector;
	std::vector<int>		 expAmtVec;
	std::vector<std::string> expVectorStr;
	std::vector<std::string> typeVector;
	std::vector<std::string> expFile;
	std::vector<std::string> expTypeVec;
	std::vector<std::string> expPrNameVec;
	std::vector<std::string> expDateVec;

public:
	//Constructor
	ExHeader();

	//Setters
	void AddBalance      ( int * addBal	   );
	void Withdraw        ( int * wdAmount  );
	void CashOnHandEx    ( int * expense   );
	void CashOnHandWd    ( int * wdAmount  );
	void AddAvailConsBal ( int * addBal    );
	void ExAvailConsBal  ( int * expense   );
	void SetAlottedDE	 ( int * alotDE	   );
	void RemDailyExpense ( int * expense   );
	void SetAlottedHO	 ( int * alotHO	   );
	void RemHangouts	 ( int * expense   );
	void SetAlottedRespo ( int * alotRespo );
	void RemRespo		 ( int * expense   );
	
	void AddExpense		 (int * expense, std::string * prName, std::string typeExpStr, std::string * dateStr);

	//Getters
	int  DisplayBalance       ();
	int  DisplayTotalWithdraw ();
	int  RemCashOnHand        ();
	int  ReturnTotalExpense   ();
	int  ReturnAvailConsBal   ();
	int  ReturnRemDE		  ();
	int  ReturnRemHO		  ();
	int  ReturnRemRespo		  ();
	void DisplayExpense       ();

	//Deconstructor
	~ExHeader();
};
