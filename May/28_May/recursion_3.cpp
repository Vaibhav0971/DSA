#include<iostream>

using namespace std;

string powerSet(string s, int index, string output){
    if(index == s.length()){
        cout<<output<<endl;
        return output;
    }

    // exclude space
    powerSet(s, index+1, output);
    // include space
    output.push_back(s[index]);
    powerSet(s, index+1, output);

    return output;
}

int main(){
    string s = "abc";
    powerSet(s, 0, "");
}