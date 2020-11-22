#pragma once

#include "NodeInterface.h"
#include <cstddef> // TO FIX: error: ‘NULL’ was not declared in this scope
#include "AVLInterface.h"
#include "Node.h"

using namespace std;

class AVL : public AVLInterface {
public:
	AVL() { root = NULL;}
	virtual ~AVL() {}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode() const;

	/*
	* Attempts to add the given int to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	/*
	* Attempts to remove the given int from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();

protected:
	Node *root;
private:
  bool insert( Node*& local_root, int data); //Add helper FUnction
  bool erase( Node*& local_root, int data); //Remove helper function
  void replace_parent(Node*& old_root, Node*& local_root); //Remove helper function
  void deleteAVL(Node*& local_root); //Clear helper function in PostOrder deletion
  int height(Node *&t);
  int difference(Node *& t);
  Node *rr_rotat(Node *&parent);
  Node *ll_rotat(Node *&parent);
  Node *lr_rotat(Node *&parent);
  Node *rl_rotat(Node *&parent);
  Node * balance(Node *&parent);
};