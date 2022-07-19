#include<iostream>

using namespace std;

bool isValid(int n){
    int arr[7] = {0};
    
    while(n > 0){
        if(n % 10 == 0 || n % 10 > 6) return false;
        arr[n%10]++;
        n/=10;
    }
    
    for(int i=1; i<=6; i++){
        if(arr[i] != 0 && arr[i] != i) return false;
    }
    
    return true;
}

int nextBeautifulNumber(int n) {
    while(1){
        n++;
        if(isValid(n)) return n;
    } 
    
    return 0;
}

int main(){
    cout<<nextBeautifulNumber(1000);
}