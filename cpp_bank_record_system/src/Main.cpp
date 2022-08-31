#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include "MemberAccount.h"
#include "BST/BST_Node.h"
#include "BST/MemberAccountTree.h"

/* TODOS:
* 1. Write BST Data to File on Account Creation (A new account can be appended to the end of the file, do not need to rebuild the store): Complete
* 2. Read BST Data from File on Program Launch: Complete
* 3. Implement a search function based on account number to retrieve target user data - Complete
* 4. Setup user input during account creation - Complete, sizeof was returning the full length of the containing string object which when passed through the filestream write was pushing junk data into the data store
* 5. Update BST Tree on Withdrawl
* 6. Update BST Tree on Deposit
* 7. Update BST Tree on User Account Details Change
* 8. Update BST Data Store on BST Data Modifiation (When the data in the BST is updated the file store will need to be updated to match - this is not very efficient but for a first time through its fine)
* 9. Update the BST to automatically balance the data in the tree, right now since the sorting index is linearly incremented we aren't taking advantage of the properties of a BST
*/


void buildAccDBTree(std::string& filename, MemberAccountTree& OutOperationTree) {
	std::fstream fs(filename, std::ios_base::binary | std::ios_base::in);
	std::string accDataString;
	std::vector<std::string> fileIterator;

	if (!fs.is_open()) {
		std::cout << "Database File Not Found, First Initialization" << std::endl;
		return;
	}

	while (!fs.eof()) {
		std::getline(fs, accDataString);
		fileIterator.push_back(accDataString);
	}

	for (int i = 0; i < fileIterator.size(); i++) {
		long accID = 0;
		std::string firstName = "";
		std::string lastName = "";
		std::string phoneNumber = "";
		long long accBalance = 0;

		int colIdx = 0;
		size_t startPos = 0;
		size_t endPos = 0;

		while (startPos != std::string::npos) {
			endPos = fileIterator[i].find('\t', startPos);
			switch (colIdx)
			{
			case 0:
				accID = atol(fileIterator[i].substr(startPos, endPos - startPos).c_str());
				break;
			case 1:
				firstName = fileIterator[i].substr(startPos, endPos - startPos);
				break;
			case 2:
				lastName = fileIterator[i].substr(startPos, endPos - startPos);
				break;
			case 3:
				phoneNumber = fileIterator[i].substr(startPos, endPos - startPos);
				break;
			case 4:
				accBalance = atoll(fileIterator[i].substr(startPos, endPos - startPos).c_str());
				break;
			default:
				break;
			}

			if (endPos == std::string::npos)
			{
				startPos = endPos;
			}
			else
			{
				startPos = endPos + 1;
			}

			colIdx++;
		}

		if (accID != 0) {
			OutOperationTree.addNode(static_cast<BSTNode*>(new MemberAccountNode(accID, firstName, lastName, phoneNumber, accBalance)));
		}

		std::cout << "Record Number: " << colIdx << " AccID: " << accID << " FN: " << firstName << " LN: " << lastName << " PN: " << phoneNumber << " Balance: " << accBalance << std::endl;
	}
}

