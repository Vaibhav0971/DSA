#include<iostream>
#include<stdlib.h>

using namespace std;

void printNumber(int n){
    cout<<"Printing Number "<<n<<endl;
}

void printEvenNumber(int n){
    for(int i=2; i<=n; i+=2){
        cout<<i<<endl;
    }
}

void printAllSquare(int n){
    for(int i=1; i<=n; i++){
        cout<<i*i<<endl;
    }
}

int factorial(int n){
    int output = 1;
    for(int i=1; i<=n; i++){
        output *= i;
    }
    return output;
}

void printNameNTimes(int n){
    for(int i=1; i<=n; i++){
        cout<<"Vaibhav Sharma"<<endl;
    }
}

void fibonachi(int num){
    int first = -1, second = 1;

    for(int i=0; i<num; i++){
        cout<<first + second<<", ";
        int temp = second;
        second = first + second;
        first = temp;
    }
}

int main(){
    system("cls");
    // printNumber(2);
    // printEvenNumber(4);
    // printAllSquare(6);
    // cout<<factorial(10);
    // printNameNTimes(10);
    // fibonachi(8);
}