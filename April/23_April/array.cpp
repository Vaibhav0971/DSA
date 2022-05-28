#include<iostream>
#include<stdlib.h>
#include<map>

using namespace std;

void inputArray(int arr[], int size){
    cout<<"Enter the number of elements"<<endl;
    int n;
    cin>>n;
    if(n>size){
        cout<<"Exceeded the size of array";
        return;
    }
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<", ";
    }
}

bool linearSearch(int arr[], int size, int num){
    for(int i=0; i<size; i++){
        if(arr[i] == num) {
            cout<<"Element found";
            return true;
        }
    }
    cout<<"Element not found";
    return false;
}

int * reverseArray(int arr[], int size){
    for(int i=0; i<size/2; i++){
        int buffer = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = buffer;
    }
    return arr;
}

int minMax(int arr[], int size){
    int min, max = arr[0];
    for(int i=0; i<size; i++){
        if(arr[i]<min) min = arr[i];
        if(arr[i]>max) max = arr[i];
    }
    cout<<"Min element "<<min<<endl;
    cout<<"Max element "<<max<<endl;
    return min, max;
}

int * swapAdjacent(int arr[], int size){
    for(int i=0; i<size; i+=2){
        int buffer = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = buffer;
    }
    return arr;
}

int * swapAlternate(int arr[], int size){
    for(int i=0; i<size; i+=4){
        int buffer;
        if(i<size && (i+2)<size){
            buffer = arr[i];
            arr[i] = arr[i+2];
            arr[i+2] = buffer;
        }
        if(i+1<size && (i+1+2)<size){
            buffer = arr[i+1];
            arr[i+1] = arr[i+1+2];
            arr[i+1+2] = buffer;
        }
    }
    return arr;
}

