#include "BST_Node.h"


//BSTNode::BSTNode(BSTNode* lbranch, BSTNode* rbranch)
//{
//	right_branch = rbranch;
//	left_branch = lbranch;
//}



MemberAccountNode::MemberAccountNode(long acc_id, std::string fname, std::string lname, std::string phone, long long balance) : BSTNode(nullptr, nullptr, nullptr)
{
	account_id = acc_id;
	first_name = fname;
	last_name = lname;
	phone_number = phone;
	account_balance = balance;
}



SimpleNode::SimpleNode(int data) : BSTNode(nullptr, nullptr, nullptr)
{
	data_internal = data;
}


//
//
//long AccountID = 1;
//std::string FirstName = "FirstName1";
//std::string LastName = "LastName1";
//std::string PhoneNumber = "123-456-7890";
//long long AccountBalance = 123;
//
//MemberAccountNode* test = new MemberAccountNode(AccountID, FirstName, LastName, PhoneNumber, AccountBalance);