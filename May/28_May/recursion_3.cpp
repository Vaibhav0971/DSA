#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;


void solve2(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
    if(index >= nums.size()){
        return;
    }

    for(int i=index; i<nums.size(); i++){
        output.push_back(nums[i]);
        ans.push_back(output);
        solve2(nums, output, i+1, ans);
        output.pop_back();
    }
}

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    
    //exclude
    solve(nums, output, index+1, ans);
    
    //include
    output.push_back(nums[index]);
    solve(nums, output, index+1, ans);
}

void powerSet(string s, int index, string output, vector<string>& ans){
    if(index == s.length()){
        ans.push_back(output);
        return;
    }

    // exclude space
    powerSet(s, index+1, output, ans);
    // include space
    output.push_back(s[index]);
    powerSet(s, index+1, output, ans);
}

void findSequence(int leftSum, int rightSum, char* output, int i, int j){
    if(i > j){
        if(leftSum == rightSum) cout<<output<<endl;
        return;
    }

    // 0, 0
    output[i] = '0';
    output[j] = '0';
    findSequence(leftSum, rightSum, output, i+1, j-1);

    // 0, 1
    output[i] = '0';
    output[j] = '1';
    findSequence(leftSum, rightSum+1, output, i+1, j-1);

    // 1, 0
    output[i] = '1';
    output[j] = '0';
    findSequence(leftSum+1, rightSum, output, i+1, j-1);

    // 1, 1
    output[i] = '1';
    output[j] = '1';
    findSequence(leftSum+1, rightSum+1, output, i+1, j-1);
}

void keypad(string digits, int index, string mapping[], string output, vector<string>& ans){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }
    
    int number = digits[index] - '0';
    string value = mapping[number];
    
    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        keypad(digits, index+1, mapping, output, ans);
        output.pop_back();
    }
}    

void permutations(string str, int index, vector<string>& ans){
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }
    
    for(int i=index; i<str.length(); i++){
        swap(str[index], str[i]);
        permutations(str, index+1, ans);
        swap(str[index], str[i]);
    }
}

bool isSafe(int x, int y, int n, vector<vector<int>> &m, vector<vector<int>>& visited){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) return true;
    
    return false;
}

void ratInMaze(int x, int y, string path, int n, vector<vector<int>> &m, vector<vector<int>>& visited, vector<string>& ans){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    
    // move down
    int newX = x+1;
    int newY = y;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('D');
        ratInMaze(newX, newY, path, n, m, visited, ans);
        path.pop_back();
    }
    // move left
    newX = x;
    newY = y-1;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('L');
        ratInMaze(newX, newY, path, n, m, visited, ans);
        path.pop_back();
    }
    // move right
    newX = x;
    newY = y+1;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('R');
        ratInMaze(newX, newY, path, n, m, visited, ans);
        path.pop_back();
    }
    // move up
    newX = x-1;
    newY = y;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('U');
        ratInMaze(newX, newY, path, n, m, visited, ans);
        path.pop_back();
    }
    
    visited[x][y] = 0;
}

void subset(vector<int> set, int index, int output, vector<int>& ans){
    if(index >= set.size()){
        return;
    }

    for(int i=index; i<set.size(); i++){
        output += set[i];
        ans.push_back(output);
        subset(set, i+1, output, ans);
        output -= set[i];
    }
}
     
int Kth_SymbolInGrammer(int n, int k){
    if(n == 1) return 0;
    
    int mid = pow(2, n-1)/2;
    
    if(k <= mid){
        return Kth_SymbolInGrammer(n-1, k);
    }
    else{
        return !Kth_SymbolInGrammer(n-1, k-mid);
    }
}

int main(){

    // int n=5, k=5;
    // cout<<Kth_SymbolInGrammer(n, k);

    // vector<int> ans;
    // int output = 0;
    // int sum = 30;
    // vector<int> set = {3, 34, 4, 12, 5, 2};

    // subset(set, 0 , output, ans);

    // for(int i=0; i<ans.size(); i++){
    //     cout<<ans[i]<<", ";
    // }
    // cout<<endl;
    // for(int i=0; i<ans.size(); i++){
    //     if(ans[i] == sum){
    //         cout<<"TRUE";
    //         break;
    //     }
    // }
    // cout<<endl;


    //***********************************************

    // vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    // int n = 4;
    // vector<string> ans;
    
    // vector<vector<int>> visited = m ;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         visited[i][j] = 0;
    //     }
    // }
    
    // int srcX = 0;
    // int srcY = 0;
    // string moves = "";
    
    // ratInMaze(srcX, srcY, moves, n, m, visited, ans);
    // sort(ans.begin(), ans.end());
    // for(int i=0; i<ans.size(); i++){
    //     cout<<ans[i]<<", ";
    // }
    // cout<<endl;

    //***********************************************

    // string str = "abc";
    // vector<string> ans;
    // int index = 0;
    // permutations(str, index, ans);
    
    // for(int i=0; i<ans.size(); i++){
    //     cout<<ans[i]<<", ";
    // }
    // cout<<endl;

    //***********************************************

    // string digits = "23";
    // vector<string> ans;
    
    // string output = "";
    // string maping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // int index = 0;
    // keypad(digits, index, maping, output, ans);

    //***********************************************

    // int n = 1;
    // char arr[2*n];
    // findSequence(0, 0, arr, 0, 2*n-1);

    //***********************************************

    // string s = "mjm";
    // vector<string> arr;
    // powerSet(s, 0, "", arr);

    // cout<<endl;
    // for(int i=0; i<arr.size(); i++){
    //     cout<<arr[i]<<endl;
    // }
    // cout<<endl;

    //***********************************************

    // vector<int> nums = {1,2,3};
    // vector<vector<int>> ans;
    // vector<int> output;
    // int index = 0; 
    // solve(nums, output, index, ans);  

    // for(int i=0; i<ans.size(); i++){
    //     cout<<" {";
    //     for(int j=0; j<ans[i].size(); j++){
    //         cout<<ans[i][j];
    //     }
    //     cout<<"},";
    // }
    // cout<<endl;
}