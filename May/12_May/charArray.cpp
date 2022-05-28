#include<iostream>
#include<cstring>
// #include<stdio.h>

using namespace std;

int getLength(char arr[]){
    int index=0;
    while(arr[index] != '\0'){
        index++;
    }
    return index;
}

void reverse(char arr[]){
    int len = strlen(arr);
    int s=0, e=len-1;
    while(s<e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main(){
    // system("cls");
    // char arr[10] = "babbar";
    // char arr1[10] = "babbar";

    // cout<<getLength(arr)<<endl;
    // cout<<strlen(arr)<<endl;
    // cout<<strcmp(arr, arr1)<<endl;

    char arr2[5] = "LOVE";
    reverse(arr2);
    cout<<arr2<<endl;

}