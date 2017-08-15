/*
Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/14/2015
443-691-8192
*/

#include "CTree.h"
#include <string>
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

class CTreeTest {
public:
/* toString and destructor tested throughout (run valgrind to test
 * destructor): "A toString() function that creates and returns a
 * string of all the elements in the nodes of the tree, separated by
 * newline characters. The ordering of the nodes must be determined by
 *
 * a depth-first pre-order traversal from the root node" "A destructor
 * that clears all the children of the current node and all the
 * siblings to the right of the current node, freeing that dynamically
 * allocated memory. (Hint: use recursion!)"
 */


/* Constructor:
 * "A constructor that is passed the character to store in the root
 * node of a new tree. 
 */
    static void constructorTest() {
        // build a few trees with constructor
        CTree t1('A');
        assert(t1.toString() == "A\n");
        CTree t2('b');
        assert(t2.toString() == "b\n");
        CTree t3('^');
        assert(t3.toString() == "^\n");
    }


/* Test adding children and siblings:
 * "An 'addChild' function, which is passed the character data to be
 * stored in the child. This function returns false if it fails
 * (because the data is already a child of this tree node) and true if
 * it succeeds. Remember that it must keep the children ordered."
 *
 * "An 'addSibling' function, which is passed the data to be stored in
 * a new sibling node. This function returns false if it fails
 * (because the data is already a sibling t * o the right of this tree
 * node) and true if it succeeds. Remember that siblings must always
 * be ordered (the hard part of the function, worth 5 points). (This
 * function is really just a helper function for addChild, but keeping
 * it public will let us test it easily.)"
 */
    static void addsTest() {
        // A
        CTree* t1Ptr = new CTree('A');
        CTree& t1 = *t1Ptr; // avoids a bunch of *'s below
        assert(t1.toString() == "A\n");

        // A
        // |
        // b
        assert(t1.addChild('b'));
        assert(t1.toString() == "A\nb\n");
        // can't add again
        assert(!t1.addChild('b'));
        assert(t1.toString() == "A\nb\n");

        // A
        // |
        // b - c
        assert(t1.addChild('c'));
        assert(t1.toString() == "A\nb\nc\n");
        // can't add again
        assert(!t1.addChild('c'));
        assert(t1.toString() == "A\nb\nc\n");

        // A
        // |
        // B - b - c
        assert(t1.addChild('B'));
        // 'B' comes before 'b'
        assert(t1.toString() == "A\nB\nb\nc\n");
        // can't add repeats
        assert(!t1.addChild('B'));
        assert(!t1.addChild('b'));
        assert(!t1.addChild('c'));
        assert(t1.toString() == "A\nB\nb\nc\n");

    
        // can't add 'A' as sibling of 'A'
        assert(!t1.addSibling('A'));
        assert(t1.toString() == "A\nB\nb\nc\n");

        // make sure that we can't add siblings to the root
        assert(!t1.addSibling('C'));
        assert(t1.toString() == "A\nB\nb\nc\n");

        // Adding in an already built subTree
        // First build another tree
        // R
        CTree* t2Ptr = new CTree('R');
        CTree& t2 = *t2Ptr;
        assert(t2.toString() == "R\n");
        
        // R
        // |
        // C
        assert(t2.addChild('C'));
        assert(t2.toString() == "R\nC\n");


        // R
        // |
        // C - d
        assert(t2.addChild('d'));
        assert(t2.toString() == "R\nC\nd\n");
        // can't repeat
        assert(!t2.addChild('d'));
        assert(t2.toString() == "R\nC\nd\n");

        // R
        // |
        // B - C - d
        assert(t2.addChild('B'));
        assert(t2.toString() == "R\nB\nC\nd\n");
        // can't repeat
        assert(!t2.addChild('B'));
        assert(t2.toString() == "R\nB\nC\nd\n");

        // Add t1 in as a child
        // R
        // |
        // A - B - C - d
        // |
        // B - b - c

        // t1 is as before
        assert(t1.toString() == "A\nB\nb\nc\n");
        // add t1 to t2
        assert(t2.addChild(&t1));
        // t1 should now have siblings
        assert(t1.toString() == "A\nB\nb\nc\nB\nC\nd\n");
        // t2 should be updated
        assert(t2.toString() == "R\nA\nB\nb\nc\nB\nC\nd\n");



        // R
        // |
        // @ - A - B - C - d
        //     |
        //     B - b - c
        assert(t2.addChild('@'));
        assert(t2.toString() == "R\n@\nA\nB\nb\nc\nB\nC\nd\n");
        // shouldn't be able to add duplicate children
        assert(!t2.addChild('@'));
        assert(!t2.addChild('A'));
        assert(!t2.addChild('B'));
        assert(!t2.addChild('C'));
        assert(!t2.addChild('d'));

        // R
        // |
        // @ - A - B - C - D - d
        //     |
        //     B - b - c
        assert(t2.addChild('D'));
        assert(t2.toString() == "R\n@\nA\nB\nb\nc\nB\nC\nD\nd\n");

        // R
        // |
        // @ - A - B - C - D - d - e
        //     |
        //     B - b - c
        assert(t2.addChild('e'));
        assert(t2.toString() == "R\n@\nA\nB\nb\nc\nB\nC\nD\nd\ne\n");

        delete t2Ptr;
        
    }

