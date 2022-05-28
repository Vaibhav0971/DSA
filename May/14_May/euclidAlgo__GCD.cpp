#include<iostream>
#include<vector>

using namespace std;

int gcd(int n, int m){
    if(n == 0) return m;
    if(m == 0) return n;

    while(n!=m){
        if(n>m) n-=m;
        else m-=n;
    }
    return m;
}

int main(){
    int n = 12; 
    int m = 8;
    cout<<"GCD is "<<gcd(n, m)<<endl;
}