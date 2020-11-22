#pragma once
#include "NodeInterface.h"
#include <cstddef>
using namespace std;

class Node : public NodeInterface {
	friend class AVL; // Allow AVL to access data members
public:
	Node(int value) {data = value;leftChild = NULL; rightChild = NULL;}
	~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;

  /*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  For an
	* example on height, see page 448 of the text book.
	*
	* @return the height of this tree with this node as the local root.
	*/
	virtual int getHeight();

	void setLeftChild(Node *ptr);
	void setRightChild(Node *ptr);
protected:
	Node *leftChild;
	Node *rightChild;
	int data;
  int height;
};