// Implementing Stack using Array  --> LIFO
#include<bits/stdc++.h>
using namespace std;

class Stack {
  int maxsize;
  int *arr;
  int top;
  public:
    Stack() {
      top = -1;
      maxsize = 1000;
      arr = new int[maxsize];
    }

  void push(int x) {
    top++;
    arr[top] = x;         // or simply -> arr[++top] = x
  }

  int pop() {
    int x = arr[top];
    top--;
    return x;
  }

  int Top() {
    return arr[top];
  }

  int Size() {
    return top + 1;
  }
};

int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack before deleting any element: " << s.Top() << endl;
  cout << "Size of stack before deleting any element: " << s.Size() << endl;
  cout << "The element deleted: " << s.pop() << endl;
  cout << "Size of stack after deleting an element: " << s.Size() << endl;
  cout << "Top of stack after deleting an element: " << s.Top() << endl;
  return 0;
}