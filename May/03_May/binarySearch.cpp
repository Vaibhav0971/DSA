#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int binarySearch(int arr[], int size, int target){
    int start = 0, end = size-1, mid = end/2;

    while(start <= end){
        if(target == arr[mid]){
            cout<<"Element found "<<arr[mid]<<" at index "<<mid<<endl;
            return mid;
        }
        if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        } 
        mid = start + (end - start)/2;
    }
    cout<<"Element not found"<<endl;
    return -1;
}

int firstOccurence(int arr[], int size, int target){
    int start = 0, end = size-1, mid = end/2, ans = -1;

    while(start <= end){
        if(target == arr[mid]){
            ans = mid;
            end = mid - 1;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        } 
        mid = start + (end - start)/2;
    }
    return ans;
}

int lastOccurence(int arr[], int size, int target){
    int start = 0, end = size-1, mid = end/2, ans = -1;

    while(start <= end){
        if(target == arr[mid]){
            ans = mid;
            start = mid + 1;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        } 
        mid = start + (end - start)/2;
    }
    return ans;
}

int totalOccurence(int arr[], int size, int target){
    return lastOccurence(arr, size, target) - firstOccurence(arr, size, target) + 1;
}

int fixedPointElement(int arr[], int size){
    int start = 0, end = size-1, mid = end/2;

    while(start <= end){
        if(mid == arr[mid]){
            cout<<mid<<endl;
            // return mid;
        }
        // we go towards the left because if arr[mid] is 3 and mid is 1 then even if i will go
        // towards right i can never reach the fixed point
        //                  👇
        // arr index - _ _ _ 1 2 3 4 5 ....
        // arr values  _ _ _ 3 4 5 6 7 .....
        // that's the reason i will have to go towards the left to find the fixd point
        // NOTE -> IT IS GIVEN THAT ALL ELEMENTS ARE DISTINCT AND FIND ONLY ONE FIXED POINT
        if(mid < arr[mid]){
            end = mid - 1;
        }
        // opposite reason for going left
        else{
            start = mid + 1;
        } 
        mid = start + (end - start)/2;
    }
    return -1;
}

int pivotElement(int arr[], int size){
    if(size == 0) return -1;
        
    int total=0, countLeft=0;
    
    for(int i=0; i<size; i++){
        total += arr[i];
    }
    
    for(int i=0; i<size; i++){
        if(countLeft == (total - arr[i]))
            return i;
        else{
            countLeft += arr[i];
            total -= arr[i];
        }
    }

    return -1;
}

int pivotElementRotatedArray(int arr[], int size){
    int start=0, end=size-1, mid=end/2;        
    while(start<end){            
        if(arr[mid] < arr[end])end = mid;
        else if(arr[mid] == arr[end])end--;
        else start = mid+1;            
        mid=start+(end-start)/2;
    }        
    return arr[start];
}

int searchRotatedSortedArray(int arr[], int size, int target){
    int start = 0, end = size-1, mid = end/2;
    int pivotIndex = pivotElementRotatedArray(arr, size);

    if(arr[pivotIndex] <= target && target <= arr[end]) start = pivotIndex;
    else end = pivotIndex;

    mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid] == target) return mid;
        if(arr[mid]<target) start=mid+1;
        if(arr[mid]>target) end=mid-1;
        mid=start+(end-start)/2;
    }
    return -1;
}

int peakMountain(int arr[], int size){
    int start=0, end=size-1, mid=end/2;
        
    while(start <= end){
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;
        
        if(arr[mid]<arr[mid+1]) start=mid;
        
        if(arr[mid]>arr[mid+1]) end=mid;
        
        mid=start+(end-start)/2;   
    }
    
    return -1;       
}

long long int squareRoot(int val){
    int start=1, end=val;
    long long int mid=start+(end-start)/2, ans=-1;;

    while(start<=end){
        if(val == mid*mid) return mid;
        else if(val>mid*mid){
            start=mid+1;
            ans = mid;
        }
        else end=mid-1;
        mid=start+(end-start)/2;
    }

    return ans;
}

double precisionSquareRoot(int val, int precision){
    int tempSol = squareRoot(val);
    double factor = 1, ans=tempSol;

    for(int i=0; i<precision; i++){
        factor /= 10;
        for(double j=ans; j*j<val; j+=factor){
            ans=j;
        }
    }
    return ans;
}

bool doubleExists(int arr[], int size){
    sort(arr, arr+size);

    for(int i=0; i<size; i++){
        if(arr[i]>=0 && binary_search(arr+i+1, arr+size, 2*arr[i])){
            cout<<"Double exists for "<<arr[i]<<endl;
            return true;
        }
        if(arr[i]<0 && arr[i]%2==0 && binary_search(arr+i+1, arr+size, arr[i]/2)){
            cout<<"Double exists for "<<arr[i]<<endl;
            return true;
        }
    }
    return false;
}

int searchInArrayOfUnknownSize(int arr[], int target){
    int start = 0, end = 1, val = arr[0];

    while(val<target){
        start = end;
        end = 2*end;
        val = arr[end];
    }
    
    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid]==target) return mid;
        if(arr[mid]<target) start = mid+1;
        else end = mid-1;
        mid = start + (end-start)/2;
    }   
    return -1;
}

int main(){
    system("cls");

    // int arr[] = {2,4,6,8,9,11,23};
    // binarySearch(arr, 7, 23);
    // BUILT IN BINARY SORT FUNCTION 👇
    // cout<<endl<<binary_search(arr, arr+7, 23);

    // int arr1[7] = {0,5,5,5,5,8,12};
    // cout<<firstOccurence(arr1, 7, 5);
    // cout<<lastOccurence(arr1, 7, 5);
    // cout<<totalOccurence(arr1, 7, 5);

    // int arr2[] = {-10, -5, 0, 3, 7, 5};
    // fixedPointElement(arr2, 6);

    // int arr3[] = {2,1,-1};
    // cout<<pivotElement(arr3, 3);

    int arr4[] = {7,9,1,2,3};
    cout<<pivotElementRotatedArray(arr4, 5);

    // int arr5[] = {4,5,6,7,0,1,2};
    // cout<<searchRotatedSortedArray(arr5, 7, 5);

    // int arr6[] = {3,5,3,2,0};
    // cout<<peakMountain(arr6, 5);

    // cout<<squareRoot(50);
    // cout<<precisionSquareRoot(50, 6);

    // int arr7[] = {-6,-4,-3,0,2,3,5,7,10};
    // doubleExists(arr7, 9);

    // int arr8[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,14,15,16,17,18,19,20};
    // cout<<searchInArrayOfUnknownSize(arr8, 10);

}