#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

bool isPossible(int pages[], int size, int student, int mid){
    int studentCount = 1;
    int pagesAlloted = 0;
    
    for(int i=0; i<size; i++){
        if(pages[i]>mid) return false;

        if(pages[i]+pagesAlloted > mid){
            studentCount++;
            pagesAlloted = pages[i];
            if(studentCount>student) return false;
        }  
        else{
            pagesAlloted += pages[i];
        }   
    }
    return true;
}

int findPages(int pages[], int size, int student){
    if(size<student) return -1;

    int start = 0, ans = -1, end =0;
    for(int i=0; i<size; i++) end += pages[i];
    int mid = end/2;

    while(start<=end){
        if(isPossible(pages, size, student, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;    
}

int main(){
    system("cls");
    int pages[] = {13,31,37,45,46,54,55,63,73,84,85};
    int n = 11;
    int student = 9;

    cout<<findPages(pages, n, student);
}