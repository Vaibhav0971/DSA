#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

bool isPossible(int positions[], int size, int aggCows, int mid){   
    int cowCount=1;
    int lastPos = positions[0]; 

    for(int i=0; i<size; i++){
        if(positions[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==aggCows) return true;
            lastPos = positions[i];
        }
    }
    return false;
}

long long maxDistance(int positions[], int size, int aggCows){
    sort(positions, positions+size);
    int start=0, ans=-1, end=positions[size-1];
    int mid = end/2;

    while(start<=end){
        if(isPossible(positions, size, aggCows, mid)){
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
    int positions[] = {1,2,8,4,9};
    int n = 5;
    int aggCows = 3;

    cout<<maxDistance(positions, n, aggCows);
}