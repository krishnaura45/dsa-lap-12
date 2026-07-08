// Insertion of a node in a Linked List
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

void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* insertsHead(Node* head,int el){
    Node* temp=new Node(el);       // OR simply Node* temp=new Node(el,head);
    temp->next=head;
    return temp;
}

Node* insertsTail(Node* head,int el){
    if(head==NULL) return new Node(el);
    Node* tail=new Node(el,NULL);        // Defining a tail node with some value and next pointer as NULL
    Node* temp=head;
    // We have to reach the current last node
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next= tail;
    return head;
}

/* //self written but one mistake is there
Node* insertsK(Node* head, int val, int k){
    if(k==1) return new Node(val,head);
    int c=1;
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        if(k==c){
            prev->next=new Node(val,temp);
        }
        c++;
        prev=temp;
        temp=temp->next;
    }
    return head;
}*/

Node* insertsK(Node* head,int el,int k){
    if(head==nullptr){
        if(k==1) return new Node(el);
        else cout<< "Invalid Input";
    }

    if(k==1){
        return new Node(el,head);
    }

    int counter=0;
    Node* temp=head;
    while(temp!=nullptr){
        counter++;
        if(counter==k-1){
            Node* x=new Node(el);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

// self written, another approach-> striver where we keep eye on 'temp->next' and don't need prev
Node* insertsBeforeValue(Node* head,int el,int val){
    if(val==head->data){
        return new Node(el,head);
    }

    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
        if(temp->data==val){
            Node* x=new Node(el);
            x->next=temp;
            prev->next=x;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){

    // Insertion of node at the beginning OR insertion of new HEAD node
    // vector<int> arr={5,6,7,8};
    // Node* head=convertArr2LL(arr);
    // head= insertsHead(head,11);             // gives new head of the LL after inserting the node at the beginning
    // printLL(head);

    // Insertion of node at the last OR insertion of new TAIL node
    // vector<int> arr={5,3,6,8,9};
    // Node* head=convertArr2LL(arr);
    // head= insertsTail(head,11);             // gives head of the LL after inserting the node at the last
    // printLL(head);

    // Insertion of node at any Kth position from start (k -> 1 to n+1) between two nodes
    // k=1 means inserting element as head and k=n+1 means inserting as tail
    vector<int> arr={5,3,8,9};
    Node* head=convertArr2LL(arr);
    head= insertsK(head,6,5);               // gives head of the LL after inserting the node at a particular position
    printLL(head);

    // Insertion of node with a particular value
    // vector<int> arr={5,3,6,9};
    // Node* head=convertArr2LL(arr);
    // head= insertsBeforeValue(head,8,3);      // gives head of the LL after inserting the node with a apecific value
    // printLL(head);

    return 0;
}