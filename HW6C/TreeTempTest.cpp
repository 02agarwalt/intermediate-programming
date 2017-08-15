/*
  Homework 6, 600.120 Spring 2015

  Tanay Agarwal
  tagarwa2@jhu.edu
  tagarwa2
  04/14/2015
  443-691-8192
*/

#include "Tree.hpp"
#include "FileDir.h"

using std::to_string;

template <class T>
void constructorTest(T a, T b, T c) {

  std::ostringstream oss;

  // build a few trees with constructor
  CTree<T> t1(a);
  oss << a << "\n";
  assert(t1.toString() == oss.str());

  CTree<T> t2(b);
  oss.str(""); oss << b << "\n";
  assert(t2.toString() == oss.str());

  CTree<T> t3(c);
  oss.str(""); oss << c << "\n";
  assert(t3.toString() == oss.str());
}

template <class T>
void addsTest(T A, T b, T c, T B, T R, T C, T d, T at) {
  std::ostringstream oss;
  
  // A
  CTree<T>* t1Ptr = new CTree<T>(A);
  CTree<T>& t1 = *t1Ptr; // avoids a bunch of *'s below
  oss << A << "\n";
  assert(t1.toString() == oss.str());
    
  // A
  // |
  // b
  assert(t1.addChild(b));
  oss << b << "\n";
  assert(t1.toString() == oss.str());
  // can't add again
  assert(!t1.addChild(b));
  assert(t1.toString() == oss.str());

  // A
  // |
  // b - c
  assert(t1.addChild(c));
  oss << c << "\n";

  assert(t1.toString() == oss.str());
  // can't add again
  assert(!t1.addChild(c));
  assert(t1.toString() == oss.str());

  // A
  // |
  // B - b - c
  assert(t1.addChild(B));
  // 'B' comes before 'b'
  oss.str(""); oss << A << "\n" << B << "\n" << b << "\n" << c << "\n";
  
  assert(t1.toString() == oss.str());
  // can't add repeats
  assert(!t1.addChild(B));
  assert(!t1.addChild(b));
  assert(!t1.addChild(c));
  assert(t1.toString() == oss.str());

    
  // can't add 'A' as sibling of 'A'
  assert(!t1.addSibling(A));
  assert(t1.toString() == oss.str());

  // make sure that we can't add siblings to the root
  assert(!t1.addSibling(C));
  assert(t1.toString() == oss.str());

  // Adding in an already built subTree
  // First build another tree
  // R
  std::ostringstream oss2;
  
  CTree<T>* t2Ptr = new CTree<T>(R);
  CTree<T>& t2 = *t2Ptr;
  oss2 << R << "\n";
  assert(t2.toString() == oss2.str());
        
  // R
  // |
  // C
  assert(t2.addChild(C));
  oss2 << C << "\n";
  assert(t2.toString() == oss2.str());


  // R
  // |
  // C - d
  assert(t2.addChild(d));
  oss2 << d << "\n";
  assert(t2.toString() == oss2.str());
  // can't repeat
  assert(!t2.addChild(d));
  assert(t2.toString() == oss2.str());

  // R
  // |
  // B - C - d
  assert(t2.addChild(B));
  oss2.str(""); oss2 << R << "\n" << B << "\n" << C << "\n" << d << "\n";
  assert(t2.toString() == oss2.str());
  // can't repeat
  assert(!t2.addChild(B));
  assert(t2.toString() == oss2.str());

  // Add t1 in as a child
  // R
  // |
  // A - B - C - d
  // |
  // B - b - c

  // t1 is as before
  assert(t1.toString() == oss.str());
  // add t1 to t2
  assert(t2.addChild(&t1));
  // t1 should now have siblings
  oss << B << "\n" << C << "\n" << d << "\n";
  assert(t1.toString() == oss.str());
  // t2 should be updated
  std::ostringstream oss3;
  oss3 << R << "\n" << oss.str();
  assert(t2.toString() == oss3.str());



  // R
  // |
  // @ - A - B - C - d
  //     |
  //     B - b - c
  assert(t2.addChild(at));
  oss3.str(""); oss3 << R << "\n" << at << "\n" << oss.str();
  assert(t2.toString() == oss3.str());
  // shouldn't be able to add duplicate children
  assert(!t2.addChild(at));
  assert(!t2.addChild(A));
  assert(!t2.addChild(B));
  assert(!t2.addChild(C));
  assert(!t2.addChild(d));

  delete t2Ptr;
        
}

// adds a single child
template <class T>
void addSimpleChildTest(T a, T b) {

  std::ostringstream oss;

  // a
  CTree<T>* t1 = new CTree<T>(a);
  oss << a << "\n";
  assert(t1->toString() == oss.str());

  // b
  CTree<T>* t2 = new CTree<T>(b);
  oss.str(""); oss << b << "\n";
  assert(t2->toString() == oss.str());

  // b
  // |
  // a
  assert(t2->addChild(t1));
  oss.str(""); oss << b << "\n" << a << "\n";
  assert(t2->toString() == oss.str());

  delete t2;
}

int main(void) {
  cout << "Testing CTree" << endl;

  //char test
  constructorTest('A', 'b', 'c');
  addSimpleChildTest('A', 'b');
  addsTest('A', 'b', 'c', 'B', 'R', 'C', 'd', '@');
 
  //int test
  constructorTest(1, 2, 3);
  addSimpleChildTest(1, 2);
  addsTest(65, 98, 99, 66, 82, 67, 100, 64);

  //double test
  constructorTest(1.01, 2.02, 3.03);
  addSimpleChildTest(1.01, 2.02);
  addsTest(65.1, 98.1, 99.1, 66.1, 82.1, 67.1, 100.1, 64.1);

  //string test
  constructorTest("hello", "bye", "hi");
  addSimpleChildTest("hello", "bye");
  string a = "AA";
  string b = "bb";
  string c = "cc";
  string d = "BB";
  string e = "RR";
  string f = "CC";
  string g = "dd";
  string h = "@@";
  addsTest(a, b, c, d, e, f, g, h);

  //FileDir test
  FileDir* ax = new FileDir("AA", 5, true);
  FileDir* bx = new FileDir("bb", 10, true);
  FileDir* cx = new FileDir("cc", 20, false);
  FileDir* dx = new FileDir("BB", 50, true);
  FileDir* ex = new FileDir("RR", 10, false);
  FileDir* fx = new FileDir("CC", 12, false);
  FileDir* gx = new FileDir("dd", 50, false);
  FileDir* hx = new FileDir("@@", 99, true);

  constructorTest(*ax, *bx, *cx);
  addSimpleChildTest(*ax, *bx);
  addsTest(*ax, *bx, *cx, *dx, *ex, *fx, *gx, *hx);

  cout << "CTree tests passed" << endl;

  delete ax; delete bx; delete cx; delete dx;
  delete ex; delete fx; delete gx; delete hx;
}
