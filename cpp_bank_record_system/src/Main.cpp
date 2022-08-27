#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MemberAccount.h"
#include "BST/BST_Node.h"
#include "BST/MemberAccountTree.h"

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


bool BSTTesting(std::fstream& fs, std::string& filename)
{
	MemberAccountTree testTree;

	long accid_a = 10;
	std::string fn_a = "FirstName1";
	std::string ln_a = "LastName1";
	std::string pn_a = "111-456-7890";
	long long ab_a = 111545;

	MemberAccountNode node_a = MemberAccountNode(accid_a, fn_a, ln_a, pn_a, ab_a);



	long accid_b = 2;
	std::string fn_b = "FirstName2";
	std::string ln_b = "LastName2";
	std::string pn_b = "222-456-7890";
	long long ab_b = 222;

	MemberAccountNode node_b = MemberAccountNode(accid_b, fn_b, ln_b, pn_b, ab_b);


	long accid_c = 30;
	std::string fn_c = "FirstName3";
	std::string ln_c = "LastName3";
	std::string pn_c = "333-456-7890";
	long long ab_c = 333333;

	MemberAccountNode node_c = MemberAccountNode(accid_c, fn_c, ln_c, pn_c, ab_c);


	long accid_d = 50;
	std::string fn_d = "FirstName4";
	std::string ln_d = "LastName4";
	std::string pn_d = "444-456-7890";
	long long ab_d = 444444;

	MemberAccountNode node_d = MemberAccountNode(accid_d, fn_d, ln_d, pn_d, ab_d);


	long accid_e = 21;
	std::string fn_e = "FirstName5";
	std::string ln_e = "LastName5";
	std::string pn_e = "555-456-7890";
	long long ab_e = 55555;

	MemberAccountNode node_e = MemberAccountNode(accid_e, fn_e, ln_e, pn_e, ab_e);



	testTree.addNode(&node_a);
	testTree.addNode(&node_b);
	testTree.addNode(&node_c);
	testTree.addNode(&node_d);
	testTree.addNode(&node_e);



	testTree.removeNode(&node_c);

	return true;
}


bool BSTTest1() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()) );

	testTree.removeNode(&node_24);

	std::cout << "\nAfter Updates - Removing: " << node_24.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}

bool BSTTest2() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	testTree.removeNode(&node_7);

	std::cout << "\nAfter Updates - Removing: " << node_7.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}

bool BSTTest3() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	testTree.removeNode(&node_6);

	std::cout << "\nAfter Updates - Removing: " << node_6.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}

bool BSTTest4() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	testTree.removeNode(&node_3);

	std::cout << "\nAfter Updates - Removing: " << node_3.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}



bool BSTTest5() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()) );

	testTree.removeNode(&node_8);

	std::cout << "\nAfter Updates - Removing: " << node_8.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}

bool BSTTest6() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	testTree.removeNode(&node_9);

	std::cout << "\nAfter Updates - Removing: " << node_9.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}

bool BSTTest7() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	testTree.removeNode(&node_5);

	std::cout << "\nAfter Updates - Removing: " << node_5.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}

bool BSTTest8() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	testTree.removeNode(&node_2);

	std::cout << "\nAfter Updates - Removing: " << node_2.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	return true;
}




