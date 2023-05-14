#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"

class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();

  void setup();

  std::string get_debug_string();
  

  
  int search(int value);
  int rsearch(int value);
  int rsearch(int value, Node *p);
  void insert(int value);
  void rinsert(int n, Node *v, Node *w, Node *p);
  void rinsert(int value);
  int findMinimum(Node *walker, Node *trailer);
  int findMinimum();
  void remove(int n, Node *walker, Node *trailer);
  void remove(int n);
  int findHeight(Node *node);
  int findHeight();

  int treesum();
  int treesum(Node *n);
  int countodds();
  int countodds(Node *n);
  int oddsum();
  int oddsum(Node *n);
  // int searchr(int value);
  // int searchr(int value, Node *n);
  
};
