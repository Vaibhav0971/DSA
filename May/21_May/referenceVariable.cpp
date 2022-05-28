#include<iostream>

using namespace std;

inline int func(){
    return 4*5;
}

int main() {

    int i=5;
    int &j = i;

    // cout<<i<<endl;
    // i++;
    // cout<<j<<endl;
    // j++;
    // cout<<i<<endl;

    // ARRAY
    // int *arr = new int[5];
    // for(int i=0; i<5; i++){
    //     cin>>arr[i];
    // }
    // for(int i=0; i<5; i++){
    //     cout<<arr[i];
    // }

    // 2D ARRAY
    // int r=0, c=0;
    // cin>>r>>c;

    // int **arr = new int *[r];   //create 2d array
    // cout<<endl;

    // for(int i=0; i<r; i++){
    //     arr[i] = new int [c];
    //     for(int j=0; j<c; j++){
    //         cin>>arr[i][j]; //taking input
    //     }
    // }

    // cout<<endl;

    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout<<arr[i][j]<<" ";   // show output
    //     }
    //     cout<<endl;
    // }

    // for(int i=0; i<r; i++){
    //     delete []arr[i];    // delete and clear heap
    // }
    // delete arr;

    // INLINE FUNCTION
    // cout<<func();


}