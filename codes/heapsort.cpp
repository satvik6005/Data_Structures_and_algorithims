//heapsort in one programme
#include<iostream>

using namespace std;
void
make (int **a, int &size)
{
  cout << "enter the size of the array \n";
  cin >> size;
  *a = new int[size];
  cout << "enter the values \n";
  for (int i = 0; i <= size - 1; i++)
    {
      cin >> (*a)[i];
    }

}

void
display (int *a, int &size)
{
  for (int i = 0; i <= size - 1; i++)
    {
      cout << a[i] << "\n";
    }
}

void
swap (int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void
heapify (int *a, int i, int size)
{
  int left, right, largest = i;
  left = 2 * i + 1;
  right = 2 * i + 2;
  if (left < size && a[left] > a[largest])
    {

      largest = left;
    }
  if (right < size && a[right] > a[largest])
    {

      largest = right;
    }
  if (largest != i)
    {
      swap (a[largest], a[i]);
      heapify (a, largest, size);
    }





}

void
seek (int *a, int size)
{

  while (size > 0)
    {
      swap (a[0], a[size - 1]);
      size--;
      heapify (a, 0, size);
    }
}

void
heaping (int *a, int &size)
{
  int i = (size - 2) / 2;
  while (i >= 0)
    {
      heapify (a, i, size);
      i--;
    }
  seek (a, size);
}

int
main ()
{

  int *a, size = 0, choice;
  do
    {
      cout <<
	"enter 1 to enter the array 2 to sort it and 3 to dispaly it \n ";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  make (&a, size);
	  break;
	case 2:
	  heaping (a, size);
	  break;
	case 3:
	  display (a, size);
	  break;
	default:
	  cout << "wrong choice \n";


	};
    }
  while (1);
