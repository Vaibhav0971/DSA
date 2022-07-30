#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int celebrity(vector<vector<int> >& M, int n){
    if(M.size() == 0 || n == 1) return -1;
    
    stack<int> st;
    for(int i=0; i<n; i++){
        st.push(i);
    }
    
    //find possible candidate for celebrity
    while(st.size() > 1){
        int temp1 = st.top();
        st.pop();
        int temp2 = st.top();
        st.pop();
        
        if(M[temp1][temp2]) st.push(temp2);
        else st.push(temp1);
    }
    
    int candidate = st.top();
    
    // verification
    // checking row
    int checkRow = true;
    for(int i=0; i<n; i++){
        if(M[candidate][i]){
            checkRow = false;
            break;
        }
    }
    
    // checking col
    int checkCol = true;
    for(int i=0; i<n; i++){
        if(i != candidate && M[i][candidate] == 0){
            checkCol = false;
            break;
        }
    }
    
    return (checkRow && checkCol) ? candidate : -1;
}

int main(){
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout<<celebrity(arr, 3);
}