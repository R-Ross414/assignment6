#include "Algorithms.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char **argv)
{
  //variables for size of array and value in array
  int size = 0;
  double val = 0.0;

  //file name as a cmd line argument
  string cmd = argv[1];
  ifstream myfile(cmd);

  //input first line as size
  myfile >> size;

  //initialize array for doubles
  double* vals = new double[size];

  for (int i = 0; i < size; i++)
  {
    vals[i] = 0.0;
  }

  int i = 0;

  //input values from file
  while (myfile)
  {
    myfile >> val;
    vals[i] = val;
    i++;
  }

  //time each algorithm

  //timing for bubble sort
  /*clock_t t;
  t = clock();
  BubbleSort(vals, size);
  t = clock() - t;
  cout << "Bubble Sort " << t << endl; */

  //timing for merge sort
  clock_t t;
  t = clock();
  MergeSort(vals, size, 1, 100000);
  t = clock() - t;
  cout << "Merge Sort " << t << endl;

  //timing for quick sort
  /*clock_t t;
  t = clock();
  QuickSort(vals, 1, 100000);
  t = clock() - t;
  cout << "Quick Sort " << t << endl;

  //timing for insertion sort
  clock_t t;
  t = clock();
  InsertionSort(vals, size);
  t = clock() - t;
  cout << "Insertion Sort " << t << endl; */

  return 0;
}
