// Array to DLL, Traversal of DLL, Length of DLL and Search an element in DLL
#include<bits/stdc++.h>
using namespace std;

class Node{                  
    public:
    int data;
    Node* next;
    Node* back;

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

Node* convertArr2DLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->back=mover;
        mover=mover->next;
    }
    return head;
}

// rest functions same as SLL- T,L,S 
void traversalDLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int lengthDLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head, int val){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data == val) return 1;
        temp=temp->next;
    }
    return 0;
}

int main(){
    // Converting an array to a doubly linked list and returning its head
    vector<int> arr={1,2,3,4};
    Node* head=convertArr2DLL(arr);
    cout<< head->next->data;    //2

    // Traversal of DLL
    // vector<int> arr={5,2,8,1};
    // Node* head=convertArr2DLL(arr);
    // traversalDLL(head);

    // Length of DLL
    // vector<int> arr={5,2,8,1};
    // Node* head=convertArr2DLL(arr);
    // int l=lengthDLL(head);
    // cout<<l;

    // Checking if an element is present in a DLL or not
    // vector<int> arr={5,2,8,1};
    // Node* head=convertArr2LL(arr);
    // int search=checkIfPresent(head,8);
    // cout<<search;

    return 0;
}