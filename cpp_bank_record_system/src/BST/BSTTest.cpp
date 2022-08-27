#include <iostream>
#include "BST_Node.h"
#include "MemberAccountTree.h"

// TODO: Fully automate the testing, this should be checking the output to make sure the outcome of each operation is expected.
//      - Remove Code Roughed In
//      - Add tests not implemented
//		- Search tests not implemented

MemberAccountTree BuildTestTree() {
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

	return testTree;
}


bool BSTRemoveTest(MemberAccountTree& testTree, long removeID) {
	std::string fn = "FirstName";
	std::string ln = "LastName";
	std::string pn = "123-456-7890";
	long long ab = 123456;

	MemberAccountNode removeTgt = MemberAccountNode(removeID, fn, ln, pn, ab);

	testTree.removeNode(&removeTgt);

	std::cout << "\nAfter Updates - Removing: " << removeID << std::endl;

	std::cout << testTree.printTree(static_cast<MemberAccountNode*>(testTree.getTreeRoot()));

	

	return true;
}

void BSTTestProcedure() {
	MemberAccountTree testTree = BuildTestTree();

	BSTRemoveTest(testTree, 80);
	BSTRemoveTest(testTree, 100);
	BSTRemoveTest(testTree, 60);
	BSTRemoveTest(testTree, 70);
	BSTRemoveTest(testTree, 5);
	BSTRemoveTest(testTree, 20);
	BSTRemoveTest(testTree, 40);
	BSTRemoveTest(testTree, 30);
	BSTRemoveTest(testTree, 50);

}