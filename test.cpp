#include<bits/stdc++.h>

using namespace std;

int kingdomToAttack(int troops, vector<int> &arr){
    if(arr.size() <= 0) return -1;
    
    int ans = -1;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= troops && arr[i] != -1){
            ans = i;
        }
    }
    
    if(ans != -1) arr[ans] = -1;
    
    return ans;
}

int solve(vector<int> &A) {
    int size = A.size();
    sort(A.begin(), A.end());
    
    int everyDayTroops = 1;
    int dayCount = 1;
    int incrementor = 1;
    
    while(size > 0){
        int nextAttack = kingdomToAttack(everyDayTroops, A);

        
        cout<<"ATK-> "<<nextAttack<<"  D-> "<<dayCount<<"  T-> "<<everyDayTroops<<"  I-> "<<incrementor<<endl;
        
        if(nextAttack != -1){
            size--;
            incrementor++;
            everyDayTroops = incrementor;
        }
        else{
            everyDayTroops += incrementor;
        }
        dayCount++;
    }
    
    return dayCount-1;
}

void reverse(string& str){
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

bool removeDub(string& str){
    map<char, int>mp;
    
    for(int i=0; i<str.length(); i++) mp[str[i]]++;
    
    for(auto i=mp.begin(); i!=mp.end(); i++){
        if(i->second > 1){
            int pos = str.find(i->first);
            cout<<pos;
            str.replace(pos, 1, "");
            return true;
        }
    }
    
    return false;
}

string removeReverse(string S) {
    while(removeDub(S)){
        cout<<endl;
        cout<<S;
        reverse(S);
        cout<<S;
    }
    return S;
}

int getFibbo(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    return getFibbo(n-1)+getFibbo(n-2);
}

int main(){
    // string str = "abab";
    // removeReverse(str);
    // cout<<str;

    // cout<<getFibbo(7);

    
    vector<int> arr = {1,1,1,5,9,8};
    cout<<solve(arr);
}