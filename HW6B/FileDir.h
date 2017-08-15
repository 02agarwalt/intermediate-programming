/*
Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/10/2015
443-691-8192
*/

#ifndef _FILEDIR_H
#define _FILEDIR_H

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <cstddef>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>

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
  
  string toString();
};

#endif
