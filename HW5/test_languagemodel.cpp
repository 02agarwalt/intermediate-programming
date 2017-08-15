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

void test_inputVector()
{
  vector<string> test;
  inputVector(test);
  
  assert(test.front() == "<START>");
  assert(test[1] == "this");
  assert(test[2] == "is");
  assert(test[3] == "a");
  assert(test[4] == "test");
  assert(test[5] == "input");
  assert(test[6] == "file");
  assert(test.back() == "<END>");
}

void test_loadLanguageModel()
{
  vector<string> test = { "<START>", "he", "liked", "that", "he", "ate", "the", "sandwich", "he", "liked", "<END>" };

  LanguageModel testModel;

  loadLanguageModel(&test, &testModel);

  assert(testModel.pairCountMap["<START> he"] == 1);
  assert(testModel.pairCountMap["he liked"] == 2);
  assert(testModel.pairCountMap["liked <END>"] == 1);

  assert(testModel.pairStartCountMap["<START>"] == 1);
  assert(testModel.pairStartCountMap["he"] == 3);
  assert(testModel.pairStartCountMap["liked"] == 2);

  assert(testModel.pairFollowMap["<START>"].front() == "he");
  assert(testModel.pairFollowMap["<START>"].back() == "he");
  assert(testModel.pairFollowMap["he"].front() == "liked");
  assert(testModel.pairFollowMap["he"].back() == "ate");
  assert(testModel.pairFollowMap["liked"].front() == "that");
  assert(testModel.pairFollowMap["liked"].back() == "<END>");
}

void test_printVector()
{
  vector<string> test = { "<START>", "he", "liked", "that", "he", "ate", "the", "sandwich", "he", "liked", "<END>" };

  printVector(&test);
}

void test_getWord()
{
  vector<string> test = { "<START>", "he", "liked", "that", "he", "ate", "the", "sandwich", "he", "liked", "<END>" };
  LanguageModel testModel;
  loadLanguageModel(&test, &testModel);
  
  string testString = getWord("<START>", &testModel);
  assert(testString == "he");

  testString = getWord("the", &testModel);
  assert(testString == "sandwich");
}

void test_outputVector()
{
  vector<string> test = { "<START>", "he", "liked", "that", "he", "ate", "the", "sandwich", "he", "liked", "<END>" };
  LanguageModel testModel;
  loadLanguageModel(&test, &testModel);

  vector<string> toCreate;
  outputVector(&testModel, toCreate);

  assert(toCreate[0] == "he");
  assert(toCreate.back() == "liked");
}

int main()
{
  srand(time(NULL));
  
  test_inputVector();
  test_loadLanguageModel();
  test_printVector();
  test_getWord();
  test_outputVector();
  return 0;
}
