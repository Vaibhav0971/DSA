#include<iostream>
#include<queue>

using namespace std;

int getKthLargestElement(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<k; i++){
        minHeap.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        if(arr[i] > minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    return minHeap.top();
}

int main(){
    // // MAX HEAP
    // priority_queue<int> q;
    // // insertion
    // q.push(1);
    // q.push(2);
    // q.push(5);
    // q.push(5);
    // q.push(3);

    // // top or root element
    // cout<<q.top()<<endl;
    // // deletion
    // q.pop();
    // cout<<q.size()<<endl;

    // if(q.empty()) cout<<"Queue is empty"<<endl;
    // else cout<<"Queue not is empty"<<endl;

    // // ******************************************************************************************

    // // MIN HEAP
    // priority_queue<int, vector<int>, greater<int>> minHeap;    
    // // insertion
    // minHeap.push(5);
    // minHeap.push(4);
    // minHeap.push(3);
    // minHeap.push(1);
    // minHeap.push(2);

    // // top or root element
    // cout<<minHeap.top()<<endl;
    // // deletion
    // minHeap.pop();
    // cout<<minHeap.size()<<endl;

    // if(minHeap.empty()) cout<<"Queue is empty"<<endl;
    // else cout<<"Queue not is empty"<<endl;
    
    // // ******************************************************************************************

    // int arr[] = {3,2,5,1,6,7,8,9};
    // int n = 8;

    // cout<<getKthLargestElement(arr, 8, 3)<<endl;
 
}