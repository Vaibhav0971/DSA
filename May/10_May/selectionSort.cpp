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

void selectionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minIndex]) minIndex = j;
        }
        swapArrayElements(arr, i, minIndex); 
    }
    printArray(arr, size);
}

int main(){
    system("cls");

    int arr[] = {6,4,3,8};
    selectionSort(arr, 4);
}

// IT iS UNSTABLE - TRY CONVERTING IT INTO STaBLE