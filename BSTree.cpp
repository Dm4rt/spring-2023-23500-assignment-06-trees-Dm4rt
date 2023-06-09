#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}




// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
  std::string a,b,c;
  
  if (n==nullptr){
    return "";
  } else {


    /*
     *  pre-order traversal
     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree

     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());


     * post-order traversal

     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node
      
     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());

    */

    /*  
	in-order traversal

	1. recurse left subtree
	2. process node
	3. recurse right subtree
    */

    a = traverse(n->getLeft());
    b = std::to_string(n->getData());
    c = traverse(n->getRight());
    

return a + ", " + b+ ", " + c;

     
  }
}

std::string BSTree::get_debug_string(){
  return traverse(root);
}

/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)

*/
int BSTree::search(int n){
  Node *current = root;

  
  while (current != nullptr){
    int node_val = current->getData();
    if (n == node_val){
      return node_val;
    } else if (n < node_val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  throw 1; // returning a not found value would be better
  
}

//Trying to make rsearch Part 1
int BSTree::rsearch(int value, Node *p){
	if(p==nullptr){
		throw std::out_of_range("not found value");
		//return;
	}
	int node_val = p->getData();
	if(node_val == value){
		return node_val;
	}
	else if(value < node_val){
		return rsearch(value, p->getLeft());
	}
	else{
		return rsearch(value, p->getRight());
	}
  	
}
int BSTree::rsearch(int value){
	Node *current =  root;
	if(current == nullptr){
		throw std::out_of_range("empty tree search");
	}
	return rsearch(value, root);
}


/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)
*/
void BSTree::insert(int n){
  Node *new_node = new Node(n);

  // special case if the tree is empty
  if (root == nullptr){
    root = new_node;
    return;
  }

  // search for the insertion point
  Node *current = root;
  Node *trailer = nullptr;
  while (current != nullptr){
    trailer = current; // catch the trailer up
    int val = current->getData();
    if (n == val){
      // update the node with the additional stuff
      return;
    } else if (n < val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  // if we get here, trailer points to the
  // node above the new node's location
  if (n < trailer->getData()){
    trailer->setLeft(new_node);
  } else {
    trailer->setRight(new_node);
  }
     
}

//attempt recursive insert
void BSTree::rinsert(int n, Node *v, Node *w, Node *p){
	if(w==nullptr){
		if (n < p->getData()){
    			p->setLeft(v);
  		} else {
    			p->setRight(v);
  		}
		return;
	}
	
	if(n < w->getData()){
		rinsert(n, v, w->getLeft(),w);
	}
	else if(n > w->getData()){
		rinsert(n, v, w->getRight(),w);
	}else{
		//assume values are same so increment
	}
	
	
}
void BSTree::rinsert(int n){
	Node *new_node = new Node(n);
	// special case if the tree is empty
  	if (root == nullptr){
    		root = new_node;
    		return;
  	}
  	Node *trailer = nullptr;
  	Node *walker = root;
  	rinsert(n, new_node, walker, trailer);
}

//attempting part 2 delete function
int BSTree::findMinimum(Node *walker, Node *trailer){
	if(walker==nullptr){
		throw std::out_of_range("empty tree search");
	}
	trailer=walker; //catch up trailer
	if(walker->getLeft()==nullptr){
		return trailer->getData();
	}
	return findMinimum(walker->getLeft(),trailer);
}

int BSTree::findMinimum(){
	if(root==nullptr){
		throw std::out_of_range("empty tree search");
	}
	Node *walker=root;
	Node *trailer=nullptr;
	return findMinimum(walker, trailer);
}
void BSTree::remove(int n, Node *walker, Node *trailer){
	if(walker->getData()==n){
		//check if has children
		Node *left = walker->getLeft();
		Node *right = walker->getRight();
		if(left==nullptr && right ==nullptr){
			//has no children
			if(n>trailer->getData()){
				trailer->setRight(nullptr);
			}
			else{
				trailer->setLeft(nullptr);
			}
		}
		else{
			//three subcases:
			if(left==nullptr&&right!=nullptr){
				//has only right child
				if(n>trailer->getData()){
					trailer->setRight(right);
				}
				else{
					trailer->setLeft(right);
				}			
			}
			else if(left!=nullptr&&right==nullptr){
				//has only left child
				if(n>trailer->getData()){
					trailer->setRight(left);
				}
				else{
					trailer->setLeft(left);
				}
			}
			else{
				//has both children
				trailer = walker;
				int min = findMinimum(walker->getRight(), walker);
				//remove min value first, so as to not conflict
				remove(min);
				//replace trailer data with min data
				trailer->setData(min);
				
			}
		}
		return;
	}
	else if(walker->getData()<n){
		remove(n, walker->getRight(), walker);
	}
	else{
		remove(n, walker->getLeft(), walker);
	}
}
void BSTree::remove(int n){
	//special case if tree is empty
	if (root == nullptr){
    		throw std::out_of_range("empty tree remove");
  	}
  	
  	//special case, if root is value
  	if(root->getData()==n){
  		root = nullptr;
  		return;
  	}
  	
  	Node *trailer = nullptr;
  	Node *walker = root;
  	remove(n, walker, trailer);
}
int BSTree::findHeight(Node* node){
    	if (node == nullptr) {
		return 0;
    	} else {
		int left_height = findHeight(node->getLeft());
		int right_height = findHeight(node->getRight());
		return std::max(left_height, right_height) + 1;
    	}
}
int BSTree::findHeight(){
	if(root==nullptr){
		return 0;
	}
	Node *new_node = root;
	return findHeight(new_node);
}
int BSTree::countLeaves(Node *node){
	if(node == nullptr){
		return 0;
	}
	else if(node->getLeft() == nullptr && node->getRight() == nullptr){
		return 1;
	}
	else{
		return countLeaves(node->getLeft())+countLeaves(node->getRight());
	}
}
int BSTree::countLeaves(){
	if (root == nullptr) {
        	return 0;
    	}
    	Node *new_node = root;
	return countLeaves(new_node);
}
int BSTree::treesum(Node *n){
  if (n==nullptr){
    return 0;
  } else {
    int value = n->getData();
    return value + treesum(n->getLeft())
      + treesum(n->getRight());
  }
}

int BSTree::treesum(){
  return treesum(root);
}

int BSTree::countodds(Node *n){
  if (n==nullptr){
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data%2==0) {
      value = 0;
    } else {
      value = 1;
    } 
    return value + countodds(n->getLeft())
      + countodds(n->getRight());
  }
}

int BSTree::countodds(){
  return countodds(root);
}
int BSTree::oddsum(Node *n){
  if (n==nullptr){
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data%2==0) {
      value = 0;
    } else {
      value = data;
    } 
    return value + oddsum(n->getLeft())
      + oddsum(n->getRight());
  }
}

int BSTree::oddsum(){
  return oddsum(root);
}


void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);
  
}


