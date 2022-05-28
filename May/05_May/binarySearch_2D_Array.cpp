#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

bool findElementIn2DArray(vector<vector<int>>& matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();
    
    int start = 0, end = row*col-1, mid = end/2;
    
    while(start<=end){
        int element = matrix[mid/col][mid%col];

        if(target == element) return true;
        else if(target > element) start = mid + 1;
        else if(target <= element) end = mid - 1;
        
        mid = start + (end-start)/2;
    }
    
    return false;
}

int main(){
    system("cls");
    vector<vector<int>> arr = {{1,5,9}, {14,20,23}, {30,34,43}};

    cout<<findElementIn2DArray(arr, 23);
}