// Array to LL, Traversal of LL, Length of LL and Search an element in LL
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

Node* convertArr2LL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;   // mover= mover->next
    }
    return head;
}

void traversal(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int lengthLL(Node* head){
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
    // // Converting an array to a linked list and returning its head
    // vector<int> arr={1,2,3,4};
    // Node* head=convertArr2LL(arr);
    // cout<< head->data;

    // Traversal of LL
    vector<int> arr={5,2,8,1};
    Node* head=convertArr2LL(arr);
    traversal(head);

    // // Length of LL
    // vector<int> arr={5,2,8,1};
    // Node* head=convertArr2LL(arr);
    // int l=lengthLL(head);
    // cout<<l;

    // // Checking if an element is present in a LL or not
    // vector<int> arr={5,2,8,1};
    // Node* head=convertArr2LL(arr);
    // int search=checkIfPresent(head,8);
    // cout<<search;

    return 0;
}