#include "Bag.h"
#include <iostream>
#include <iomanip>

using std::ostream;
using std::istream;
using std::ios;
using std::setw;
using std::setfill;
using std::cerr;
using std::endl;

int Bag::CAPLIMIT = 100;

Bag::Bag():size(0), capacity(CAPLIMIT)
{
    intbag = new int[capacity];
}

Bag::Bag(int cap):size(0), capacity(cap)
{
    if (capacity > CAPLIMIT)
	capacity = CAPLIMIT;
    cerr << "changing capacity to limit: " << CAPLIMIT << endl;
    intbag = new int[capacity];
}

  // copy constructor - DEEP copy
Bag::Bag(const Bag & frombag)
{
    size = frombag.size;
    capacity = frombag.capacity;
    intbag = new int[capacity];
    for (int i = 0; i < size; i++)	// makes it deep copy
	intbag[i] = frombag.intbag[i];
}

// destructor
Bag::~Bag()
{
    delete[]intbag;		// release memory!!
}

void Bag::clear() 
{
  delete [] intbag;
  intbag = new int[capacity];
  size = 0;
}

bool Bag::add(int n)
{
    if (size == capacity)	// bag is full
	return false;

    intbag[size++] = n;
    return true;
}

int Bag::where(int n) const
{
    for (int i = 0; i < size; i++)
	if (intbag[i] == n)
	    return i;
    return -1;
}

bool Bag::find(int n) const
{
    return where(n) != -1;
}

bool Bag::remove(int n)
{
    int w = where(n);
    if (w == -1)
	return false;
    intbag[w] = intbag[--size];
    return true;
}

ostream & Bag::write(ostream & os) const
{
    char oldfill = os.fill('*');
    os << '{';
    os.setf(ios::fixed);
    os.setf(ios::showpoint);
    for (int i = 0; i < size - 1; i++)
	os << setw(5) << intbag[i] << ", ";
    os << setfill('0') << setw(5) << intbag[size - 1] << '}';
    os.fill(oldfill);		// need to reset to default
    os.unsetf(ios::fixed);
    os.unsetf(ios::showpoint);
    return os;
}

istream & Bag::read(istream & is)
{
    int value;
    while (is >> value && !isFull()) {
	add(value);
    }
    return is;
}

int Bag::CapLimit(int limit)
{
    int temp = CAPLIMIT;
    CAPLIMIT = limit;
    return temp;
}

// affiliated non-member operators

ostream & operator<<(ostream & os, const Bag & b)
{
    return b.write(os);
}

istream & operator>>(istream & is, Bag & b)
{
    return b.read(is);
}
