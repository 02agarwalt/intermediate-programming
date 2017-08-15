/*
Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/14/2015
443-691-8192
*/

#include "FileDir.h"

using std::endl;
using std::cout;
using std::istringstream;
using std::ostringstream;


// Tests constructors and accessors:
//
// - A constructor which is passed a string name, a long size and a
// boolean value which is true if the item is a directory and false if
// it's a file. Include default parameter values of 4 for the size and
// false for boolean.
//
// - A copy constructor.
//
// - Functions that return the size and the name of the item, long
// getSize() and string getName() respectively.
//
// - A function called "isFile" that returns true if the object is a
// file, and false if it is a directory.

void basicsTest() {
    // basic use of constructor
    FileDir d1("testDir", 4, false);
    assert(d1.getName() == "testDir");
    assert(d1.getSize() == 4);
    assert(d1.isFile());

    // do defaults work as expected?
    FileDir d2("testDir");
    assert(d2.getName() == "testDir");
    assert(d2.getSize() == 4);
    assert(d2.isFile());

    // equality check
    assert(d1 == d2);

    // try with a big num and a directory
    long bigNum = 2 << 18;
    bool isDir = true;
    FileDir d3("testDir", bigNum, isDir);
    assert(d3.getName() == "testDir");
    assert(d3.getSize() == bigNum);
    assert(!d3.isFile());

    // same name but still shouldn't be equal
    //assert(!(d3 == d2));

    // make sure that copy constructor works
    FileDir d4 = d2;
    //assert(d4 == d2);
    FileDir d5 = d3;
    //assert(d5 == d3);

    // test with a different name
    FileDir d6("differentname");
    assert(d6.getName() == "differentname");
    assert(d6.getSize() == 4);
    assert(d6.isFile());
    //assert(!(d6 == d2));
    
    // we don't expect special handling of white space and punctuation
    // in name, right?
    string messyName = "29872 &*(2 messy name !/\n\n\n/\n//";
    FileDir d7(messyName);
    assert(d7.getName() == messyName);

}

// Tests mutators (rename and resize)
//
// - A mutator called "rename" that is passed a string to use in order
// to rename the item. This function should return the former name.
// 
// - A mutator called "resize" that updates the item size according to a
// number passed as a parameter. If the parameter is >0, it's value
// should be added to the current size. If it is negative, it should
// be subtracted from the size, but only if the result will be >=
// 0. Make no changes if the parameter is invalid. In either case
// return the (new) current size.

void mutatorsTest() {
    // basic use of constructor
    FileDir d1("testDir", 5);
    assert(d1.getName() == "testDir");
    assert(d1.getSize() == 5);
    assert(d1.isFile());

    assert(d1.rename("differentName") == "testDir");
    assert(d1.getName() == "differentName");
    assert(d1.getSize() == 5);
    assert(d1.isFile());

    // empty name
    assert(d1.rename("") == "differentName");
    assert(d1.getName() == "");

    // subtract to exactly 0
    assert(d1.resize(-5) == 0);
    assert(d1.getSize() == 0);

    // add from 0
    assert(d1.resize(10) == 10);
    assert(d1.getSize() == 10);

    // add 0
    assert(d1.resize(0) == 10);
    assert(d1.getSize() == 10);

    // add from positive number
    assert(d1.resize(5) == 15);
    assert(d1.getSize() == 15);

    // subtract not to zero
    assert(d1.resize(-4) == 11);
    assert(d1.getSize() == 11);

    // try to subtract "past" 0
    assert(d1.resize(-12) == 11);
    assert(d1.getSize() == 11);

    // subtract to 0
    assert(d1.resize(-11) == 0);
    assert(d1.getSize() == 0);

    // try to subtract from 0
    assert(d1.resize(-10000) == 0);
    assert(d1.getSize() == 0);

}

void toStringTest() {
    // regular file
    FileDir d("testFile", 50, false);
    //cout << d.toString() << endl;
    assert(d.toString() == "testFile [50kb]");

    // directory
    FileDir d2("testDir", 51, true);
    assert(d2.toString() == "testDir/ [51kb]");

}

int main(void) {
    cout << "Running FileDir tests..." << endl;
    basicsTest();
    mutatorsTest();
    //    readTest();    // not required
    //    writeTest();   // not required
    toStringTest();
    cout << "FileDir tests passed." << endl;

}
