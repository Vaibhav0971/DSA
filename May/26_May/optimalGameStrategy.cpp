#include<iostream>
#include<algorithm>

using namespace std;

int solve(int arr[], int i, int j){
    if(i>j) return 0;

    int choice1 = arr[i] + min(solve(arr, i+2, j), solve(arr, i+1, j-1));
    int choice2 = arr[j] + min(solve(arr, i, j-2), solve(arr, i+1, j-1));

    return max(choice1, choice2);
}

int main() {
    int arr[] = {20,30,2,2,2,10};
    cout<<solve(arr, 0, 5);    
}