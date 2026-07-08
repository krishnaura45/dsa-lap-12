// Basics of DLL => Definition of Node
#include<bits/stdc++.h>
using namespace std;

class Node{                  
    public:
    int data;
    Node* next;
    Node* back;    // addition of reference to prev node

    public:
    Node(int data1,Node* next1,Node* back1){   // first constructor
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){               // second constructor
        data=data1;
        next=NULL;
        back=nullptr;
    }
};

int main(){
    
    Node* x=new Node(4);
    cout<<x->data<<endl;
    cout<<x->next<<endl;
    cout<<x->back;
    return 0;
}