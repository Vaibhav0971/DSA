#include<bits/stdc++.h>

using namespace std;

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

    cout<<getFibbo(7);
}