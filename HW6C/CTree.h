/*
Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/14/2015
443-691-8192
*/

#ifndef _CTREE_H
#define _CTREE_H

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <cstddef>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>

using std::ostream;  using std::istream;  using std::string;  using std::cout;

// tree of characters, can be used to implement a trie

class CTree {
  friend class CTreeTest;
  char data;     // the value stored in the tree node

  CTree * kids;  // children - pointer to first child of list, maintain order & uniqueness

  CTree * sibs;  // siblings - pointer to rest of children list, maintain order & uniqueness
                 // this should always be null if the object is the root of a tree

  CTree * prev;  // pointer to parent if this is a first child, or left sibling otherwise
                 // this should always be null if the object is the root of a tree

 public:
  CTree(char ch); //constructor
  CTree(const CTree* fromTree); //extra credit: deep copy constructor
  ~CTree();  // clear siblings to right and children and this node
  
  // siblings and children must be unique, return true if added, false otherwise
  bool addChild(char ch);

  // add tree root for better building, root should have null prev and sibs 
  // returns false on any type of failure, including invalid root
  bool addChild(CTree *root);

  std::string toString(); // all characters, separated by newlines, including at the end

  //extra credit: removeChild function
  bool removeChild(char ch);

 private:
  // these should only be called from addChild, and have the same restrictions
  // the root of a tree should never have any siblings
  // returns false on any type of failure, including invalid root
  bool addSibling(char ch);
  bool addSibling(CTree *root);

} ;

#endif