    // adds a single child
    static void addSimpleChildTest() {
        // A
        CTree* t1 = new CTree('A');
        assert(t1->toString() == "A\n");

        // A
        CTree* t2 = new CTree('A');
        assert(t2->toString() == "A\n");

        // A
        // |
        // A
        assert(t2->addChild(t1));
        assert(t2->toString() == "A\nA\n");

        delete t2;
    }

  static void copyConstructorTest()
  {
    // A
    CTree* t1Ptr = new CTree('A');
    CTree& t1 = *t1Ptr; // avoids a bunch of *'s below
    assert(t1.toString() == "A\n");

    // A
    // |
    // b
    assert(t1.addChild('b'));
    assert(t1.toString() == "A\nb\n");
    // can't add again
    assert(!t1.addChild('b'));
    assert(t1.toString() == "A\nb\n");

    // A
    // |
    // b - c
    assert(t1.addChild('c'));
    assert(t1.toString() == "A\nb\nc\n");
    // can't add again
    assert(!t1.addChild('c'));
    assert(t1.toString() == "A\nb\nc\n");

    // A
    // |
    // B - b - c
    //     |
    //     D
    assert(t1.addChild('B'));
    // 'B' comes before 'b'
    assert(t1.toString() == "A\nB\nb\nc\n");
    t1.kids->sibs->addChild('D');
    //use copy constructor
    CTree* copiedTree = new CTree(t1Ptr);

    //check new tree
    assert(copiedTree->toString() == "A\nB\nb\nD\nc\n");

    //clean up
    delete copiedTree;
    delete t1Ptr;
  }