//bool openAccount(std::fstream& fs, std::string& filename) {
bool openAccount(std::string& filename, std::string& dbFilename, MemberAccountTree& dbTree) {
	long accountID = 1;
	std::string dbCoreRead;
	std::vector<std::string> dbCoreIteratorUpd;
	std::vector<std::string> dbCoreIterator;


	std::string FirstName = "";
	std::string LastName = "";
	std::string PhoneNumber = "";
	std::string AccountBalanceString = "";
	long long AccountBalance = 0;

	std::cout << "Enter the New Account Info\n" << std::endl;
	std::cout << "First Name:" << std::endl;
	std::cin >> FirstName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "\nLast Name:" << std::endl;
	std::cin >> LastName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "\nPhone Number:" << std::endl;
	std::cin >> PhoneNumber;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "\nInitial Account Balance:" << std::endl;
	std::cin >> AccountBalanceString;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	AccountBalance = atoll(AccountBalanceString.c_str());

	// Read In DB Core Data
	std::fstream dbc_is(dbFilename, std::ios_base::binary | std::ios_base::in);
	if (dbc_is.is_open()) {
		while (!dbc_is.eof()) {
			std::getline(dbc_is, dbCoreRead);
			if (dbCoreRead.find(filename) != std::string::npos) {
				dbCoreIteratorUpd.push_back(dbCoreRead);
			}
			else
			{
				dbCoreIterator.push_back(dbCoreRead);
			}
		}

		if (dbCoreIteratorUpd.size() != 0)
		{
			// Get the Previous Tracking Value
			size_t idx = dbCoreIteratorUpd[0].find("\t idx:");
			accountID = atol(dbCoreIteratorUpd[0].substr(idx + 6, 19).c_str() ) + 1;

			// Update the entry to represent the new Tracking Value
			std::ostringstream accIDString;
			accIDString << std::setw(19) << std::setfill('0') << accountID;

			// Add it to the iterator which will create the new file
			dbCoreIterator.push_back(filename + "\t idx:" + accIDString.str());
		}

		dbc_is.close();
	}


	if (dbCoreIteratorUpd.size() != 0) {
		// Create Temporary File and Write Updates
		std::fstream dbct_os("db_core_temp.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::app);
		if (!dbct_os.is_open()) {
			std::cout << "Open Account Operation Failed - Failed to Create Update File" << std::endl;
			return false;
		}

		for (std::vector<std::string>::iterator it = dbCoreIterator.begin(); it != dbCoreIterator.end(); ++it) {
			dbct_os.write(it->c_str(), sizeof * it);
		}

		dbct_os.close();

		remove(dbFilename.c_str());
		int renameCheck = rename("db_core_temp.bin", dbFilename.c_str());
		if (renameCheck != 0) {
			perror("Error encountered when renaming file");
			return false;
		}
	}
	else
	{
		std::fstream dbc_os(dbFilename, std::ios_base::binary | std::ios_base::out | std::ios_base::app);
		if (!dbc_os.is_open()) {
			std::cout << "Open Account Operation Failed - Unable to open the DB Core File" << std::endl;
			return false;
		}

		std::ostringstream accIDString;
		accIDString << std::setw(19) << std::setfill('0') << accountID;

		std::string dbcinputstring = filename + "\t idx:" + accIDString.str();
		dbc_os.write(dbcinputstring.c_str(), sizeof dbcinputstring);

		dbc_os.close();
	}


	// Update the Account Table
	std::fstream fs(filename, std::ios_base::binary | std::ios_base::out | std::ios_base::app);
	if (!fs.is_open()) {
		std::cout << "Open Account Operation Failed - Unable to Open DB File" << std::endl;
		return false;
	}


	MemberAccount* account = new MemberAccount(accountID, FirstName, LastName, PhoneNumber, AccountBalance);
	std::string accountString = account->CreateEntry();
	std::cout << accountString.length() << std::endl;
	std::cout << sizeof accountString << std::endl;
	fs.write(accountString.c_str(), accountString.length());
	
	MemberAccountNode* newAccount = new MemberAccountNode(accountID, FirstName, LastName, PhoneNumber, AccountBalance);
	dbTree.addNode(static_cast<BSTNode*>(newAccount));

	std::cout << "Account Created with Account ID: " << accountID << std::endl;

	fs.close();
	return true;
}

bool accSearch(MemberAccountTree& dbTree) {
	std::cout << "Enter Account ID to Pull Up\n" << std::endl;

	std::string accountIDInput;
	std::cin >> accountIDInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	long accountID = atol(accountIDInput.c_str());

	if (accountID == 0)
	{
		std::cout << "Invalid Account ID Entry, Please Re-Enter Account ID Value to Retrieve\n" << std::endl;
		return false;
	}

	MemberAccountNode* searchResult =  dbTree.findNode(accountID);

	if (searchResult == nullptr) {
		std::cout << "Unable to locate and account with the input ID\n" << std::endl;
		return false;
	}

	std::cout << "Account ID: " << searchResult->account_id << "\n";
	std::cout << "Account Owner: " << searchResult->last_name << ", " << searchResult->first_name << "\n";
	std::cout << "Contact Number: " << searchResult->phone_number << "\n";
	std::cout << "Balance: " << searchResult->account_balance << "\n" << std::endl;

	return true;
}

bool accWithdraw(MemberAccountTree& dbTree, std::string& filename) {
	// Query User for Account ID to Withdraw From
	std::cout << "Enter Account ID for Withdrawl\n" << std::endl;
	std::string accountIDInput;
	std::cin >> accountIDInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	long accountID = atol(accountIDInput.c_str());
	if (accountID == 0)
	{
		std::cout << "Invalid Account ID Entry, Please Re-Enter Account ID Value to Retrieve\n" << std::endl;
		return false;
	}

	// Retrieve Account to Perform Withdrawl From
	MemberAccountNode* searchResult = dbTree.findNode(accountID);
	if (searchResult == nullptr) 
	{
		std::cout << "Unable to locate and account with the input ID\n" << std::endl;
		return false;
	}

	// Query User for Withdrawl Amount
	std::cout << "How much would you like to withdraw?\n" << std::endl;
	std::string withdrawlAmountInput;
	std::cin >> withdrawlAmountInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	// Validate Withdrawl Operation
	long long withdrawlAmount = atoll(withdrawlAmountInput.c_str());
	if (withdrawlAmount > searchResult->account_balance) 
	{
		std::cout << "Insufficient Funds\n" << std::endl;
		return false;
	}

	// Update the Object in the Tree
	searchResult->account_balance = searchResult->account_balance - withdrawlAmount;

	// Update Database File
	std::fstream dbct_os("acc_temp.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::app);
	if (!dbct_os.is_open()) 
	{
		std::cout << "Withdraw Failed - Failed to Update Account Database" << std::endl;
		return false;
	}
	std::string updatedTree = dbTree.buildStorageData( static_cast<MemberAccountNode*>(dbTree.getTreeRoot()) );
	dbct_os.write(updatedTree.c_str(), updatedTree.length());
	dbct_os.close();
	remove(filename.c_str());
	int renameCheck = rename("acc_temp.bin", filename.c_str());
	if (renameCheck != 0)
	{
		perror("Error encountered when renaming file");
		return false;
	}

	// Notify User and Exit
	std::cout << "Withdrew: " << withdrawlAmount;
	std::cout << "\n\nRemaining Balance: " << searchResult->account_balance << std::endl;
	return true;
}



bool accDeposit(MemberAccountTree& dbTree, std::string& filename) {
	// Query User for Account ID to Deposit To
	std::cout << "Enter Account ID for Deposit\n" << std::endl;
	std::string accountIDInput;
	std::cin >> accountIDInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	long accountID = atol(accountIDInput.c_str());
	if (accountID == 0)
	{
		std::cout << "Invalid Account ID Entry, Please Re-Enter Account ID Value to Retrieve\n" << std::endl;
		return false;
	}

	// Retrieve Account to Perform Deposit To
	MemberAccountNode* searchResult = dbTree.findNode(accountID);
	if (searchResult == nullptr)
	{
		std::cout << "Unable to locate and account with the input ID\n" << std::endl;
		return false;
	}

	// Query User for Deposit Amount
	std::cout << "How much would you like to deposit?\n" << std::endl;
	std::string depositAmountInput;
	std::cin >> depositAmountInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Update the Object in the Tree
	long long depositAmount = atoll(depositAmountInput.c_str());
	searchResult->account_balance = searchResult->account_balance + depositAmount;

	// Update Database File
	std::fstream dbct_os("acc_temp.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::app);
	if (!dbct_os.is_open())
	{
		std::cout << "Deposit Failed - Failed to Update Account Database" << std::endl;
		return false;
	}
	std::string updatedTree = dbTree.buildStorageData(static_cast<MemberAccountNode*>(dbTree.getTreeRoot()));
	dbct_os.write(updatedTree.c_str(), updatedTree.length());
	dbct_os.close();
	remove(filename.c_str());
	int renameCheck = rename("acc_temp.bin", filename.c_str());
	if (renameCheck != 0)
	{
		perror("Error encountered when renaming file");
		return false;
	}

	// Notify User and Exit
	std::cout << "Deposited: " << depositAmount;
	std::cout << "\n\nNew Balance: " << searchResult->account_balance << std::endl;
	return true;
}




void readDBInfo(std::string& filename) {
	std::fstream fs(filename, std::ios_base::binary | std::ios_base::in);
	std::string accDataString;
	std::vector<std::string> fileIterator;

	if (!fs.is_open()) {
		std::cout << "Unable to Open Database File" << std::endl;
		return;
	}

	while (!fs.eof()) {
		std::getline(fs, accDataString);
		fileIterator.push_back(accDataString);
	}

	for (int i = 0; i < fileIterator.size(); i++) {
		std::cout << fileIterator[i] << std::endl;
	}

	fs.close();
	return;
}



int main(int argv, char* argc[]) {
	std::string dbFilename = "db_core.bin";					// This binary file will be used to track current table indicies
	std::string accFilename = "account_db.bin";			// This binary file will act as the account db table for storing the account data
	std::fstream fs;


	MemberAccountTree accDB;
	buildAccDBTree(accFilename, accDB);

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
			openAccount(accFilename, dbFilename, accDB);
			
			break;
		case 2:
			std::cout << "Check Account Balance\n" << std::endl;
			
			break;
		case 3:
			std::cout << "Withdraw Funds\n" << std::endl;
			accWithdraw(accDB, accFilename);
			break;
		case 4:
			std::cout << "Deposit Funds\n" << std::endl;
			accDeposit(accDB, accFilename);
			break;
		case 5:
			std::cout << "View Account Details\n" << std::endl;
			accSearch(accDB);
			break;

		case 6:
			std::cout << "Search Accounts\n" << std::endl;
			readDBInfo(accFilename);
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

