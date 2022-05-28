#include<iostream>
#include<stdlib.h>

using namespace std;

void takeInput(int arr[3][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
}

void print2D_Array(int arr[4][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool searchIn2D_Array(int arr[3][3], int row, int col, int target){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == target){
                cout<<arr[i][j]<<" Yes it is present in 2D array"<<endl;
                return true;
            }
        }
    }
    return false;
}

void columnViseSum(int arr[3][4], int row, int col){
    int output[col] = {0};
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            output[j] = output[j] + arr[i][j];
        }
    }
    cout<<"Printing sum of columns "<<endl;
    int largest = INT_MIN;
    for(int i=0; i<col; i++){
        cout<<output[i]<<" ";
        if(largest<output[i]){
            largest = output[i];
        }
    }
    cout<<endl<<"The largest column sum is "<<largest<<endl;
}

void transpose(int arr[3][3], int row, int col){
    int output[row][col] = {0};
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
           output[i][j] = arr[j][i];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotate90Deg(int arr[3][3], int row, int col){
    int output[row][col] = {0};
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
           output[i][col-j-1] = arr[j][i];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void spiralPrint(int arr[4][4], int row, int col){
    int startRow = 0, startCol = 0, endRow = row-1, endCol = col-1, loop = row * col;

    while(loop>0){
        for(int i=startCol; i<=endCol; i++){
            cout<<arr[startRow][i]<<" ";
            loop--;
        }
        startRow++;
        for(int i=startRow; i<=endRow; i++){
            cout<<arr[i][endCol]<<" ";
            loop--;
        }
        endCol--;
        for(int i=endCol; i>=startCol; i--){
            cout<<arr[endRow][i]<<" ";
            loop--;
        }
        endRow--;
        for(int i=endRow; i>=startRow; i--){
            cout<<arr[i][startCol]<<" ";
            loop--;
        }
        startCol++;
    } 

    cout<<endl;
}

void wavePrint(int arr[4][4], int row, int col){
    int currRow = 1, loop = row * col;

    while(loop>0){
        if(currRow%2 == 0){
            for(int i=col-1; i>=0; i--){
                cout<<arr[currRow-1][i]<<" ";
                loop--;
            }
        }
        else{
            for(int i=0; i<col; i++){
                cout<<arr[currRow-1][i]<<" ";
                loop--;
            }
        }
        currRow++;
    } 

    cout<<endl;
}

int main(){
    system("cls");

    // Initialize with 0
    // int arr[3][3] = {0};
    
    // First element 1 rest 0
    // int arr[3][3] = {1};

    // Initializing like 1D array
    // int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    
    // Initializing 2D array row wise
    // int arr[4][2] = {{1,2}, {3,4}, {5,6}, {7,8}};
    
    // Initializing 2D array row wise but not giving all values
    // int arr[3][3] = {{1,2,3}, {3,4,5}, {5,6,8}};

    // int arr[3][3] = {5,1,3,4,6,7,0,9,2};
    // print2D_Array(arr, 3,3);



    // cout<<searchIn2D_Array(arr, 3, 3, 5);
    // int arr1[3][4] = {3,5,11,2,7,9,8,0,5,0,1,3};
    // columnViseSum(arr1, 3, 4);
    // transpose(arr, 3, 3);
    // rotate90Deg(arr, 3, 3);

    int arr2[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    print2D_Array(arr2, 4, 4);

//     spiralPrint(arr2, 4, 4);
    // wavePrint(arr2, 4, 4);
}