  static void removeNodeTest()
  {
    // A
    CTree* t1Ptr = new CTree('A');
    CTree& t1 = *t1Ptr; // avoids a bunch of *'s below
    assert(t1.toString() == "A\n");

    // A
    // |
    // b
    assert(t1.addChild('b'));
    assert(t1.toString() == "A\nb\n");
    // can't add again
    assert(!t1.addChild('b'));
    assert(t1.toString() == "A\nb\n");

    // A
    // |
    // b - c
    assert(t1.addChild('c'));
    assert(t1.toString() == "A\nb\nc\n");
    // can't add again
    assert(!t1.addChild('c'));
    assert(t1.toString() == "A\nb\nc\n");

    // A
    // |
    // B - b - c
    assert(t1.addChild('B'));
    // 'B' comes before 'b'
    assert(t1.toString() == "A\nB\nb\nc\n");
    // can't add repeats
    assert(!t1.addChild('B'));
    assert(!t1.addChild('b'));
    assert(!t1.addChild('c'));
    assert(t1.toString() == "A\nB\nb\nc\n");

    
    // can't add 'A' as sibling of 'A'
    assert(!t1.addSibling('A'));
    assert(t1.toString() == "A\nB\nb\nc\n");

    // make sure that we can't add siblings to the root
    assert(!t1.addSibling('C'));
    assert(t1.toString() == "A\nB\nb\nc\n");

    // Adding in an already built subTree
    // First build another tree
    // R
    CTree* t2Ptr = new CTree('R');
    CTree& t2 = *t2Ptr;
    assert(t2.toString() == "R\n");
        
    // R
    // |
    // C
    assert(t2.addChild('C'));
    assert(t2.toString() == "R\nC\n");


    // R
    // |
    // C - d
    assert(t2.addChild('d'));
    assert(t2.toString() == "R\nC\nd\n");
    // can't repeat
    assert(!t2.addChild('d'));
    assert(t2.toString() == "R\nC\nd\n");

    // R
    // |
    // B - C - d
    assert(t2.addChild('B'));
    assert(t2.toString() == "R\nB\nC\nd\n");
    // can't repeat
    assert(!t2.addChild('B'));
    assert(t2.toString() == "R\nB\nC\nd\n");

    // Add t1 in as a child
    // R
    // |
    // A - B - C - d
    // |
    // B - b - c

    // t1 is as before
    assert(t1.toString() == "A\nB\nb\nc\n");
    // add t1 to t2
    assert(t2.addChild(&t1));
    // t1 should now have siblings
    assert(t1.toString() == "A\nB\nb\nc\nB\nC\nd\n");
    // t2 should be updated
    assert(t2.toString() == "R\nA\nB\nb\nc\nB\nC\nd\n");



    // R
    // |
    // @ - A - B - C - d
    //     |
    //     B - b - c
    assert(t2.addChild('@'));
    assert(t2.toString() == "R\n@\nA\nB\nb\nc\nB\nC\nd\n");
    // shouldn't be able to add duplicate children
    assert(!t2.addChild('@'));
    assert(!t2.addChild('A'));
    assert(!t2.addChild('B'));
    assert(!t2.addChild('C'));
    assert(!t2.addChild('d'));

    // R
    // |
    // @ - A - B - C - D - d
    //     |
    //     B - b - c
    assert(t2.addChild('D'));
    assert(t2.toString() == "R\n@\nA\nB\nb\nc\nB\nC\nD\nd\n");

    // R
    // |
    // @ - A - B - C - D - d - e
    //     |
    //     B - b - c
    assert(t2.addChild('e'));
    assert(t2.toString() == "R\n@\nA\nB\nb\nc\nB\nC\nD\nd\ne\n");

    //call removeChild function
    t2.removeChild('A');

    //check if it worked
    assert(t2.toString() == "R\n@\nB\nC\nD\nd\ne\n");

    //keep removing and testing
    t2.removeChild('Z'); //should do nothing
    assert(t2.toString() == "R\n@\nB\nC\nD\nd\ne\n");
    t2.removeChild('@');
    assert(t2.toString() == "R\nB\nC\nD\nd\ne\n");
    t2.removeChild('e');
    assert(t2.toString() == "R\nB\nC\nD\nd\n");
    t2.removeChild('D');
    t2.removeChild('C');
    t2.removeChild('d');
    assert(t2.toString() == "R\nB\n");
    t2.removeChild('B');
    assert(t2.toString() == "R\n");
    
    //clean up
    delete t2Ptr;
  }
  
};



int main(void) {
    cout << "Testing CTree" << endl;
    CTreeTest::constructorTest();
    CTreeTest::addsTest();
    CTreeTest::addSimpleChildTest();
    CTreeTest::removeNodeTest();
    CTreeTest::copyConstructorTest();
    cout << "CTree tests passed" << endl;
}
