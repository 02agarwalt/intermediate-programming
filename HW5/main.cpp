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

int main()
{
  srand(time(NULL));
  vector<string> input;
  vector<string> output;
  LanguageModel model;

  cout << "Please enter line(s) of input to be interpreted by our language model" << endl;
  inputVector(input); //load input vector
  loadLanguageModel(&input, &model); //load language model
  outputVector(&model, output); //create random-styled vector using language model
  printVector(&output); //print random-styled vector

  return 0;
}
