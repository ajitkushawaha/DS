// Q1. Implement queue using array?

#include <iostream>

using namespace std;

class Queue
{
  int Top = -1;
  int *queue;
  int size;
  int Front = -1;
  int Rear = -1;

public:
  Queue(int size)
  {
    this->size = size;
    queue = new int[size];
  }

  void enqueue(int num)
  {
    if (Rear == size - 1)
    {
      throw "Queue Overflow";
    }
    if (Rear == -1)
      Front = 0;
    queue[++Rear] = num;
  }

  int dequeue()
  {
    if (Front == -1){
      throw "Queue Underflow";
    }
    int temp = Front;
    if (Front == Rear)
    {
      Front = Rear = -1;
      return queue[temp];
    }
    else
      return queue[Front++];
  }

  int front()
  {
    return Front;
  }
};

int main()
{
  Queue *queue = new Queue(5);
  try
  {
    queue->enqueue(5);
    queue->enqueue(6);
    queue->enqueue(7);
    queue->enqueue(8);
    queue->enqueue(9);

    while (queue->front() != -1)
    {
      cout << queue->dequeue() << endl;
    }
  }
  catch (const char *s)
  {
    cout << s << endl;
  }

  return 0;
}
