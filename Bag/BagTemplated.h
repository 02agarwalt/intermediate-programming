//
//  BagTemplated.h
//
//  Created by Scott Smith on 10/27/14.
//  Copyright (c) 2014 Scott Smith. All rights reserved.
//

#ifndef __Cpp_oneliner__Bag__
#define __Cpp_oneliner__Bag__

#include <cassert>
#include <iostream>

template <class T>
class Bag {
private:
    int size;
    static int capacity; 
    T *data;
    
public:
    Bag();
    Bag(const Bag<T> &);
    ~Bag();
    bool    add(T elt);
    bool    lookup(T elt);
    bool    remove(T elt);
    static   bool changeCap(int elt);
};


template <class T>
int Bag<T>::capacity = 10;

template <class T>
Bag<T>::Bag()
{ size = 0;
    data = new T [capacity];
}

template <class T>
Bag<T>::Bag(const Bag<T> &b)
{ std::cout<< "copying" <<std::endl;
    size = b.size;
    data = new T [capacity];
    for (int i = 1;i<size;i++)
        data[i]=b.data[i];
}

template <class T>
Bag<T>::~Bag()
{ std::cout << "destroying; size " << size << std::endl;
    size = 0;
    delete [] data;
}

template <class T>
bool Bag<T>::add(T elt)
{
    if (size==capacity) return false;
    data[size++] = elt;
    return true;
}

template <class T>
bool Bag<T>::remove(T elt)
{
    for(int i = 0; i<size;i++)
        if (data[i] == elt)
        {
            data[i] = data[--size];
            return true;
        }
    return false;
}

template <class T>
bool Bag<T>::lookup(T elt)
{
    for(int i = 0; i<size;i++)
        if (data[i] == elt) return true;
    return false;
}

template <class T>
bool Bag<T>::changeCap(int newcap)
{   capacity = newcap;
    return true;
}


#endif /* defined(__Cpp_oneliner__Bag__) */
