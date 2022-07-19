#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void insertNode(Node* &tail, int element, int d){
    Node* newNode = new Node(d);

    if(tail == NULL){
        newNode -> next = newNode;
        tail = newNode;
    }
    else{
        Node* temp = tail;
        while(temp -> data != element){
            temp = temp -> next;
        }

        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev -> next;
    while(curr -> data != value){
        prev = curr;
        curr = prev -> next;
    }

    prev -> next = curr -> next;
    
    if(curr == prev){
        tail = NULL;
    }
    else if(tail == curr){
        tail = prev;
    }
    
    curr -> next = NULL;
    delete curr;
}

bool isCircularList(Node* &tail){
    if(tail == NULL){
        return true;
    }

    Node* temp = tail -> next;
    while(temp != NULL && temp != tail ) {
        temp = temp -> next;
    }

    if(temp == tail ) {
        return true;
    }

    return false;
}

void print(Node* tail){
    if(tail == NULL){
        cout<<"List is empty."<<endl;
        return;
    }

    Node* temp = tail;
    do{
        cout<<tail -> data<<", ";
        tail = tail -> next;
    }
    while(tail != temp);
    
    cout<<endl;
}

int main(){
      Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

   insertNode(tail, 3, 5);
   print(tail);


    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);
    insertNode(tail, 3, 4);
    print(tail);
   
    deleteNode(tail, 5);
    print(tail);
     

    // if(isCircularList(tail)) {
    //     cout << " Linked List is Circular in nature" << endl;
    // }
    // else{
    //     cout << "Linked List is not Circular " << endl;
    // }
}