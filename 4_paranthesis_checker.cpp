// Q4. Using Stack check if an expression has balanced paranthesis

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

  string s;
  cout << "Enter an arithmetic exprression : ";
  cin >> s;

  Stack *stack = new Stack(s.length());

  for (char c : s)
  {
    if (c == '(')
    {
      stack->push(c);
    }
    if (c == ')')
    {
      stack->pop();
    }
  }

  if (stack->top() == -1)
  {
    cout << "Expression has balanced paranthesis" << endl;
  }
  else
  {
    cout << "Expression does not has balanced paranthesis" << endl;
  }

  return 0;
}
