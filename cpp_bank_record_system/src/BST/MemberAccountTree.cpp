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
	// If the tree is empty set the root node to be equal to the current node.
	if (this->getTreeRoot() == nullptr) {
		this->setTreeRoot(add_node);
		return true;
	}

	// If account_id < root_node.account_id then
	//	if left_branch == nullptr
	//		left_branch == add_node_pointer
	//  else
	//      recursively call add_node
	// --------- This seems to indicate it might be better to implement the add/remove node on the node itself, something to think about
	//       node.add_node(new_node) { if (this.account_id > new_node.account_id) {if (this.left_branch) {this.left_branch.add_node(new_node).....

	return false;
}

bool MemberAccountTree::removeNode(BSTNode* remove_node)
{
	return false;
}
