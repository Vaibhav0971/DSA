#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

bool isPossibleSolution(int arr[], int size, int m, int mid){
    int ans = 0;
    for(int i=0; i<size; i++){
        if(arr[i]>mid) ans += arr[i] - mid;
    }
    return ans>=m;
}

int getMaxHeightOfSaw(int arr[], int n, int m){
    sort(arr, arr+n);
    int start = 0, end = arr[n-1], mid = start + (end-start)/2;

    int ans = -1;
    
    while (start<=end){
        if(isPossibleSolution(arr, n, m, mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    } 
    return ans;
}

int main(){
    system("cls");
    int treeHeight[] = {20, 15, 10, 17};
    int n = 4;
    int target = 7;

    cout<<getMaxHeightOfSaw(treeHeight, n, target);
}