/*
Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/10/2015
443-691-8192
*/

#include "FileDir.h"
#include <iomanip>

FileDir::FileDir(string inputName, long inputSize, bool inputIsDirectory)
{
  name = inputName;
  size = inputSize;
  isDirectory = inputIsDirectory;
}

FileDir::FileDir(const FileDir & input)
{
  name = input.name;
  size = input.size;
  isDirectory = input.isDirectory;
}

long FileDir::getSize() const
{
  return size;
}

string FileDir::getName() const
{
  return name;
}

bool FileDir::isFile() const
{
  return !isDirectory;
}

string FileDir::rename(string newName)
{
  string formerName = name;
  name = newName;
  return formerName;
}

long FileDir::resize(long addSize)
{
  if ((size + addSize) >= 0)
    size = size + addSize;

  return size;
}

string FileDir::toString()
{
  std::ostringstream oss;
  if (isDirectory)
    {
      oss << name << "/ [" << size << "kb]";
    }
  else
    {
      oss << name << " [" << size << "kb]";
    }
  
  return oss.str();
}
