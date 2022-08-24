#include <iostream>
#include "MemberAccountTree.h"

MemberAccountTree::MemberAccountTree()
{
}

bool MemberAccountTree::initializeTree()
{
	// This will need to be able to loop over a file and build a tree from the data contained in the file
	return false;
}

bool MemberAccountTree::addNode(BSTNode* add_node)
{
	MemberAccountNode* operationNode = static_cast<MemberAccountNode*>(add_node);
	if (!operationNode) {
		return false;
	}

	// If the tree is empty set the root node to be equal to the current node.
	if (this->getTreeRoot() == nullptr) {
		this->setTreeRoot(operationNode);
		return true;
	}
	

	bool rSuccess = false;
	bool insertComplete = false;
	MemberAccountNode* comparisonNode = static_cast<MemberAccountNode*>(getTreeRoot());

	while (!insertComplete) {
		if (operationNode->account_id > comparisonNode->account_id) 
		{
			if (comparisonNode->right_branch == nullptr) {
				comparisonNode->right_branch = operationNode;
				insertComplete = true;
				rSuccess = true;
			}
			else {
				comparisonNode = static_cast<MemberAccountNode*>(comparisonNode->right_branch);
			}
		}
		else if (operationNode->account_id < comparisonNode->account_id) 
		{
			if (comparisonNode->left_branch == nullptr) 
			{
				comparisonNode->left_branch = operationNode;
				insertComplete = true;
				rSuccess = true;
			}
			else 
			{
				comparisonNode = static_cast<MemberAccountNode*>(comparisonNode->left_branch);
			}
		}
		else 
		{
			std::cout << "Non-Unique Identifier in Tree!" << std::endl;
			insertComplete = true;
			rSuccess = false;
		}
	}

	return rSuccess;
}

bool MemberAccountTree::removeNode(BSTNode* remove_node)
{
	MemberAccountNode* operationNode = static_cast<MemberAccountNode*>(remove_node);
	if (!operationNode) {
		return false;
	}

	// If the root node is missing something is wrong, tree should be empty
	if (this->getTreeRoot() == nullptr) {
		return false;
	}

	bool rSuccess = false;
	bool removeComplete = false;
	MemberAccountNode* comparisonNode = static_cast<MemberAccountNode*>(getTreeRoot());



	return rSuccess;
}
