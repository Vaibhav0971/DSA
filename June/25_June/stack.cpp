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

int findElement(stack<int>& st, int index){
    if(st.size() == index) return st.top();

    int temp = st.top();
    st.pop();
    int ans = findElement(st, index);
    st.push(temp);
    return ans;
}

void insertAtBottom(stack<int>& st, int el){
    if(st.size() == 0){ 
        st.push(el);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtBottom(st, el);
    st.push(temp);
}

void reverse(stack<int>& st){
    if(st.size() == 0) return;

    int temp = st.top();
    st.pop();

    reverse(st);
    insertAtBottom(st, temp);
}

int main(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    // cout<<findElement(st, 4);
    printStack(st);
    cout<<endl;

    reverse(st);    
    printStack(st);

}