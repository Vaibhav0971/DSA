#include<iostream>
#include<stdlib.h>
using namespace std;

void getBinary(int num){
    while(num != 0){
        cout<<(num & 1);
        num = num>>1;
    }
}

void getDecimal(int num){
    
}

int main(){
    system("cls");
    getBinary(10);
    getDecimal(10);
}