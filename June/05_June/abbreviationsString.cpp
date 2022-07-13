#include<iostream>
#include<vector>

using namespace std;

void solve(int index, string str, string output, vector<string>& ans){
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }

    // exclude
    int count = 1; 
    if (!output.empty() && isdigit(output.back())) {
        count += (int)(output.back() - '0');
        output.pop_back();
    }
    output.push_back((char)(count + '0'));
    solve(index+1, str, output, ans);
    output.pop_back();

    // include
    output.push_back(str[index]);
    solve(index+1, str, output, ans);
    output.pop_back();
}

int main(){
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(index, "ANKS", output, ans);

    for(auto i : ans){
        cout<<i<<", ";
    }
    cout<<endl;
}