int * swapNthElement(int arr[], int size, int swap){
    if(swap <= 1) return arr;

    for(int i=0; i<size; i+=swap+swap-2){
        int buffer;
        for(int j=0; j<swap-1; j++){
            if(i+j<size && (i+j+swap-1)<size){
                buffer = arr[i+j];
                arr[i+j] = arr[i+j+swap-1];
                arr[i+j+swap-1] = buffer;
            }
            else return arr;
        }
    }
    return arr;
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

int * negativeToSide(int arr[], int size){
    int j=0;
    for(int i=0; i<size; i++){
        if(arr[i]<0){
            swapArrayElements(arr, i, j++);
        }
    }
    return arr;
}

void arrayUnion(int arr1[], int size1, int arr2[], int size2){
    int i = 0, j = 0;

    while(size1 > i && size2 > j){
        if(arr1[i] < arr2[j])
            cout<<arr1[i++]<<", ";
        else if(arr1[i] > arr2[j])
            cout<<arr2[j++]<<", ";
        else {
            cout<<arr2[j++]<<", ";
            i++;
        }
    }
 
    while (i < size1)
        cout<<arr1[i++]<<", ";
 
    while (j < size2)
        cout<<arr2[j++]<<", ";
}

void arrayIntersection(int arr1[], int size1, int arr2[], int size2){
    int i = 0, j = 0;

    while(size1 > i && size2 > j){
        if(arr1[i] < arr2[j])
            i++;
        else if(arr1[i] > arr2[j])
            j++;
        else {
            cout<<arr2[j++]<<", ";
            i++;
        }
    }
}

int * cyclicallyRotateArray(int arr[], int size, int cycleCount){
    if(cycleCount == 0) return arr;

    int LastElement = arr[size-1];

    for(int i=size-1; i>=0; i--){
        swapArrayElements(arr, i-1, i);
    }
    arr[0] = LastElement;

    if(cycleCount > 1) cyclicallyRotateArray(arr, size, --cycleCount);
    
    return arr;
}

void findDuplicate(int arr[], int size){
    sortArray(arr, size);
    for(int i=0; i<size; i++){
        if(arr[i] == arr[i+1]){
            if(i-1 < 0 && arr[i-1] == arr[i]) continue;
            cout<<arr[i];
        }
    }
}

// 2nd approch
int dublicateInN1(int arr[], int size){
    // {1,2,2,3,4};
    int sum1 = 0;
    for(int i=0; i<size; i++){
        sum1 += arr[i];
    }
    return sum1 - (((size)*(size-1))/2);
}

void findPairInArray(int arr[], int size, int sum){
    sortArray(arr, size);
    int j = size - 1;
    for(int i=0; i<size; i++){
        if(arr[i] + arr[j] == sum){
            cout<<"The Pair is - "<<arr[i]<<", "<<arr[j]<<endl;
        }
        if(arr[i] + arr[j] > sum){
            j--;
        }
        if(arr[i] + arr[j] == sum){
            i++;
        }
    }
}

void findTripletInArray(int arr[], int size, int sum){
    // {8,7,3,5,6,4,1,9,0,2,8,7,3,5,6,4,1,9,8,2}
    sortArray(arr, size);
    for(int k=0; k<size; k++){
        int newTarget = sum - arr[k];
        int j = size - 1;
        for(int i=k; i<size; i++){
            if(arr[i] + arr[j] == newTarget){
                cout<<"The Triplet is - "<<arr[k]<<", "<<arr[i]<<", "<<arr[j]<<endl;
            }
            if(arr[i] + arr[j] > newTarget){
                j--;
            }
            if(arr[i] + arr[j] == newTarget){
                i++;
            }
        }
    }
}

bool checkArrayForPalindrome(int arr[], int size){
    for(int i=0; i<size/2; i++){
        if(arr[i] != arr[size-1-i]) {
            cout<<"Array is Not Palindrome"<<endl;
            return false;
        }
    }
    cout<<"Array is Palindrome"<<endl;
    return true;
}

int bringLessThan_K_Together(int arr[], int size, int k){
    // {2, 7, 9, 1, 2, 5, 4, 8, 7, 4}
    int windowSize = 0;

    for(int i=0; i<size; i++){
        if(arr[i]<=k) windowSize++;
    }

    // create first window
    int bad = 0;
    for(int i=0; i<windowSize; i++){
        if(arr[i]>k) bad++;
    }

    // check for remaining windows
    int ans = bad;
    for(int i=0, j=windowSize; j<size; i++, j++){
        if(arr[i]>k) bad--;
        if(arr[j]>k) bad++;
        ans = min(ans, bad);
    }

    cout<<"Minimum swaps required to bring all elements less than or equal to k together is - "<<ans<<endl;
    return ans;
}

bool uniqueOccurrences(int arr[], int size) {    
    map<int, int> mp;
        
    for(int i=0; i<size; i++){
        mp[arr[i]]++;
    }
    
    for(auto i=mp.begin(); i != mp.end(); i++){
        for(auto j=mp.begin(); j != mp.end(); j++){
            if(i->second == j->second && i->first != j->first) return false;
        }
    }

    return true;  
}

int kadance(int arr[], int size){
    // {-2,-3,4,-1,-2,1,5,-3}
    int ans = INT_MIN;
    int maxTillNow = 0;

    for(int i=0; i<size; i++){
        maxTillNow += arr[i];

        if(ans < maxTillNow) ans = maxTillNow;

        if(maxTillNow < 0) maxTillNow = 0;
    }

    return ans;
}

int kadanceGetArray(int arr[], int size){
    // {-2,-3,4,-1,-2,1,5,-3}
    int ans = INT_MIN;
    int maxTillNow = 0;

    for(int i=0; i<size; i++){
        maxTillNow += arr[i];

        if(ans < maxTillNow) ans = maxTillNow;

        if(maxTillNow < 0) maxTillNow = 0;
    }

    return ans;
}


int main(){
    system("cls");
    int arr[20] = {8,7,3,5,6,4,1,9,0,2,8,7,3,5,6,4,1,9,8,2};

    // inputArray(arr, 10);
    // printArray(arr, 5); 
    // linearSearch(arr, 10, 5);
    // printArray(reverseArray(arr, 20), 20);
    // minMax(arr, 10);
    // printArray(swapAdjacent(arr, 20), 20);
    // printArray(swapAlternate(arr, 20), 20);
    // printArray(swapNthElement(arr, 20, 1), 20);
    // printArray(sortArray(arr, 20), 20);

    // int arr1[20] = {8,7,3,-5,6,-4,1,9,0,-2,8,7,-3,5,6,4,1,9,0,2};
    // printArray(negativeToSide(arr1, 20), 20);

    // int arr2[9] = {1,2,3,4,5,6,7,8,9};
    // int arr3[6] = {5,6,7,8,9,22};
    // arrayUnion(arr2, 9, arr3, 6);
    // cout<<endl;
    // arrayIntersection(arr2, 9, arr3, 6);

    // printArray(cyclicallyRotateArray(arr, 20, 1), 20);

    // findDuplicate(arr, 20);
    // int arrX[5] = {1,2,2,3,4};
    // cout<<dublicateInN1(arrX, 5);

    // findPairInArray(arr, 20, 10);
    // findTripletInArray(arr, 20, 15);

    // checkArrayForPalindrome(arr, 20);

    // int arr4[7] = {1, 2, 5, 4, 8, 7, 4};
    // bringLessThan_K_Together(arr4, 7, 5);

    int arr5[6] = {1,2,2,1,1,3};
    cout<<uniqueOccurrences(arr5, 6);

    // int arr6[8] = {-2,-3,4,-1,-2,1,5,-3};
    // cout<<kadance(arr6, 8);
    // cout<<kadanceGetArray(arr6, 8);

}