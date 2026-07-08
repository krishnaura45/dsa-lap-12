// Deletion of a node in a Linked List
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

Node* removesHead(Node* head){
    if(head== nullptr) return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* removesTail(Node* head){
    if(head== nullptr || head->next == nullptr) return NULL;
    Node* temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next= NULL;
    return head;
}

Node* removesKthElement(Node* head, int k){
    Node* temp=head;
    if(k==1){
        head=head->next;
        delete temp;
        return head;
    }
    else{
        int c=0;
        Node* prev=nullptr;
        while(temp!=nullptr){
            c++;
            if(k==c){
                prev->next=prev->next->next;
                free(temp);
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    } 
    return head;
}

Node* removesValue(Node* head,int val){
    Node* temp=head;
    if(head->data==val){
        head=head->next;
        delete temp;
        return head;
    }
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){

    // // Deletion of node at the beginning OR deletion of HEAD node
    // vector<int> arr={5,3,6,7,8};
    // Node* head=convertArr2LL(arr);
    // head= removesHead(head);   // gives new head of the LL after removing the node at the beginning
    // printLL(head);

    // // Deletion of node at the last OR deletion of TAIL node
    // vector<int> arr={5,3,6,8,9};
    // Node* head=convertArr2LL(arr);
    // head= removesTail(head);   // gives head of the LL after removing the node at the last
    // printLL(head);

    // Deletion of node at any Kth position from start
    vector<int> arr={5,3,6,8,9};
    Node* head=convertArr2LL(arr);
    head= removesKthElement(head,3);   // gives head of the LL after removing the node at a particular position
    printLL(head);

    // // Deletion of node with a particular value
    // vector<int> arr={5,3,6,8,9};
    // Node* head=convertArr2LL(arr);
    // head= removesValue(head,5);   // gives head of the LL after removing the node with a apecific value
    // printLL(head);

    return 0;
}