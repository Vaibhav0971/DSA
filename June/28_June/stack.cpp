#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void printStack(stack<int>& st){
    if(st.empty()) return;

    int temp = st.top();
    cout<<temp<<", ";
    st.pop();
    printStack(st);
    st.push(temp);
}

void insertSorted(stack<int>& st, int data){
    if(st.empty() || st.top() < data) {
        st.push(data);
        return;
    }

    int temp = st.top();
    st.pop();

    insertSorted(st, data);

    st.push(temp);
}

void sortStack(stack<int>& st){
    if(st.empty()) return;

    int temp = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, temp);
}

bool findRedundantBrackets(string &s){
    stack<char> st;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            bool valid = false;
            while(!st.empty()){
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                    valid = true;
                }
                else if(st.top() == '('){
                    st.pop();
                    break;
                }
                st.pop();
            }
            if(!valid) return true;
        }
    }
    return false;
}

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans(n);
    
    st.push(-1);
    
    for(int i=n-1; i>=0; i--){
        while(arr[i] <= st.top()){
            st.pop();
        }
        ans[i] = st.top();  
        st.push(arr[i]);
    }    
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans(n);
    
    st.push(-1);
    
    for(int i=0; i<n; i--){
        while(arr[i] <= st.top()){
            st.pop();
        }
        ans[i] = st.top();  
        st.push(arr[i]);
    }    
    return ans;
}

int main(){
    // stack<int> st;

    // st.push(2);
    // st.push(4);
    // st.push(1);
    // st.push(3);

    // printStack(st);
    // cout<<endl;
    // sortStack(st);
    // printStack(st);

    

    // string s = "(a+b)";
    // cout<<"\nIs Redundant - "<<(findRedundantBrackets(s) ? "Yes" : "No");

}