#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> prevIndex(vector<int>& arr){
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);
    
    for(int i=0; i<arr.size(); i++){
        while(st.top() != -1 && arr[i] <= arr[st.top()]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextIndex(vector<int>& arr){
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);
    
    for(int i=arr.size()-1; i>=0; i--){
        while(st.top() != -1 && arr[i] <= arr[st.top()]){
            st.pop();
        }
        if(st.top() == -1) ans[i] = arr.size();
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> prev = prevIndex(heights);
    vector<int> next = nextIndex(heights);
    
    int maxArea = INT_MIN;
    for(int i=0; i<heights.size(); i++){
        int height = heights[i];
        int width = next[i] - prev[i] - 1;
        
        int area = width * height;
        maxArea = max(area, maxArea);
    }
    
    return maxArea;
}

int main(){
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout<<largestRectangleArea(arr);
}