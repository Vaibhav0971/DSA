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

Node* kReverse(Node* head, int k) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    
    for(int i=0; i<k; i++){
        if(curr == NULL) return prev;
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    
    if(curr != NULL){
        head -> next = kReverse(curr, k);        
    }     
    return prev;
}

Node* splitHalf(Node* head){
    if(head == NULL || head -> next == NULL) return head;

    Node* slow = head;
    Node* fast = head;

    while(fast -> next != NULL && slow -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
        if(fast -> next != NULL){
            fast = fast -> next;
        }
        else{
            break;
        }
    }

    return slow;
}

void print(Node* &head){
    Node* temp =  head;
    while(temp != NULL){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* createLL(int start, int n){
    if(n < start) return NULL;
    
    Node* temp = new Node(start);
    temp -> next = createLL(start+1, n);
    
    return temp;
}

int main(){    
    Node* head = createLL(1, 3);
    print(head);

    // kReverse(head, 2);

    Node* div = splitHalf(head);
    cout<<div -> data;

    // print(head);
}