// Implementing Queue using Array
#include<bits/stdc++.h>
using namespace std;
class Queue {
  int * arr;
  int front, rear, cnt, n;  // start, end, current size, maximum size
  public:
    Queue() {
      arr = new int[15];
      front = 0;
      rear = 0;
      cnt = 0;
    }

  Queue(int n) {
    ( * this).n = n;
    arr = new int[n];
    front = 0;
    rear = 0;
    cnt = 0;
  }

  void push(int el) {
    if(cnt==n) {
        cout<<"Unable to push, queue is full"<<endl;
        return;
    }
    arr[rear%n]=el;
    rear++;
    cnt++;
    cout<<"Pushed "<< el<<" into the queue"<<endl;
  }

  int pop() {
    if(cnt==0) {
        cout<<"Unable to pop, queue is empty"<<endl;
        return -1;
    }
    int x=arr[front%n];
    arr[front%n]=-1;
    front++;
    cnt--;
    return x;
  }

  int top() {
    return arr[front%n];
  }

  int size() {
    return cnt;
  }

};

int main() {
  Queue q(3);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element: " << q.top() << endl;
  cout << "The size of the queue before deletion: " << q.size() << endl;
  cout << "The first element to be deleted: " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element: " << q.top() << endl;
  cout << "The size of the queue after deleting an element: " << q.size() << endl;

  cout<<q.pop();
  q.push(3);
  cout<<q.pop();
  q.push(5);
  cout<<q.pop();
  q.push(7);
  cout<<q.pop();

  return 0;
}