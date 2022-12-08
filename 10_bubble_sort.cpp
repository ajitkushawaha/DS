// Q10. Perform bubble sort on an array?

#include <iostream>

using namespace std;

void bubbleSort(int *, int);

int main()
{
  int size;

  cout << "Enter the number of elements : ";

  cin >> size;

  if (size < 0)
  {
    throw "Invalid number of elements. Try Again.";
  }

  cout << "Enter the elements : ";

  int *arr = new int[size];

  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  bubbleSort(arr, size);

  cout << "Elements after sorting : ";

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}

void bubbleSort(int *arr, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - (i + 1); j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}