#pragma once
#include <fstream>
#include <string>
#include "BST_Tree.h"


class MemberAccountTree : public BSTTree {
public:
	MemberAccountTree();

	// The Initialize Tree Function is intended for use on startup when the tree structure is first created or is being restored from a static data store.
	bool initializeTree() override;

	bool addNode(BSTNode* add_node) override;

	bool removeNode(BSTNode* remove_node) override;

	std::string printTree(MemberAccountNode* node, int depth = 0);

};