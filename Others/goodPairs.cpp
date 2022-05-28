#include<bits/stdc++.h>

using namespace std;

int findGoodPairs(int arr1[], int size1, int arr2[], int size2){
    map<pair<int, int>,int> mpp;

    int counter = 0;
    for(int i=0; i<size1; i++){
        counter += mpp[{arr1[i], arr2[i]}];
        mpp[{arr2[i], arr1[i]}]++;
    }
    return counter;
}

int main(){
    system("cls");

    int arr1[] = {4,8,1,1};
    int arr2[] = {8,4,1,1};

    cout<<findGoodPairs(arr1, 4, arr2, 4);
}