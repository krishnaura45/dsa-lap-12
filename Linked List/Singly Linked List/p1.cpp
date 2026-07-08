// Basics of LL => Definition of Node, struct and class
#include<bits/stdc++.h>
using namespace std;

class Node{                   // 'struct' does the same but 'class' allows OOP such as abstraction, etc
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){   // first constructor
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){               // second constructor
        data=data1;
        next=NULL;
    }
};

int main(){
    // Node* head= new Node(2,nullptr);        // new keyword assigns a pointer to the memory location directly
    // cout<< head;

    // Node y= Node(1,nullptr);                // one way of declaration of node
    // cout<< y.data<<endl;
    // cout<< y.next;

    // Node* n= new Node(3, NULL);             // another way
    // cout<< n->data;
    // cout<< n->next;

    Node* x=new Node(4);
    cout<<x->data<<endl;
    cout<<x->next;
    return 0;
}