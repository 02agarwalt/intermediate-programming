/*
Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/14/2015
443-691-8192
*/

#ifndef _FILEDIR_H
#define _FILEDIR_H

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <cstddef>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <utility>
#include <algorithm>

using std::ostream;  using std::istream;  using std::string;

class FileDir {

  string name;
  long size;
  bool isDirectory;

 public:
  FileDir(string inputName, long inputSize = 4, bool inputIsDirectory = false); // constructor
  FileDir(const FileDir &);  // copy constructor - DEEP copy

  // accessors
  long getSize() const;  
  string getName() const;
  bool isFile() const;

  // modifiers (mutators)
  string rename(string newName);
  long resize(long addSize);
  
  string toString() const;

  bool operator==(const FileDir & rhs) const;
  bool operator!=(const FileDir & rhs) const;
  bool operator<(const FileDir & rhs) const;
  friend ostream & operator<<(ostream & output, const FileDir & rhs);
};

#endif
