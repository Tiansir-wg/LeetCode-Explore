#include <stdio.h>
#define SIZE 20
void merge(int arr[],int low,int mid,int high){
	int temp[SIZE];
	int i  = low,k = 0,j = mid + 1;
	while(i <= mid && j <= high){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
		}
	}

	while(j <= high){
		temp[k++] = arr[j++];
	}
	while(i <= mid){
		temp[k++] = arr[i++];
	}
	for(i = 0,j = low;i <= high - low;){
		arr[j++] = temp[i++];
	}
}

void mergeSort(int arr[],int low,int high){
	if(!arr || low >= high)
		return;
	int mid = (low + high) / 2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid + 1,high);
	merge(arr,low,mid,high);
}
void print(int arr[],int length){
	for(int i = 0;i < length;i ++){
		printf("%d\t",arr[i]);
	}
}
int main(){
	int arr[10] = {1,5,2,4,6,7,8,0,9,3};
	mergeSort(arr,0,9);
	print(arr,10);
	return 0;
}