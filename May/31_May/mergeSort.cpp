#include<iostream>

using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s + e) / 2;

    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    int *left = new int[leftLength];
    int *right = new int[rightLength];

    int originalIndex = s;
    for(int i=0; i<leftLength; i++){
        left[i] = arr[originalIndex++];
    }

    originalIndex = mid + 1;
    for(int i=0; i<rightLength; i++){
        right[i] = arr[originalIndex++];
    }

    int leftIndex = 0, rightIndex = 0;
    originalIndex = s;
    while(leftIndex < leftLength && rightIndex < rightLength){
        if(left[leftIndex] <= right[rightIndex]){
            arr[originalIndex++] = left[leftIndex++];
        }
        else{
            arr[originalIndex++] = right[rightIndex++];
        }
    }

    while(leftIndex < leftLength){
        arr[originalIndex++] = left[leftIndex++];
    }

    while(rightIndex < rightLength){
        arr[originalIndex++] = right[rightIndex++];
    }


}

void mergeSort(int arr[], int s, int e){
    if(s >= e) return;

    int mid = (s + e) / 2;

    // left size
    mergeSort(arr, s, mid);

    // right side
    mergeSort(arr, mid+1, e);

    // merge
    merge(arr, s, e);
}

int main(){
    int arr[] = {12, 11, 13, 9, 6, 2};
    int size = 6;
    mergeSort(arr, 0, size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }



}