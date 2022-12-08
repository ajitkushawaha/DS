// Q11. Perform Binary Search on an array?

#include <iostream>

using namespace std;

void binarySearch(int *, int, int);

int main()
{
  int size;
  int target;

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

  cout << "Enter the element to search : ";
  cin >> target;

  binarySearch(arr, size, target);

  return 0;
}

void binarySearch(int *arr, int size, int target)
{
  int start = 0;
  int end = size - 1;
  int mid;

  while (start <= end)
  {
    mid = (start + end) / 2;

    if (arr[mid] == target)
    {
      cout << target << " found at index " << mid << endl;
      return;
    }
    else if (arr[mid] > target)
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }

  cout << target << " doesn't exist in array" << endl;
}
