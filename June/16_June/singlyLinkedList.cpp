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
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }

};

void insertAtHead(Node* &head, int d){
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;    
}

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail->next = newNode;  
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d){
    if(pos == 1){
        insertAtHead(head, d);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    while(count < pos-1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }
    
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;

        while(count < pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        if(prev -> next == NULL){
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp =  head;
    while(temp != NULL){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
}

int main(){
    Node* node1 = new Node(100);

    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;
    
    insertAtHead(head, 99);

    insertAtTail(tail, 101);
    insertAtTail(tail, 102);

    insertAtPosition(head, tail, 5, 105);

    deleteNode(head, tail, 2);

    print(head);

}