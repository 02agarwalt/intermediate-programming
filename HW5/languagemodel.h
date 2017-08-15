/*
Homework 5, 600.120 Spring 2015

Tanay Agarwal and Nirmal Krishnan
tagarwa2@jhu.edu
nkrishn9@jhu.edu
tagarwa2
nkrishn9
03/25/2015
443-691-8192 - Tanay
330-840-0368 - Nirmal
*/

#ifndef _LANGUAGEMODEL_H_
#define _LANGUAGEMODEL_H_

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <cstddef>
#include <string>
#include <cstdlib>
#include <cassert>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

typedef struct
{
  std::unordered_map<std::string, int> pairCountMap;
  std::unordered_map<std::string, int> pairStartCountMap;
  std::unordered_map<std::string, std::list<std::string>> pairFollowMap;
} LanguageModel;

void inputVector(std::vector<std::string> & toLoad); //load words from stdin into vector of strings
void loadLanguageModel(const std::vector<std::string> * loadedVect, LanguageModel *toLoad); //load model data
std::string getWord(std::string currWord, const LanguageModel  *model); //return next word based on probabilities
void outputVector(const LanguageModel *loadedModel, std::vector<std::string> & toCreate); //create vector of strings to be outputted
void printVector(const std::vector<std::string> *toPrint); //print vector of strings

#endif // _LANGUAGEMODEL_H_
