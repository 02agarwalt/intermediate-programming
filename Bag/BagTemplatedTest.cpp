//
//  BagTemplatedTest.cpp
//
//  Created by Scott Smith on 10/27/14.
//  Copyright (c) 2014 Scott Smith. All rights reserved.
//

#include <stdio.h>
#include <cassert>
#include "Bag.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    Bag<int> b1;
    b1.add(3);
    b1.add(4);
    assert(b1.lookup(3));
    assert(!(b1.lookup(88)));
    
    Bag<int>::changeCap(10);

    Bag<int> b2 = b1;
    b2.add(444);
    assert(!(b1.lookup(444)));
    assert((b2.lookup(444)));

    assert(b1.remove(4));
    assert(!b1.lookup(4));
  
    for (int i = 0;i<1000;i++) b1.add(3);
    assert(!(b1.add(44)));
  
    
    
    Bag<float> b3;
    b3.add(3.4);
    b3.add(4.3);
    assert(b3.lookup(3.4));
    assert(!(b3.lookup(88)));
    
    Bag<float>::changeCap(100);
    
    Bag<float> b4 = b3;
    b4.add(444);
    assert(!(b3.lookup(444)));
    assert((b4.lookup(444)));

}
