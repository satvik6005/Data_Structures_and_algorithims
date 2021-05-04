#include<iostream>

using namespace std;
/*quicksort*/
void swap (int &a, int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int pivot_genrator (int low, int high, int **arr)
{
  int i = low - 1;
  for (int j = low; j <= high; j++)
    {
      if ((*arr)[j] <= (*arr)[high])
	{
	  i++;
	  swap ((*arr)[i], (*arr)[j]);
	}
    }
  return i;
}

void sort (int low, int high, int **arr)
{
  if (low < high)
    {
      int pivot = pivot_genrator (low, high, arr);
      sort (low, pivot - 1, arr);
      sort (pivot + 1, high, arr);
    }
}

void display (int &size, int **arr)
{
  for (int i = 0; i < size; i++)
    {
      cout << (*arr)[i];
    }

}

int main ()
{
  int *arr = new int;
  int *size = new int;
  cout << "enter the size of the array";
  cin >> *size;
  for (int i = 0; i < *size; i++)
    {
      cin >> arr[i];
    }
  sort (0, *size - 1, &arr);
  display (*size, &arr);



  return 0;
}

