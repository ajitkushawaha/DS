// Q2. Implement stack using array?

#include <iostream>

using namespace std;

class Stack
{
  int Top = -1;
  int size;
  int *stack;

public:
  Stack(int size)
  {
    this->size = size;
    stack = new int[size];
  }

  void push(int num)
  {
    if (Top == size - 1)
    {
      throw "Stack Overflow";
    }
    stack[++Top] = num;
  }

  int pop()
  {
    if (Top == -1)
    {
      throw "Stack Underflow";
    }
    return stack[Top--];
  }

  int top()
  {
    return Top;
  }
};

int main()
{
  Stack *stack = new Stack(5);
  try
  {

    stack->push(6);
    stack->push(7);
    stack->push(8);
    stack->push(9);
    stack->push(10);

    while (stack->top() != -1)
    {
      cout << stack->pop() << endl;
    }
  }
  catch (const char *s)
  {
    cout << s << endl;
  }

  return 0;
}

