// Q8. Create a Priority Queue using Max Heap and perform related operations?

#include <iostream>
#include <cmath>

using namespace std;

class MaxHeap
{
  int *heap;
  int size = 0;
  int maxSize;

  int parent(int i)
  {
    int p = (i + 1) / 2 - 1;

    if (p < 0)
      return -1;
    return p;
  }

  int firstChild(int i)
  {
    int c = (i * 2) + 1;

    if (c > size - 1)
      return -1;
    return c;
  }

  int secondChild(int i)
  {
    int c = (i * 2) + 2;

    if (c > size - 1)
      return -1;
    return c;
  }

  void swap(int i, int j)
  {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
  }

  void heapify(int i)
  {
    int fc = firstChild(i);
    int sc = secondChild(i);
    int largest = i;

    if (fc == -1 && sc == -1)
    {
      return;
    }
    if (fc == -1 && heap[sc] > heap[i])
    {
      largest = sc;
    }
    else if (sc == -1 && heap[fc] > heap[i])
    {
      largest = fc;
    }
    else if (fc != -1 && sc != -1)
    {
      if (heap[fc] > heap[sc])
      {
        largest = fc;
      }
      else if (heap[sc] > heap[fc])
      {
        largest = sc;
      }
    }

    if (largest != i && heap[largest] > heap[i])
    {
      swap(largest, i);
      heapify(largest);
    }
  }

public:
  MaxHeap(int maxSize)
  {
    this->maxSize = maxSize;
    heap = new int[maxSize];
  }

  void insertElement(int data)
  {
    if (size == maxSize)
    {
      throw "Heap is full";
    }
    heap[size++] = data;

    if (size == 1)
      return;

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
      heapify(i);
    }
  }

  void deleteElementByIndex(int i)
  {
    if (i < 0 || i > size - 1)
      throw "No element exist on this index";

    if (i == size - 1)
    {
      size--;
      return;
    }

    swap(size - 1, i);

    size--;

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
      heapify(i);
    }
  }

  void printElements()
  {
    int j = 0;
    for (int i = 0; i < size; i++)
    {
      cout << heap[i] << " ";
      if (i == j)
      {
        cout << endl;
        j = (j + 1) * 2;
      }
    }
    cout << endl;
  }

  int search(int num)
  {
    for (int i = 0; i < size; i++)
    {
      if (heap[i] == num)
        return i;
    }
    return -1;
  }

  int peek()
  {
    if (size == 0)
      throw "Heap has no elements";
    return heap[0];
  }
};

class PriorityQueue
{
  MaxHeap *maxHeap;

public:
  PriorityQueue(int n)
  {
    maxHeap = new MaxHeap(n);
  }

  void insertElement(int num)
  {
    maxHeap->insertElement(num);
  }

  void deleteElement(int num)
  {
    int i = maxHeap->search(num);
    maxHeap->deleteElementByIndex(i);
  }
  bool ifExist(int num)
  {
    int i = maxHeap->search(num);
    if (i == -1)
      return false;
    return true;
  }
  int peak()
  {
    return maxHeap->peek();
  }
  void print()
  {
    maxHeap->printElements();
  }
};

int main()
{
  try
  {
    PriorityQueue *pq = new PriorityQueue(10);
    pq->insertElement(5);
    pq->insertElement(10);
    pq->insertElement(2);
    pq->insertElement(3);
    pq->insertElement(7);
    pq->insertElement(1);

    pq->print();

    cout << endl
         << "Peak Element : " << pq->peak() << endl;

    pq->deleteElement(pq->peak());

    cout << endl;
    pq->print();
  }
  catch (const char *s)
  {
    cout << s << endl;
  }

  return 0;
}