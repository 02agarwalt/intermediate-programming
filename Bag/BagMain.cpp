#include "Bag.h"
#include <iostream>
#include <fstream>
using namespace std;

void initBAD(Bag, int);
void initGOOD(Bag &, int);

int main(void)
{
  Bag b1;      // calls default constructor
  b1.add(10);
  b1.add(20);
  b1.add(3);
  //  int old = (Bag:: CapLimit(150));
  Bag b2(100);  // calls conversion constructor
  Bag b3(b1);    // call copy constructor
  b3.remove(20);
  b3.write(cout) << endl;
  //  Bag:: CapLimit(old);

  initBAD(10, -23);   // uses conversion constructor 1st param

  //  initGOOD(10, -23);   // can't pass constant to ref param

  Bag b4(10);
  initGOOD(b4, -23);
  cout << "b4: ";
  b4.write(cout) << endl;

  Bag b5(5);
  cout << "enter bag elements, ^D to end: " << endl;
  b5.read(cin);
  b5.write(cout);

  ifstream infile("bag6.txt", ios::in);
  ofstream outfile("bag6.out", ios::app);
  Bag b6;
  b6.read(infile);
  b6.add(20);
  b6.add(20);
  b6.write(outfile) << endl;
}

void initBAD(Bag b, int value)
{
  for (int i=0; i < b.cap(); i++)
	b.add(value);
}

void initGOOD(Bag & b, int value)
{
  b.clear();
  for (int i=0; i < b.cap(); i++)
	b.add(value);
}
