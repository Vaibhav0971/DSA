#include<iostream>

using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot) count++;
    }
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i=s, j=e;
    while(i<pivotIndex && pivotIndex<j){
        if(arr[i] > pivot){
            if(arr[j] < pivot){
                swap(arr[i], arr[j]);
            }
            else j--;
        }
        else i++;        
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s >= e) return;

    // partition
    int p = partition(arr, s, e);

    // left side
    quickSort(arr, s, p-1);

    // right side
    quickSort(arr, p+1, e);
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = 6;
    quickSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}