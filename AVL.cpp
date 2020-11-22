#include "AVL.h"
#include "Node.h"
#include <iostream>
using namespace std;
  /*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * AVL::getRootNode() const
	{
    return root;
	}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool AVL::add(int data)
	{
	  return insert(this->root, data);
	}

  bool AVL::insert( Node*& local_root, int data) {
    bool inserted = false;
    if (local_root == NULL) {
      local_root = new Node(data);
      local_root->leftChild = NULL;
      local_root->rightChild = NULL;
      inserted = true;
      return inserted;
   } else if (data < local_root->data) {
      inserted = insert(local_root->leftChild, data);
      local_root = balance(local_root);
      return inserted;
   } else if (data > local_root->data) {
      inserted = insert(local_root->rightChild, data);
      local_root = balance(local_root);
      return inserted;
   } return inserted;
  }

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool AVL::remove(int data) 
	{
    return erase(this->root, data);
	}

  bool AVL::erase( Node*& local_root, int data) {
    bool erased = false;
    if (local_root == NULL) { 
      return erased; 
    } else { 
      if (data < local_root->data) {
        erased = erase(local_root->leftChild, data);
        local_root = balance(local_root);
        return erased;
      }
      else if (local_root->data < data) {
        erased = erase(local_root->rightChild, data); 
        local_root = balance(local_root);
        return erased;
      }
      else { // Found item 
        Node* old_root = local_root; 
        if (local_root->leftChild == NULL) { 
          local_root = local_root->rightChild; 
        } else if (local_root->rightChild == NULL) { 
          local_root = local_root->leftChild; 
        } else { 
          replace_parent(old_root, old_root->leftChild); 
        } 
        delete old_root; 
        old_root = NULL;
        local_root = balance(local_root);
        erased = true;
        return erased;
      }
    }
  }

  void AVL::replace_parent( Node*& old_root, Node*& local_root) {
    if (local_root->rightChild != NULL) { 
      replace_parent(old_root, local_root->rightChild);
    } else { 
      old_root->data = local_root->data; 
      old_root = local_root; 
      local_root = local_root->leftChild;
      delete old_root;
      old_root = NULL;
    }
  }

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void AVL::clear()
	{
    deleteAVL(root);
	}


  void AVL::deleteAVL(Node*& local_root) {
    if(local_root == NULL) {
      return;
    }
    deleteAVL(local_root->leftChild);
    deleteAVL(local_root->rightChild);
    delete local_root;
    local_root = NULL;
  }

  int AVL::height(Node *&t) {
    int h = 0;
    if (t != NULL) {
      int l_height = height(t->leftChild);
      int r_height = height(t->rightChild);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
    }
    return h;
}
int AVL::difference(Node *&t) {
  if (t == NULL) {
    return 0;
  }
  int l_height = height(t->leftChild);
  int r_height = height(t->rightChild);
  int b_factor = l_height - r_height;
  return b_factor;
}
Node *AVL::rr_rotat(Node *&parent) {
   Node *t;
   t = parent->rightChild;
   parent->rightChild = t->leftChild;
   t->leftChild = parent;
   cout<<"Right-Right Rotation";
   return t;
}
Node *AVL::ll_rotat(Node *&parent) {
   Node *t;
   t = parent->leftChild;
   parent->leftChild = t->rightChild;
   t->rightChild = parent;
   cout<<"Left-Left Rotation";
   return t;
}
Node *AVL::lr_rotat(Node *&parent) {
   Node *t;
   t = parent->leftChild;
   parent->leftChild = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
Node *AVL::rl_rotat(Node *&parent) {
   Node *t;
   t = parent->rightChild;
   parent->rightChild = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
Node *AVL::balance(Node *&t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->leftChild) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->rightChild) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}

