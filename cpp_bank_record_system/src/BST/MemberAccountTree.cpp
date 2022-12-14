#include <iostream>
#include <vector>
#include "MemberAccountTree.h"
#include "../MemberAccount.h"

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
				operationNode->source_node = comparisonNode;
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
				operationNode->source_node = comparisonNode;
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
	int depthFromSwap = 0;
	MemberAccountNode* comparisonNode = static_cast<MemberAccountNode*>(getTreeRoot());
	MemberAccountNode* swapNode;

	// Search for the target node
	while (!removeComplete) {
		// Target Node Found
		if (operationNode->account_id == comparisonNode->account_id) {
			// If the right branch node exists we need to find the leaf to swap in to keep the tree consistant (furtherst left leaf off the first node of the right branch)
			if (static_cast<MemberAccountNode*>(comparisonNode->right_branch) != nullptr && !removeComplete) {
				swapNode = static_cast<MemberAccountNode*>(comparisonNode->right_branch);

				while (swapNode->left_branch != nullptr) {
					swapNode = static_cast<MemberAccountNode*>(swapNode->left_branch);
					depthFromSwap++;
				}


				// If there are children nodes on the right branch from the selected swap node these need to be relinked
				if (swapNode->right_branch != nullptr && depthFromSwap > 0) {
					swapNode->source_node->left_branch = swapNode->right_branch;
					swapNode->right_branch->source_node = swapNode->source_node;
				}
				// Else the swap node was a leaf and we need to update the precusor node to to be nullptr on its left branch
				else if (depthFromSwap > 0)
				{
					swapNode->source_node->left_branch = nullptr;
				}


				// If the Source of the Comparison Node is not null we need to reassign the source not to point to the swapNode
				if (comparisonNode->source_node != nullptr && static_cast<MemberAccountNode*>(comparisonNode->source_node->right_branch)->account_id == comparisonNode->account_id ) 
				{
					comparisonNode->source_node->right_branch = swapNode;
				} 
				else if (comparisonNode->source_node != nullptr && static_cast<MemberAccountNode*>(comparisonNode->source_node->left_branch)->account_id == comparisonNode->account_id) 
				{
					comparisonNode->source_node->left_branch = swapNode;
				}
				else if (comparisonNode->source_node == nullptr) // Comparison Node is the Root
				{
					this->setTreeRoot(swapNode);
				}


				// If there is a left branch from the comparison node update its source to point to the swapNode
				if (comparisonNode->left_branch != nullptr) {
					comparisonNode->left_branch->source_node = swapNode;
				}

				// If there is a right branch from the comparison node update its source to point to the swapNode
				if (comparisonNode->right_branch != nullptr) {
					comparisonNode->right_branch->source_node = swapNode;
				}

				// Update the Swap Node to point to the locations the comparision node used to
				swapNode->source_node = comparisonNode->source_node;
				swapNode->left_branch = comparisonNode->left_branch;

				if (depthFromSwap > 0) {
					swapNode->right_branch = comparisonNode->right_branch;
				}
				

				// We are done with the remove node operation, return space allocated for the comparisonNode back to the operating system
				removeComplete = true;
			}


			// If the remove operation is not complete and the left branch node exists we need to find the leaf to swap in to keep the tree consistant (furtherst right leaf of the left branch)
			if (static_cast<MemberAccountNode*>(comparisonNode->left_branch) != nullptr && !removeComplete) {
				swapNode = static_cast<MemberAccountNode*>(comparisonNode->left_branch);

				while (swapNode->right_branch != nullptr) {
					swapNode = static_cast<MemberAccountNode*>(swapNode->right_branch);
					depthFromSwap++;
				}


				// If there are children nodes on the right branch from the selected swap node these need to be relinked
				if (swapNode->left_branch != nullptr && depthFromSwap > 0) {
					swapNode->source_node->right_branch = swapNode->left_branch;
					swapNode->left_branch->source_node = swapNode->source_node;
				}
				// Else the swap node was a leaf and we need to update the precusor node to to be nullptr on its left branch
				else if (depthFromSwap > 0)
				{
					swapNode->source_node->right_branch = nullptr;
				}


				// If the Source of the Comparison Node is not null we need to reassign the source not to point to the swapNode
				if (comparisonNode->source_node != nullptr && static_cast<MemberAccountNode*>(comparisonNode->source_node->right_branch)->account_id == comparisonNode->account_id) 
				{
					comparisonNode->source_node->right_branch = swapNode;
				}
				else if (comparisonNode->source_node != nullptr && static_cast<MemberAccountNode*>(comparisonNode->source_node->left_branch)->account_id == comparisonNode->account_id) 
				{
					comparisonNode->source_node->left_branch = swapNode;
				}
				else if (comparisonNode->source_node == nullptr) // Comparison Node is the Root
				{
					this->setTreeRoot(swapNode);
				}


				// If there is a left branch from the comparison node update its source to point to the swapNode
				if (comparisonNode->left_branch != nullptr) {
					comparisonNode->left_branch->source_node = swapNode;
				}

				// If there is a right branch from the comparison node update its source to point to the swapNode
				if (comparisonNode->right_branch != nullptr) {
					comparisonNode->right_branch->source_node = swapNode;
				}

				// Update the Swap Node to point to the locations the comparision node used to
				swapNode->source_node = comparisonNode->source_node;
				swapNode->right_branch = comparisonNode->right_branch;
				if (depthFromSwap > 0) {
					swapNode->left_branch = comparisonNode->left_branch;
				}

				// We are done with the remove node operation, return space allocated for the comparisonNode back to the operating system
				removeComplete = true;
			}


			// If the remove operation still is not complete the node removed was a leaf itself.  It's source needs to have its pointer cleared in the tree
			if (!removeComplete) {
				if (comparisonNode->source_node != nullptr && 
					comparisonNode->source_node->left_branch != nullptr &&
					comparisonNode->account_id == static_cast<MemberAccountNode*>(comparisonNode->source_node->left_branch)->account_id) 
				{
					comparisonNode->source_node->left_branch = nullptr;
					removeComplete = true;
				}
				else if (
					comparisonNode->source_node != nullptr &&
					comparisonNode->source_node->right_branch != nullptr &&
					comparisonNode->account_id == static_cast<MemberAccountNode*>(comparisonNode->source_node->right_branch)->account_id)
				{
					comparisonNode->source_node->right_branch = nullptr;
					removeComplete = true;
				}
				else
				{
					std::cout << "Error while removing node from the tree, comparison node not found on source" << std::endl;
				}
			}
		}

		if (removeComplete) {
			// Need to make sure this is using heap storage, might not be right now
			//			delete comparisonNode;
			return rSuccess;
		} 
		else
		{
			if (operationNode->account_id > comparisonNode->account_id) {
				comparisonNode = static_cast<MemberAccountNode*>(comparisonNode->right_branch);
			}
			else
			{
				comparisonNode = static_cast<MemberAccountNode*>(comparisonNode->left_branch);
			}

			if (comparisonNode == nullptr) {
				removeComplete = true;
				rSuccess = false;
				std::cout << "Node not found" << std::endl;
			}
		}
	}

	

	return rSuccess;
}

