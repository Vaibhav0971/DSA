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

int main() {

    // cout<<factorial(5);
    // counting(5);
    // cout<<fibonacci(5);

    // int arr[] = {4,2,6,9,1,0,12};
    // cout<<maxNumber(arr, 7);
    // cout<<searchNumber(arr, 7, 0);

    // cout<<fastExpo(11);

    string name = "Vaibhav";
    string *s = &name;
    reverse(name, 0, name.length()-1);
    cout<<name;

}