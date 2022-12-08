// Q9. Perform merge sort on an array?

#include <iostream>

using namespace std;

void mergeSort(int *, int, int, int);
void merge(int *, int, int, int, int);

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

  mergeSort(arr, 0, size - 1, size);

  cout << "Elements after sorting : ";

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}

void merge(int *arr, int start, int mid, int end, int size)
{
  int *tempArr = new int[size];

  int i = start;
  int j = mid + 1;

  int k = 0;

  while (i <= mid && j <= end)
  {
    if (arr[i] <= arr[j])
    {
      tempArr[k++] = arr[i++];
    }
    else
    {
      tempArr[k++] = arr[j++];
    }
  }

  while (i <= mid)
  {
    tempArr[k++] = arr[i++];
  }

  while (j <= end)
  {
    tempArr[k++] = arr[j++];
  }

  k = start;
  i = 0;

  while (k <= end)
  {
    arr[k++] = tempArr[i++];
  }

  delete tempArr;
}

void mergeSort(int *arr, int start, int end, int size)
{
  if (start == end)
    return;
  int mid = (end + start) / 2;
  mergeSort(arr, start, mid, size);
  mergeSort(arr, mid + 1, end, size);
  merge(arr, start, mid, end, size);
}