MemberAccountNode* MemberAccountTree::findNode(int accountNumber) {
	bool nodeFound = false;
	MemberAccountNode* currentNode = static_cast<MemberAccountNode*>(getTreeRoot());

	while (!nodeFound)
	{
		// Current Node is the target node
		if (currentNode != nullptr && accountNumber == currentNode->account_id) {
			nodeFound = true;
		}
		else if (currentNode != nullptr && accountNumber > currentNode->account_id) {
			currentNode = static_cast<MemberAccountNode*>(currentNode->right_branch);
		}
		else if (currentNode != nullptr && accountNumber > currentNode->account_id) {
			currentNode = static_cast<MemberAccountNode*>(currentNode->left_branch);
		}
		else
		{
			nodeFound = true;
		}
	}

	return currentNode;
}

std::string MemberAccountTree::printTree(MemberAccountNode* node, int depth)
{
	std::string subtreeLeft;
	std::string subtreeRight;
	if (node != nullptr) {
		if (node->left_branch != nullptr) {
			subtreeLeft = printTree(static_cast<MemberAccountNode*>(node->left_branch), depth + 1);
		}

		if (node->right_branch != nullptr) {
			subtreeRight = printTree(static_cast<MemberAccountNode*>(node->right_branch), depth + 1);
		}

		return std::to_string(node->account_id) + "\t l:" + subtreeLeft + "\t r:" + subtreeRight + "\n";
		//std::cout << depth << ":  " << node->account_id << std::endl;
		//std::cout << node->account_id;
	}
	else
	{
		return "";
	}
}


std::string MemberAccountTree::buildStorageData(MemberAccountNode* node) {
	std::string subtreeLeft;
	std::string subtreeRight;
	if (node != nullptr) {
		if (node->left_branch != nullptr) {
			subtreeLeft = buildStorageData(static_cast<MemberAccountNode*>(node->left_branch));
		}

		if (node->right_branch != nullptr) {
			subtreeRight = buildStorageData(static_cast<MemberAccountNode*>(node->right_branch));
		}
		
		std::string accountData = MemberAccount(node->account_id, node->first_name, node->last_name, node->phone_number, node->account_balance).CreateEntry();

		return accountData + subtreeLeft + subtreeRight;
		//std::cout << depth << ":  " << node->account_id << std::endl;
		//std::cout << node->account_id;
	}
}