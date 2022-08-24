#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MemberAccount.h"
#include "BST/BST_Node.h"


bool openAccount(std::fstream& fs, std::string& filename) {
	fs.open(filename, /* std::ios_base::binary | */ std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
	if (!fs.is_open()) {
		std::cout << "Open Account Operation Failed - Unable to Open DB File";
		return false;
	}

	long AccountID = 1;
	std::string FirstName = "FirstName1";
	std::string LastName = "LastName1";
	std::string PhoneNumber = "123-456-7890";
	long long AccountBalance = 123;


	MemberAccount* account = new MemberAccount(AccountID, FirstName, LastName, PhoneNumber, AccountBalance);
	std::string accountString = account->CreateEntry();
	fs.write(accountString.c_str(), sizeof accountString);


	//fs.seekp(0);

	//int lineno = 0;
	//while (!fs.eof()) {
	//	fs >> lineno;
	//	std::cout << lineno;
	//}
	auto size = fs.tellg();
	std::string str(size, '\0');
	fs.seekg(0);
	if (fs.read(&str[0], size))
		std::cout << str << '\n';


	fs.close();
	return true;
}




bool accWithdraw(std::fstream& fs, std::string& filename) {
	//SimpleNode test(5);
	//std::cout << "data" << test.data_internal << "left" << test.left_branch << "right" << test.right_branch << std::endl;
	long AccountIDx = 1;
	std::string FirstNamex = "FirstName1";
	std::string LastNamex = "LastName1";
	std::string PhoneNumberx = "111-456-7890";
	long long AccountBalancex = 111545;

	MemberAccountNode acctestx(AccountIDx, FirstNamex, LastNamex, PhoneNumberx, AccountBalancex);




	long AccountID = 2;
	std::string FirstName = "FirstName2";
	std::string LastName = "LastName2";
	std::string PhoneNumber = "222-456-7890";
	long long AccountBalance = 234545;

	MemberAccountNode acctest(AccountID, FirstName, LastName, PhoneNumber, AccountBalance);

	acctest.left_branch = &acctestx;

	std::cout << "Member Account Node" <<
		acctest.account_id << " " <<
		acctest.first_name << " " <<
		acctest.last_name << " " <<
		acctest.phone_number << " " <<
		acctest.account_balance << " " <<
		acctest.left_branch << " " <<
		acctest.right_branch << " " << std::endl;


	
	
	// Read in previous account balance
	//fs.open(filename, std::ios_base::binary | std::ios_base::in);

	//fs.close();

	// Write new account balance
	//fs.open(filename, std::ios_base::binary | std::ios_base::out);

	//fs.close();
	return true;
}


int main(int argv, char* argc[]) {
	std::string accFilename = "account_db.bin";
	std::fstream fs;
	bool runApp = true;
	

	while (runApp) {
		std::cout << "Welcome to Simplex Banking Solutions\n\n";
		std::cout << "1. Open An Account\n";
		std::cout << "2. Check Account Balance\n";
		std::cout << "3. Withdraw Funds\n";
		std::cout << "4. Deposit Funds\n";
		std::cout << "5. View Account Details\n";
		std::cout << "6. Search Accounts\n";
		std::cout << "7. Close An Account\n";
		std::cout << "8. Exit\n\n";

		std::cout << "Select and Option to Continue\n" << std::endl;

		std::string actionSelStr;
		std::cin >> actionSelStr;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (atoi(actionSelStr.c_str()))
		{
		case 1:
			std::cout << "Open An Account\n" << std::endl;
			openAccount(fs, accFilename);
			
			break;
		case 2:
			std::cout << "Check Account Balance\n" << std::endl;
			accWithdraw(fs, accFilename);
			
			break;
		case 3:
			std::cout << "Withdraw Funds\n" << std::endl;
			break;
		case 4:
			std::cout << "Deposit Funds\n" << std::endl;
			break;
		case 5:
			std::cout << "View Account Details\n" << std::endl;
			break;
		case 6:
			std::cout << "Search Accounts\n" << std::endl;
			break;
		case 7:
			std::cout << "Close An Account\n" << std::endl;
			break;
		case 8:
			std::cout << "Goodbye!\n" << std::endl;
			runApp = false;
			break;
		default:
			std::cout << "Invalid Selection\n" << std::endl;
			break;
		}
	}
}

