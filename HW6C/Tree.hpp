/*
  Homework 6, 600.120 Spring 2015

  Tanay Agarwal
  tagarwa2@jhu.edu
  tagarwa2
  04/14/2015
  443-691-8192
*/

#ifndef __Cpp_oneliner__Tree__
#define __Cpp_oneliner__Tree__

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <cstddef>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>

using std::ostream;
using std::istream;
using std::string;
using std::cout;
using std::endl;

//class definition
template <class T>
class CTree {
private:
  
  template <class U> friend void constructorTest(U a, U b, U c);
  template <class U> friend void addsTest(U A, U b, U c, U B, U R, U C, U d, U at);
  template <class U> friend void addSimpleChildTest(U a, U b);

  T data; //value stored in node
  CTree<T> * kids; //pointer to first child
  CTree<T> * sibs; //pointer to first sibling (towards the right)
  CTree<T> * prev; //pointer to previous node (either sibling or parent)
  
public:
  CTree(T ch); //constructor
  ~CTree(); //destructor
  
  bool addChild(T ch); //add child using data
  bool addChild(CTree<T> * root); //add child using existing node
  string toString(); //return all data, in order
  
private:
  bool addSibling(T ch); //add sibling using data
  bool addSibling(CTree<T> * root); //add sibling using existing node
};

//function implementations:

template <class T>
CTree<T>::CTree(T ch):data(ch)
{
  this->kids = NULL;
  this->sibs = NULL;
  this->prev = NULL;
}

template <class T>
CTree<T>::~CTree()
{
  if(this->sibs != NULL)
    delete this->sibs; //recurse

  if(this->kids != NULL)
    delete this->kids;
}

template <class T>
string CTree<T>::toString()
{
  std::ostringstream oss;
  
  oss << this->data << "\n"; //process data in current "this"
  
  if(this->kids != NULL)
    {
      oss << (this->kids)->toString(); //recurse over kids
    }
  if(this->sibs != NULL)
    {
      oss << (this->sibs)->toString(); //recurse over siblings
    }
  
  return oss.str();
}

template <class T>
bool CTree<T>::addSibling(CTree<T>* root)
{
  //check for invalid root or "this"
  if(root == NULL || root->prev != NULL || root->sibs != NULL || this->prev == NULL)
    return false;

  //see if data already exists in current tree
  CTree<T>* iterator = this;
  while(iterator != NULL && iterator->data != root->data)
    iterator = iterator->sibs;

  if(iterator != NULL)
    {
      return false;
    }

  //find where to insert sibling
  iterator = this;
  while(iterator != NULL && iterator->data < root->data)
    iterator = iterator->sibs;
  
  //to insert at end of sibling list
  if(iterator == NULL)
    {
      //reset iterator and go to end of sibling list
      iterator = this;
      while(iterator->sibs != NULL)
	iterator = iterator->sibs;
      
      //add after last sibling
      root->sibs = NULL;
      root->prev = iterator;
      iterator->sibs = root;
    }
  else if(iterator->prev == this->prev) //to insert at beginning of sibling list
    {
      root->sibs = this;
      root->prev = this->prev;
      this->prev = root;
      root->prev->kids = root;
    }
  else //to insert at middle of sibling list
    {
      root->sibs = iterator;
      root->prev = iterator->prev;
      root->prev->sibs = root;
      iterator->prev = root;
    }

  return true;
}

//insert sibling using data
template <class T>
bool CTree<T>::addSibling(T ch)
{
  //create node with given data, then call addSibling(CTree<T>* root)
  CTree<T>* newNodeP = new CTree(ch);

  bool success = addSibling(newNodeP);
  
  if(!success)
    delete newNodeP;

  return success;
}

//adds child to current node (using addSibling() function)
template <class T>
bool CTree<T>::addChild(CTree<T>* root)
{
  //check if root is valid
  if(root == NULL || root->prev != NULL || root->sibs != NULL)
    return false;

  //to insert first child
  if(this->kids != NULL)
    return (this->kids)->addSibling(root);
  else //to insert new child
    {
      root->sibs = NULL;
      root->prev = this;
      this->kids = root;
      
      return true;
    }
}

//adds child using data
template <class T>
bool CTree<T>::addChild(T ch)
{
  CTree<T>* newNodeP = new CTree(ch);

  bool success =  addChild(newNodeP);
  
  if(!success)
    delete newNodeP;

  return success;
}

#endif /* defined(__Cpp_oneliner__Tree__) */
