#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

void solve(string str, string output, map<int, bool> mp, set<string>& ans){
    for(int i=0; i<str.length(); i++){
        if(!mp[i]){
            output.push_back(str[i]);
            mp[i] = true;
            ans.insert(output);
            solve(str, output, mp, ans);
            output.pop_back();
            mp[i] = false;
        }
    }
}

int numTilePossibilities(string str){
    set<string> ans;
    string output = "";
    map<int, bool> mp;

    solve(str, output, mp, ans);

    for(auto s : ans){
        cout<<s<<", ";
    }
    cout<<endl;

    return ans.size();
}

int main(){
    cout<<numTilePossibilities("AAB");
}