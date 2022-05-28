#include<iostream>
#include<stdlib.h>

using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int j=i-1, temp = arr[i];
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j]; 
            j--;
        }
        arr[j+1]=temp;
    }
    printArray(arr, size);
}

int main(){
    system("cls");

    int arr[] = {6,4,3,8};
    insertionSort(arr, 4);
}