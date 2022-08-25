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
	MemberAccountNode* lftBranchNode;
	MemberAccountNode* rgtBranchNode;
	MemberAccountNode* swapNode;

	while (!removeComplete) {
		// Found the Target Node
		if (operationNode->account_id == comparisonNode->account_id) {
			// Save the pointers to the removed node's left and right branches
			// Might not need to do this, all of this information will exist on the comparison node (it will have the source_node, its left branch, and its right branch)
			rgtBranchNode = static_cast<MemberAccountNode*>(comparisonNode->right_branch);
			lftBranchNode = static_cast<MemberAccountNode*>(comparisonNode->left_branch);
			
			// If the right branch node exists we need to find the leaf to swap in to keep the tree consistant (furtherst left leaf of the right branch)
			if (rgtBranchNode != nullptr && !removeComplete) {
				// Handle case where there are no leafs down the left side of the right branch from the node removed point.
				if (rgtBranchNode->left_branch == nullptr) {
					rgtBranchNode->source_node = comparisonNode->source_node;
					rgtBranchNode->left_branch = comparisonNode->left_branch;
				}
				// Otherwise we need to iterate down the left branch from the right node to find the furtherest left node
				else 
				{
					swapNode = rgtBranchNode;
					while (swapNode->left_branch != nullptr) {
						swapNode = static_cast<MemberAccountNode*>(swapNode->left_branch);
					}
					// Once the swap node has been identified we need to clear the link to the swap node from its current source, and reassign it to the position in the tree that the comparison node held.
					swapNode->source_node->left_branch = nullptr;
					swapNode->source_node = comparisonNode->source_node;
					swapNode->left_branch = comparisonNode->left_branch;
					swapNode->right_branch = comparisonNode->right_branch;
				}
				removeComplete = true;
			}

			// If the left branch node exists and a node from the right side of the tree hasn't already been switched in we need to find a swap in from the left (furthest right left of the left branch)
			if (lftBranchNode != nullptr && !removeComplete) {
				// Handle case where there are no leafs down the right side of the left branch from the node removed point.
				if (lftBranchNode->right_branch == nullptr) {
					lftBranchNode->source_node = comparisonNode->source_node;
					lftBranchNode->right_branch = comparisonNode->right_branch;
				}
				// Otherwise we need to iterate down the left branch from the right node to find the furtherest left node
				else
				{
					swapNode = lftBranchNode;
					while (swapNode->right_branch != nullptr) {
						swapNode = static_cast<MemberAccountNode*>(swapNode->right_branch);
					}
					// Once the swap node has been identified we need to clear the link to the swap node from its current source, and reassign it to the position in the tree that the comparison node held.
					swapNode->source_node->right_branch = nullptr;
					swapNode->source_node = comparisonNode->source_node;
					swapNode->left_branch = comparisonNode->left_branch;
					swapNode->right_branch = comparisonNode->right_branch;
				}
				removeComplete = true;
			}

			// If the remove operation still is not complete the node removed was a leaf itself.  It's source needs to have its pointer cleared in the tree
			if (!removeComplete) {
				if (comparisonNode->source_node != nullptr && 
					comparisonNode->source_node->left_branch != nullptr &&
					comparisonNode->account_id == static_cast<MemberAccountNode*>(comparisonNode->source_node->left_branch)->account_id) 
				{
						comparisonNode->source_node->left_branch = nullptr;
				}
				else if (
					comparisonNode->source_node != nullptr &&
					comparisonNode->source_node->right_branch != nullptr &&
					comparisonNode->account_id == static_cast<MemberAccountNode*>(comparisonNode->source_node->right_branch)->account_id)
				{
					comparisonNode->source_node->right_branch = nullptr;
				}
				else
				{
					std::cout << "Error while removing node from the tree, comparison node not found on source" << std::endl;
				}
			}
		}
	}

	

	return rSuccess;
}
