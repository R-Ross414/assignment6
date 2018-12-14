#include <iostream>
using namespace std;

void swap(double* A, double* B)
{
  double temp = *A;
  *A = *B;
  *B = temp;
}

///////////////////////////////////////////////////////////////////////////
//partitioning for quick sort
int partition(double* vals, int low, int high)
{
  //choose an element as a pivot point
  double pivot = vals[high];
  int i = low - 1;
  int j = low;

  //for loop for sorting elements in comparison to the pivot
  for (j = low; j <= high - 1; j++)
  {
    if (vals[j] <= pivot)
    {
      i++;
      swap(&vals[i], &vals[j]);
    }
  }

  swap(&vals[i+1], &vals[high]);

  return i + 1;
}

//////////////////////////////////////////////////////////////////////////
/////////////////////////////QUICK SORT//////////////////////////////////
void QuickSort(double* vals, int low, int high)
{
  //series of partitioning
  if (low < high)
  {
    int pivot = partition(vals, low, high);

    //recursive calls
    QuickSort(vals, low, pivot - 1);
    QuickSort(vals, pivot + 1, high);
  }
}

//////////////////////////////////////////////////////////////////////////
/////////////////////////////BUBBLE SORT//////////////////////////////////
void BubbleSort(double* vals, int size)
{
  int i, j = 0;

  //nested for loops for iterating through doubles
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      //condition for swapping
      if (vals[j] > vals[j + 1])
      {
        swap(&vals[j], &vals[j + 1]);
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////
//merge for merge sort
void merge(double* vals, int size, int left, int mid, int right)
{
	//temporary array
	double* sorted = new double[size];

	int i = left;
	int j = mid + 1;
	int k = left;

	//a and b arent fully copied
	while (i <= mid && j <= right)
	{
		if (vals[i] < vals[j]) sorted[k++] = vals[i++];
		else sorted[k++] = vals[j++];
	}

	//a isn't fully copied
	while (i <= mid)
	{
		sorted[k++] = vals[i++];
	}

	//b isn't fully copied
	while (j <= right)
	{
		sorted[k++] = vals[j++];
	}

	//copy elements into array
	for (i = left; i < k; i++) vals[i] = sorted[i];

	return;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////MERGE SORT////////////////////////////////
void MergeSort(double* vals, int size, int left, int right)
{
	//middle value
	int mid;

	if (left < right)
	{
		//calculating the middle value
		mid = (left + right) / 2;

		//recursive calls
		MergeSort(vals, size, left, mid);
		MergeSort(vals, size, mid + 1, right);

		//merge elements
		merge(vals, size, left, mid, right);
	}

	return;
}

////////////////////////////////////////////////////////////////////////
//////////////////////////INSERTION SORT////////////////////////////////
void InsertionSort(double* vals, int size)
{
  int i,j = 0;

  for (i; i < size; i++)
  {
    j = i;

    while (j > 0 && vals[j] < vals[j - 1])
    {
      swap(&vals[j], &vals[j - 1]);
      j--;
    }

  }
}
