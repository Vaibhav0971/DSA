#include<iostream>
#include<stdlib.h>
using namespace std;

int findComplement(int num){
    int mask = 0;

    while(mask < num){
        mask = (mask<<1) | 1;
    }
    int ans = (~num) & mask;
    return ans;
}

int main(){
    system("cls");
    cout<<findComplement(5);
}