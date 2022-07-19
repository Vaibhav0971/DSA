#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        if(next !=  NULL){
            delete next;
            next = NULL;
        }
    }
};

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(d);
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(d);
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d){
    if(pos == 1){
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int count = 1;
    
    while(count < pos - 1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    temp -> next = newNode;
    newNode -> prev = temp;
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* temp = head;
        int count = 1;

        while(count < pos){
            temp = temp -> next;
            count++;
        }

        if(temp -> next == NULL){
            temp -> prev -> next = NULL;
            tail = temp -> prev;
            temp -> prev = NULL;
            temp -> next = NULL;
            delete temp;
            return;
        }

        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        temp -> next = NULL;
        temp -> prev = NULL;

        delete temp;
    }
}

int getLength(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<", ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){ 
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head,tail, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(head,tail, 13);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(head,tail, 8);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(head,tail, 25);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(head, tail, 2, 100);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(head, tail, 1, 101);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(head, tail, 7, 102);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    deleteNode(head, tail, 7);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
    
    deleteNode(head, tail, 3);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

}