#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

using namespace std;

bool isPossible(int boards[], int size, int painters, long mid){
    int painterCount = 1;
    int allotedArea = 0;
    
    for(int i=0; i<size; i++){
        if(boards[i]>mid) return false;

        if(boards[i]+allotedArea > mid){
            painterCount++;
            allotedArea = boards[i];
            if(painterCount>painters) return false;
        }  
        else{
            allotedArea += boards[i];
        }   
    }
    return true;
}

long long minTime(int boards[], int size, int painters){
    long start=0, ans=-1, end=0;
    for(int i=0; i<size; i++) end += boards[i];
    long mid = end/2;

    while(start<=end){
        if(isPossible(boards, size, painters, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;    
}

int main(){
    system("cls");
    int boards[] = {5, 10, 30, 20, 15};
    int n = 5;
    int painters = 3;

    cout<<minTime(boards, n, painters);
}