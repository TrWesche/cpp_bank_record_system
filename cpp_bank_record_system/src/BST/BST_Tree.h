#pragma once
#include "BST_Node.h"

class BSTTree {
public:
	BSTTree(): mRoot(nullptr) {};

	// The Initialize Tree Function is intended for use on startup when the tree structure is first created or is being restored from a static data store.
	virtual bool initializeTree();
	
	virtual bool addNode(BSTNode* add_node);
	
	virtual bool removeNode(BSTNode* remove_node);

	// These might need to be implemented with the ability to dynamically asign the node type instead of always using BSTNode.
	virtual BSTNode* getTreeRoot() { return mRoot; }
	virtual void setTreeRoot(BSTNode* root_node) { mRoot = root_node; }

private:
	BSTNode* mRoot = nullptr;
};