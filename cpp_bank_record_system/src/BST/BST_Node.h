#pragma once
#include <string>

//class BST_NODE {
//public:
//	BST_NODE(int data, BST_NODE* left_branch, BST_NODE* right_branch) {};
//
//	int data;
//
//	BST_NODE* leftBranch = nullptr;
//	BST_NODE* rightBranch = nullptr;
//};



class BSTNode {
public:
	BSTNode(BSTNode* lbranch, BSTNode* rbranch): left_branch(lbranch), right_branch(rbranch) {};

	BSTNode* left_branch = nullptr;
	BSTNode* right_branch = nullptr;
};


class SimpleNode : public BSTNode {
public:
	SimpleNode(int data);

	int data_internal = 0;
};


class MemberAccountNode : public BSTNode {
public:
	MemberAccountNode(long acc_id, std::string fname, std::string lname, std::string phone, long long balance);

	long account_id = 0;
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	long long account_balance = 0;

};