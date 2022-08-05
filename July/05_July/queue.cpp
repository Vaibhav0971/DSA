#include<iostream>
#include<queue>

using namespace std;

void printQueue(queue<int> q){
    if(q.size() == 0) return;

    cout<<q.front()<<", ";
    q.pop();
    printQueue(q);
}

void reverseQueue(queue<int>& q){
    if(q.size() == 0) return;

    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}

int main(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    printQueue(q);
    cout<<endl;
    reverseQueue(q);
    printQueue(q);
}