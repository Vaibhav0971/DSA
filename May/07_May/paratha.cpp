#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

using namespace std;

int numberOfParathas(int a,int time){
    int d = sqrt(a*a + 8*a*time);
    d-=a;
    return d / (2*a);
}

bool isPossibleSolution(int arr[], int size, int target, int mid){
    int count = 0;
    for(int i=0; i<size; i++){
        // count += numberOfParathas(arr[i], mid); 

        // 👇 Both of them are correct, use only one 👆

        int time=arr[i], j=2;
        while(time<=mid){
            count++;
            time += arr[i]*j;
            j++;
        }
    }
    return count>=target;
}

int maxTime(int n, int m){
    return n*m*(m+1)/2;
}

int totalTime(int arr[], int n, int target){
    // sort(arr, arr+n);
    int start = 0, end = maxTime(arr[0], target), mid = start + (end-start)/2;

    int ans = -1;
    
    while (start<=end){
        if(isPossibleSolution(arr, n, target, mid)){
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
    int cookRank[] = {1,2,3,4};
    int n = 4;
    int target = 10;

    cout<<totalTime(cookRank, n, target);
}