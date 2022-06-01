#include<iostream>

using namespace std;

int factorial(int num){
    if(num == 1) return 1;
    return num*factorial(num-1);
}

void counting(int num){
    if(num==0) return;
    counting(num-1);
    cout<<num<<endl;
}

int fibonacci(int num){
    if (num <= 1) return num;
    return fibonacci(num-1) + fibonacci(num-2);   
}

int maxNumber(int arr[], int size){
    if(size == 0) return arr[size];

    int n = maxNumber(arr, size-1);

    return max(arr[size], n);
}

int searchNumber(int arr[], int size, int target){
    if(size == 0) return 0;

    int n = searchNumber(arr, size-1, target);

    if(arr[n] == target) return n;
    return size;
}

int fastExpo(int num){
    if(num==0) return 1;

    int n = fastExpo(num/2);
    if(num&1) return n*n*2;    
    return n*n;
}

void reverse(string& s, int i,int j){
    if(i>j){
        return ;
    }
    swap(s[i],s[j]);
    reverse(s,i+1,j-1); //working
    // reverse(s, i++, j--); //not working getting segmentation fault error
}

bool isSorted(int arr[], int size){
    if(size == 0 || size == 1) return true;
    bool ans;
    
    if(arr[0] > arr[1]) return false;
    else ans = isSorted(arr+1, size-1);

    return ans;
}

int sum(int arr[], int size){
    if(size == 0) return 0;
    if(size == 1) return arr[0];

    return arr[size] + sum(arr, size-1);
}

bool linearSearch(int arr[], int size, int target){
    if(size == 0) return false;

    if(target == arr[size-1]) return true;

    bool ans = linearSearch(arr, size-1, target);

    if(ans) return true;
    return false;
}

bool binarySearch(int arr[], int target, int s, int e){
    if(s>e) return false;

    int mid = s + (e-s)/2;
    if(arr[mid] == target) return true;

    if(target > arr[mid]) return binarySearch(arr, target, mid+1, e);
    else return binarySearch(arr, target, s, mid-1);
}

string reverseString(string str, int i){
    if(i == str.length()) return "";

    string ans =  reverseString(str, i-1);
    ans.push_back(str[i]);
    return ans;
}

int reverseNumber(int num){
    if(num == 0) return 0;

    int digit = 0;
    digit = num % 10;
    num /= 10;

    int ans = reverseNumber(num);

    return ans * 10 + digit;    
}

int main() {

    // cout<<factorial(5);
    // counting(5);
    // cout<<fibonacci(5);

    // int arr[] = {4,2,6,9,1,0,12};
    // cout<<maxNumber(arr, 7);
    // cout<<searchNumber(arr, 7, 0);

    // cout<<fastExpo(11);

    // string name = "Vaibhav";
    // string *s = &name;
    // reverse(name, 0, name.length()-1);
    // cout<<name;

    // int arr2[] = {4,2,6,9,1,0,12};
    // cout<<isSorted(arr2, 7);
    // cout<<sum(arr2, 7);
    // cout<<linearSearch(arr2, 7, 0);

    // int arr3[] = {1,2,3,4,5,6,7,8,9};
    // cout<<binarySearch(arr3, 90, 0, 6);

    // cout<<reverseString("qwer", 0);
    cout<<reverseNumber(123);
}