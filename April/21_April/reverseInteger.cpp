#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

// 1st Approach
int reverse(int num){
    int ans = 0;
    
    while(num != 0){
        int digit = num % 10;
        if(ans < (INT_MIN/10)) return 0;
        if((ans * 10) > INT_MAX) return 0;
        ans = (ans *10) + digit;
        num /= 10;
    }
    
    return ans;
}

int main(){
    system("cls");
    cout<<reverse(214748364);
}