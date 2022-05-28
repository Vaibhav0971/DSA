#include<iostream>
#include<vector>

using namespace std;

int coe(int n){
    int count = 0;
    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++){
        if(prime[i]){
            count++;
            for(int j=2*i; j<=n; j=j+i){
                prime[j] = false;
            }
        }
    }

    return count;
}

int main(){
    int n = 30; 
    cout<<"Number of prime is "<<coe(n)<<endl;
}