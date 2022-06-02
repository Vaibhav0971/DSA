#include<iostream>

using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s + e) / 2;

    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    //create  left and right parts
    int *left = new int[leftLength];
    int *right = new int[rightLength];

    //copy into left array
    int originalIndex = s;
    for(int i=0; i<leftLength; i++){
        left[i] = arr[originalIndex++];
    }

    //copy into right array
    originalIndex = mid + 1;
    for(int i=0; i<rightLength; i++){
        right[i] = arr[originalIndex++];
    }

    // now we have 2 sorted arrays 
    // we have to merge them
    int leftIndex = 0, rightIndex = 0;
    originalIndex = s;

    //compare elements from left and right array and copy into original array
    while(leftIndex < leftLength && rightIndex < rightLength){
        if(left[leftIndex] <= right[rightIndex]){
            arr[originalIndex++] = left[leftIndex++];
        }
        else{
            arr[originalIndex++] = right[rightIndex++];
        }
    }

    //check if any more element is present in left array ,
    // then copy it to original array
    while(leftIndex < leftLength){
        arr[originalIndex++] = left[leftIndex++];
    }

    //check if any more element is present in right array ,
    // then copy it to original array
    while(rightIndex < rightLength){
        arr[originalIndex++] = right[rightIndex++];
    }

    // clearing dynamic array
    delete [] left;
    delete [] right;
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = 6;
    mergeSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}