bool BSTTestRoot() {
	MemberAccountTree testTree;

	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	long accid_1 = 50;

	long accid_2 = 30;
	long accid_3 = 70;

	long accid_4 = 10;
	long accid_5 = 40;
	long accid_6 = 60;
	long accid_7 = 100;

	long accid_8 = 5;
	long accid_9 = 20;
	long accid_10 = 35;
	long accid_11 = 45;
	long accid_12 = 55;
	long accid_13 = 65;
	long accid_14 = 85;
	long accid_15 = 110;

	long accid_16 = 15;
	long accid_17 = 25;
	long accid_18 = 36;
	long accid_19 = 63;
	long accid_20 = 75;

	long accid_21 = 24;
	long accid_22 = 38;
	long accid_23 = 61;
	long accid_24 = 80;

	MemberAccountNode node_1 = MemberAccountNode(accid_1, fn, ln, pn, ab);
	testTree.addNode(&node_1);

	MemberAccountNode node_2 = MemberAccountNode(accid_2, fn, ln, pn, ab);
	testTree.addNode(&node_2);

	MemberAccountNode node_3 = MemberAccountNode(accid_3, fn, ln, pn, ab);
	testTree.addNode(&node_3);

	MemberAccountNode node_4 = MemberAccountNode(accid_4, fn, ln, pn, ab);
	testTree.addNode(&node_4);

	MemberAccountNode node_5 = MemberAccountNode(accid_5, fn, ln, pn, ab);
	testTree.addNode(&node_5);

	MemberAccountNode node_6 = MemberAccountNode(accid_6, fn, ln, pn, ab);
	testTree.addNode(&node_6);

	MemberAccountNode node_7 = MemberAccountNode(accid_7, fn, ln, pn, ab);
	testTree.addNode(&node_7);

	MemberAccountNode node_8 = MemberAccountNode(accid_8, fn, ln, pn, ab);
	testTree.addNode(&node_8);

	MemberAccountNode node_9 = MemberAccountNode(accid_9, fn, ln, pn, ab);
	testTree.addNode(&node_9);

	MemberAccountNode node_10 = MemberAccountNode(accid_10, fn, ln, pn, ab);
	testTree.addNode(&node_10);

	MemberAccountNode node_11 = MemberAccountNode(accid_11, fn, ln, pn, ab);
	testTree.addNode(&node_11);

	MemberAccountNode node_12 = MemberAccountNode(accid_12, fn, ln, pn, ab);
	testTree.addNode(&node_12);

	MemberAccountNode node_13 = MemberAccountNode(accid_13, fn, ln, pn, ab);
	testTree.addNode(&node_13);

	MemberAccountNode node_14 = MemberAccountNode(accid_14, fn, ln, pn, ab);
	testTree.addNode(&node_14);

	MemberAccountNode node_15 = MemberAccountNode(accid_15, fn, ln, pn, ab);
	testTree.addNode(&node_15);

	MemberAccountNode node_16 = MemberAccountNode(accid_16, fn, ln, pn, ab);
	testTree.addNode(&node_16);

	MemberAccountNode node_17 = MemberAccountNode(accid_17, fn, ln, pn, ab);
	testTree.addNode(&node_17);

	MemberAccountNode node_18 = MemberAccountNode(accid_18, fn, ln, pn, ab);
	testTree.addNode(&node_18);

	MemberAccountNode node_19 = MemberAccountNode(accid_19, fn, ln, pn, ab);
	testTree.addNode(&node_19);

	MemberAccountNode node_20 = MemberAccountNode(accid_20, fn, ln, pn, ab);
	testTree.addNode(&node_20);

	MemberAccountNode node_21 = MemberAccountNode(accid_21, fn, ln, pn, ab);
	testTree.addNode(&node_21);

	MemberAccountNode node_22 = MemberAccountNode(accid_22, fn, ln, pn, ab);
	testTree.addNode(&node_22);

	MemberAccountNode node_23 = MemberAccountNode(accid_23, fn, ln, pn, ab);
	testTree.addNode(&node_23);

	MemberAccountNode node_24 = MemberAccountNode(accid_24, fn, ln, pn, ab);
	testTree.addNode(&node_24);

	//std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	testTree.removeNode(&node_1);

	std::cout << "\nAfter Updates - Removing: " << node_1.account_id << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

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
			BSTTesting(fs, accFilename);

			break;
		case 4:
			std::cout << "Deposit Funds\n" << std::endl;

			//BSTTest1();
			//BSTTest5();
			BSTTestRoot();
			break;
		case 5:
			std::cout << "View Account Details\n" << std::endl;

			//BSTTest2();
			//BSTTest6();
			break;
		case 6:
			std::cout << "Search Accounts\n" << std::endl;

			//BSTTest3();
			//BSTTest7();
			break;
		case 7:
			std::cout << "Close An Account\n" << std::endl;

			//BSTTest4();
			//BSTTest8();
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

