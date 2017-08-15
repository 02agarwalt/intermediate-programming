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

#include "languagemodel.h"

using namespace std;

void inputVector(vector<string> & toLoad)
{
  string word;

  toLoad.push_back("<START>");
  while(cin >> word)
    {
      toLoad.push_back(word);
    }
  toLoad.push_back("<END>");
}

void loadLanguageModel(const vector<string> *loadedVect, LanguageModel *toLoad)
{
  //fill pairCountMap
  vector<string>::const_iterator wordCount = (*loadedVect).begin();
  for (; wordCount != (*loadedVect).end() - 1; wordCount++)
    {
      string together = *wordCount + " " + *(wordCount + 1);
      
      unordered_map<string, int>::iterator tempIt = toLoad->pairCountMap.find(together);

      if(tempIt != toLoad->pairCountMap.end())
	{
	  (tempIt->second)++;
	}
      else
	{
	  pair<string, int> toInsert (together, 1);
	  toLoad->pairCountMap.insert(toInsert);
	}
    }

  //fill pairStartCountMap
  vector<string>::const_iterator wordPos = (*loadedVect).begin();

  for(; wordPos != loadedVect->end(); wordPos++)
    {
      int wordFreq = 0;
      
      for(vector<string>::const_iterator wordCheck = (*loadedVect).begin(); wordCheck != loadedVect->end(); wordCheck++)
	{
	  if((*wordCheck) == (*wordPos))
	    {
	      wordFreq++;
	    }
	}

      unordered_map<string, int>::iterator tempIt2 = toLoad->pairStartCountMap.find(*wordPos);
      
      if(tempIt2 == toLoad->pairStartCountMap.end())
	{
	  pair<string, int> toInsert2 (*wordPos, wordFreq);
	  toLoad->pairStartCountMap.insert(toInsert2);
	}
    }

  //fill pairFollowMap
  wordPos = (*loadedVect).begin();

  for(; wordPos != loadedVect->end() - 1; wordPos++)
    {
      for(vector<string>::const_iterator wordCheck = (*loadedVect).begin(); wordCheck != loadedVect->end() - 1; wordCheck++)
	{
	  if((*wordCheck) == (*wordPos))
	    {
	      string wordFollow = *(wordCheck + 1);
	      unordered_map<string, list<string>>::iterator tempIt3 = toLoad->pairFollowMap.find(*wordPos);
	      if(tempIt3 != toLoad->pairFollowMap.end())
		{
		  bool exists = (find((tempIt3->second).begin(), (tempIt3->second).end(), wordFollow) != (tempIt3->second).end());
		  
		  if (!exists)
		    {
		      (tempIt3->second).push_back(wordFollow);
		    }
		}
	      else
		{
		  list<string> toAdd (1, wordFollow);
		  pair<string, list<string>> toInsert3 (*wordPos, toAdd);
		  toLoad->pairFollowMap.insert(toInsert3);
		}
	    }
	}
    }
}

string getWord(string currWord, const LanguageModel *model)
{
  unordered_map<string, list<string>>::const_iterator tempIt = model->pairFollowMap.find(currWord);
  int totalOccur = model->pairStartCountMap.at(currWord);
  int randNum = (rand() % totalOccur) + 1;
  int sum = 0;
  list<string>::const_iterator listIt = (tempIt->second).begin();

  while(listIt != (tempIt->second).end() && sum < randNum)
    {
      string together = currWord + " " + *listIt;
      int currOccur = model->pairCountMap.at(together);
      sum = sum + currOccur;
      
      if(sum >= randNum)
	return *listIt;
      else
	listIt++;
    }
  
  return "nirmal";
}

void outputVector(const LanguageModel *loadedModel, vector<string> & toCreate)
{
  string currWord = "<START>";
  
  while((currWord = getWord(currWord, loadedModel)) != "<END>")
    {
      toCreate.push_back(currWord);
    }
}

void printVector(const vector<string>  *toPrint)
{
  for(vector<string>::const_iterator i = toPrint->begin(); i != toPrint->end(); i++)
    {
      cout << *i << " ";
    }
  cout << "\n";
}
