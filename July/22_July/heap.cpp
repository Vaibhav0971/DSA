#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    int arr[250];
    int size;

    Heap(){
        size = 0;
    }

    void insertIntoHeap(int data){
        size++;
        int index = size;
        arr[index] = data;

        while(index > 1){
            if(arr[index] > arr[index / 2]){
                arr[index] = arr[index / 2];
                arr[index / 2] = data;
                index = index / 2;
            }
            else return;
        }
    }

    void deleteFromHeap(){
        if(size == 0) {
            cout<<"Heap is already empty"<<endl;
            return;
        }
        swap(arr[1], arr[size]);
        size--;

        int index = 1;
        while(index <= size){
            if((arr[index] < arr[index * 2]) || (arr[index] < arr[index * 2 + 1])){
                if(arr[index * 2] > arr[index * 2 + 1]){
                    swap(arr[index * 2], arr[index]);
                }
                else{
                    swap(arr[index * 2 + 1], arr[index]);
                }
            }
            else return;
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int index){
    if((arr[index] < arr[index * 2]) || (arr[index] < arr[index * 2 + 1])){
        if(arr[index * 2] > arr[index * 2 + 1]){
            swap(arr[index * 2], arr[index]);
            heapify(arr, index * 2);
        }
        else{
            swap(arr[index * 2 + 1], arr[index]);
            heapify(arr, index * 2 + 1);
        }
    }
}

int main(){
    // Heap maxHeap = Heap();
    // maxHeap.insertIntoHeap(2);
    // maxHeap.insertIntoHeap(6);
    // maxHeap.insertIntoHeap(8);
    // maxHeap.insertIntoHeap(3);
    // maxHeap.insertIntoHeap(7);
    // maxHeap.print();
    // maxHeap.deleteFromHeap();
    // maxHeap.print();

    // int size = 6;
    // int arr[size] = {-1,2,6,8,3,7};
    // for(int i = size/2; i>=1; i--){
    //     heapify(arr, i);
    // }
    // for(int i=1; i<size; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

}