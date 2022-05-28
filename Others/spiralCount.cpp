#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter any Number : ";
    cin>>n;
    int count = n;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            if(j<i)
                cout<<count--<<" ";
            else if(j> 2*(n-1)-i)
                cout<<++count<<" ";
            else
                cout<<n-i<<" ";
        }
        cout<<endl;
    }

    for (int i = n-2; i >= 0 ; i--) 
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            if(j<i)
                cout<<count--<<" ";
            else if(j> 2*(n-1)-i)
                cout<<++count<<" ";
            else
                cout<<n-i<<" ";
        }
        cout<<endl;
    }
}