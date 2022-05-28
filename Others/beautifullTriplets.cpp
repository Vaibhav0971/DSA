#include<bits/stdc++.h>

using namespace std;

int findGoodPairs(int arr[], int size, int d){
    unordered_map<int, int> m;
    int cnt = 0;
    for (int i=0; i<size; i++) {
        int a = arr[i];
        m[a] += 1;
        cnt += m[a-d]*m[a-2*d];
    }
    return cnt;
}

int main(){
    system("cls");

    int arr[] = {1,2,4,5,7,8,10};

    cout<<findGoodPairs(arr, 7, 3);
}