#ifndef _BAG_H
#define _BAG_H

#include <iostream>
using std::ostream;  using std::istream;


class Bag {

// class members private by default

  int size; // actual number of elements
  int capacity;  // how many it can hold
  int *intbag;

  static int CAPLIMIT;  // shared by all Bag objects

 public:
  Bag();  // default constructor
  Bag(int);   // conversion constructor
  Bag(const Bag &);  // copy constructor - DEEP copy
  ~Bag();   // destructor!!

  // accessors - do not modify object
  // const applies to object calling function

  // inline definitions
  int getSize() const { return size; } ;  
  bool isEmpty() const { return size == 0; } ;
  bool isFull() const { return size == capacity; } ;
  int cap() const { return capacity; } ;

  // definitions in implementation file
  bool find(int) const;
  ostream & write(ostream &) const;

  // modifiers (mutators)
  bool add(int);
  bool remove(int);
  void clear();   // dump the contents
  istream & read(istream &);

  static int CapLimit(int);   // change static variable

  // helpers
 private:
  int where(int) const;

} ;  // must have semicolon

#endif
