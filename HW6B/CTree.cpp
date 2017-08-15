/*
Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/10/2015
443-691-8192
*/

#include "CTree.h"
#include <iomanip>

//constructor
CTree::CTree(char ch)
{
  this->data = ch;
  this->kids = NULL;
  this->sibs = NULL;
  this->prev = NULL;
}

//deep copy constructor
CTree::CTree(const CTree* fromTree)
{
  //create node
  this->data = fromTree->data;
  this->kids = NULL;
  this->sibs = NULL;
  this->prev = NULL;
  
  if(fromTree->kids != NULL) //recurse over kids
    {
      CTree* newNodeP = new CTree(fromTree->kids);

      //link children one by one
      this->kids = newNodeP;
      newNodeP->prev = this;
    }
  if(fromTree->sibs != NULL) //recurse over siblings
    {      
      CTree* newNodeP = new CTree(fromTree->sibs);

      //link siblings one by one
      this->sibs = newNodeP;
      newNodeP->prev = this;
    }
}

//destructor
CTree::~CTree()
{
  if(this->sibs != NULL)
    delete this->sibs; //recurse

  if(this->kids != NULL)
    delete this->kids;
}

//returns all data in tree
string CTree::toString()
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

//add sibling using existing root
bool CTree::addSibling(CTree* root)
{
  //check for invalid root or "this"
  if(root == NULL || root->prev != NULL || root->sibs != NULL || this->prev == NULL)
    return false;

  //see if data already exists in current tree
  CTree* iterator = this;
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

//insert sibling using character
bool CTree::addSibling(char ch)
{
  //create node with given character, then call addSibling(CTree* root)
  CTree* newNodeP = new CTree(ch);

  bool success = addSibling(newNodeP);
  
  if(!success)
    delete newNodeP;

  return success;
}

//adds child to current node (using addSibling() function)
bool CTree::addChild(CTree* root)
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

//adds child using character
bool CTree::addChild(char ch)
{
  CTree* newNodeP = new CTree(ch);

  bool success =  addChild(newNodeP);
  
  if(!success)
    delete newNodeP;

  return success;
}

//extra credit function: removes child from given node
bool CTree::removeChild(char ch)
{
  //check if data exists in tree
  CTree* iterator = this->kids;
  while(iterator != NULL && iterator->data != ch)
    iterator = iterator->sibs;

  if(iterator == NULL)
    {
      return false;
    }

  //if data exists, make new iterator to node behind the one to be removed
  CTree* newIterator = iterator->prev;
  
  //to remove first child
  if(iterator->prev == this)
    {
      if(iterator->sibs == NULL) //if child is last in list
	{
	  newIterator->kids = iterator->sibs;
	  iterator->prev = NULL;
	  delete iterator;
	}
      else //if child is not last in list
	{
	  newIterator->kids = iterator->sibs;
	  newIterator->kids->prev = this;
	  iterator->sibs = NULL;
	  iterator->prev = NULL;
	  delete iterator;
	}
    }
  else //to remove non-first child
    {
      if(iterator->sibs == NULL) //if child is last in list
	{
	  newIterator->sibs = iterator->sibs;
	  iterator->prev = NULL;
	  delete iterator;
	}
      else //if child is not last in list
	{
	  newIterator->sibs = iterator->sibs;
	  newIterator->sibs->prev = newIterator;
	  iterator->prev = NULL;
	  iterator->sibs = NULL;
	  delete iterator;
	}
    }
  
  return true;
}
