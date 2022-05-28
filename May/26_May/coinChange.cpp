#include<iostream>

using namespace std;

int possibleWays(int coin[], int size, int amount, int currentCoin){
    if(amount==0) return 1;
    if(amount<0) return 0;

    int ans=0;
    for(int i=currentCoin; i<size; i++){
        ans+=possibleWays(coin, size, amount-coin[i], i);
    }

    return ans;
}

int main() {
    int coin[] = {1,2};
    int amount = 4;
    cout<<possibleWays(coin, 2, amount, 0);
    
}