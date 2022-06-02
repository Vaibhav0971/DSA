#include<iostream>

using namespace std;

void print(int arr[], int size){	
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int merge(int arr[], int s, int mid, int e){
	int inv = 0;
	int lLen = mid - s + 1;
	int rLen = e - mid;
	int arrL[lLen];
	int arrR[rLen];

	for(int i=0; i<lLen; i++) arrL[i] = arr[s + i];

	for(int i=0; i<rLen; i++) arrR[i] = arr[mid + i + 1];

	int i=0, j=0, k=s;
	while((i<lLen) && (j<rLen)){
		if(arrL[i] <= arrR[j]){
			arr[k++] = arrL[i++];
		}
		else{
			arr[k++] = arrR[j++];
			inv += lLen - i;
		}
	}

	while(i<lLen) arr[k++] = arrL[i++];

	while(j<rLen) arr[k++] = arrR[j++];

	return inv;
}

int mergeSort(int arr[], int s, int e){
	int inv = 0;

	if(e > s){
		int mid = (s + e)/2;
		inv += mergeSort(arr, s, mid);
		inv += mergeSort(arr, mid+1, e);
		inv += merge(arr, s, mid, e);
	}

	return inv;
}

int main(){
	int arr[] = {8, 4, 2, 1};
	int size = 4;

	cout<<mergeSort(arr, 0, size-1);
	cout<<endl;
	
	print(arr, size);
}