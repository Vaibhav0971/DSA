#include<iostream>
#include<stdlib.h>

using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int * swapArrayElements(int arr[], int firstEl, int secondEl){
    int buffer = arr[firstEl];
    arr[firstEl] = arr[secondEl];
    arr[secondEl] = buffer;
    return arr;
}

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        bool swapped = false;
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swapArrayElements(arr, j, j+1); 
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    printArray(arr, size);
}

int main(){
    system("cls");

    int arr[] = {6,4,3,8};
    bubbleSort(arr, 4);


}

// HOW TO OPTIMISE USING FLAG IN ITERVIEW