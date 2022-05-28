#include<iostream>
#include<stdlib.h>
using namespace std;

// 1st Approach
bool isPowerOfTwo_1(int num){
    if(num <= 0) return false;

    int count = 0;
    while(num > 0){
        if(num & 1){ 
            count++;
            if(count>1) return false;
        }
        num = num>>1;
    }
    
    if(count == 1) return true;
    return false;
}

// 2st Approach
bool isPowerOfTwo_2(int num){
    if(num <= 0) return false;
    if((num&(num-1)) == 0) return true;
    return false;
}

int main(){
    system("cls");
    // cout<<isPowerOfTwo_1(8);
    cout<<isPowerOfTwo_2(8);
}