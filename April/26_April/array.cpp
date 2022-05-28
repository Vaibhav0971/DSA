#include<iostream>
#include <unordered_map>
#include<map>
#include<stdlib.h>

using namespace std;

void findCommonElements(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3){
    // {1,2,3,4,5};
    // {3,4,8,9,10,11,12,13};
    // {2,4,5,6};
    int i=0, j=0, k=0;

    while(i < size1 && j < size2 && k < size3){
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
            cout<<arr1[i]<<endl;
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j]) i++;
        else if(arr2[j] < arr3[k]) j++;
        else k++;
    }
}

void firstRepeatingElement(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] == arr[j]){
                cout<<arr[i]<<endl;
                return;
            }
        }
    }
}

// Hash map approch
int firstRepeatingElement_2(int arr[], int size){
    unordered_map<int,int> count;
    
    for(int i=0; i<size; i++){
        int currentElement = arr[i];
        count[currentElement]++;
    }
    
    for(int i=0; i<size; i++){
        int currentElement = arr[i];
        if(count[currentElement] > 1){
            cout<<currentElement<<endl;
            return currentElement;
        }
    }

    return -1;
}

void firstNonRepeatingElement(int arr[], int size){
    bool repeated = false;
    for(int i=0; i<size; i++){
        repeated = false;
        for(int j=0; j<size; j++){
            cout<<arr[j]<<endl;
            if(arr[i] == arr[j] && j!=i){
                repeated = true;
            }
        }
        if(!repeated){
            cout<<arr[i]<<endl;
            return;
        }
    }
}

void subArrayWithEqual_0_and_1(int arr[], int size){
    int zeroCount = 0, oneCount = 0;

    for(int i=0; i<size; i++){
        if(arr[i]) oneCount++;
        else zeroCount++;
    }

    int window = size - abs(oneCount-zeroCount);
    if(window == size) {
        cout<<"0 to "<<size;
        return;
    }

// { 1, 0, 0, 1, 0, 1,| 1 }
    oneCount = 0;
    zeroCount = 0;
    for(int i=0; i<window; i++){
        if(arr[i]) oneCount++;
        else zeroCount++;
    }
    if(oneCount == zeroCount) {
        cout<<"0 to "<<window;
        return;
    }

    for(int i=1, j=window; i<size; i++, j++){
        if(arr[i-1]) oneCount--;
    }
}

void zeroSumSubArray(int arr[], int size){
    int ans = INT_MIN;
    int ansTillNow = 0;

    for(int i=0; i<size; i++){
        ansTillNow += arr[i];

        if(ans < ansTillNow){
            ans = ansTillNow;
            if(ans = 0){
                cout<<ans<<endl;
                return;
            }
        } 

        if(ansTillNow < 0) ansTillNow = 0;
    }

    cout<<ans;
}

int multiply(int num, int arr[], int arr_size){
    int carry = 0;
    for(int i=0; i<arr_size; i++){
        int ans = arr[i] * num + carry;
        arr[i] = ans%10;
        carry=ans/10;
    }
    while(carry){
        arr[arr_size] = carry % 10;
        carry = carry/10;
        arr_size++;
    }
    return arr_size;
}

void factorial(int num){
    int MAX=500;
    int ans[MAX];
    int ans_size=1;

    for(int i=2; i<=num; i++){
        ans_size = multiply(i, ans, ans_size);
    }

    for(int i=ans_size-1; i>=0; i--){
        cout<<ans[i];
    }    
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int * swapArrayElements(int arr[], int firstEl, int secondEl){
    int buffer = arr[firstEl];
    arr[firstEl] = arr[secondEl];
    arr[secondEl] = buffer;
    return arr;
}

int * sortArray(int arr[], int size){
    for(int i=0; i<size; i++){
        int min = arr[i];
        int minIndex = i;
        for(int j=i; j<size; j++){
            if(arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
        }
        swapArrayElements(arr, i, minIndex);
    }
    return arr;
}

int minimumPlatform(int arrival[], int arrSize, int departure[], int depSize){
    int platformCount = 1, i=1, j=0, ans = 1;
    sortArray(arrival, arrSize);
    sortArray(departure, depSize);

    while(i < arrSize && j < arrSize){
        if(arrival[i] <= departure[j]){ 
            platformCount++;
            i++;
        }
        else if(arrival[i] > departure[j]){
            platformCount--;
            j++;
        }
        ans = max(ans, platformCount);
    }

    cout<<"Ans "<<ans<<endl;
    return ans;
}

int minimizeHeight(int arr[], int size, int k){
    int mini=INT_MAX, maxi=INT_MIN, ans;
    sortArray(arr, size);
    printArray(arr, size);

    mini = arr[0];
    maxi = arr[size-1];
    ans = maxi - mini;

    for(int i=1; i<size; i++){
        mini = min(arr[0]+k, arr[i]-k);
        maxi = max(arr[size-1]-k, arr[i-1]+k);
        ans = min(ans, maxi - mini);
    }
    
    cout<<ans<<endl;
    return ans;
}

int majorityElement(int arr[], int size) {             
    map<int, int> mp;
    
    int majority = size/2;
    int count=0, ans=-1;
    
    for(int i=0; i<size; i++){
        mp[arr[i]]++;
        
        if(mp[arr[i]] > majority && mp[arr[i]] > count){
            count = mp[arr[i]];
            ans=arr[i];
        }
    }
    
    return ans;      
}

bool isSubset(int a1[], int n, int a2[], int m) {
    map<int, int> mp;
    
    for(int i=0; i<n; i++) mp[a1[i]]++;
    
    for(int i=0; i<m; i++){
        if(mp[a2[i]] == 0) return false;
    }
    
    return true;
}

int main(){
    system("cls");

    // int arr1[5] = {1,2,3,4,5};
    // int arr2[8] = {3,4,8,9,10,11,12,13};
    // int arr3[4] = {2,4,5,6};
    // findCommonElements(arr1, 5, arr2, 8, arr3, 4);

    // int arr4[8] =  {1,0,3,4,5,6,3,4};
    // firstRepeatingElement(arr4, 8);
    // firstRepeatingElement_2(arr4, 8);
    // firstNonRepeatingElement(arr4, 8);

    // int arr5[] = { 1, 0, 0, 1, 0, 1, 1 };
    // subArrayWithEqual_0_and_1(arr5, 7);

    // int arr6[8] = {1,1,2,-3,5,1,-4,-1};
    // zeroSumSubArray(arr6, 8);

    // cout<<factorial(10);

    // int arrival[] = { 900, 940, 950, 1100, 1500, 1800 };
    // int departure[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    // minimumPlatform(arrival, 6, departure, 6);

    // int arrHeight[] = {1, 5, 8, 10};
    // minimizeHeight(arrHeight, 4, 2);

    // int arr7[] = {2,2,1,1,1,2,2};
    // cout<<majorityElement(arr7, 7);

    // int arr8[] = {11, 1, 13, 21, 3, 7};
    // int arr9[] = {11, 3, 7, 1};
    // cout<<isSubset(arr8, 6, arr9, 4);

}
