#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL 1000000

int partion(int arr[],int low,int high){

	// 随机生成枢纽位置
	int pivotIndex = low + rand() % (high - low + 1);
	int temp = arr[pivotIndex];
	arr[pivotIndex] =  arr[low];
	arr[low] = temp;

	while(low < high){

		while(low < high && arr[high] >= temp)
			high--;
		arr[low] = arr[high];

		while(low < high && arr[low] <= temp)
			low++;
		arr[high] = arr[low];
	}

	arr[low] = temp;

	return low;
	
}

void quickSort(int arr[],int low,int high){
	if(low < high){
		int pivot = partion(arr,low,high);
		quickSort(arr,low,pivot - 1);
		quickSort(arr,pivot + 1,high);
	}
}

void print(int arr[],int length){
	for(int i = 0;i < length;i ++){
		printf("%d\t",arr[i]);
	}
}

int main(){
	int *arr = (int*)malloc(sizeof(int) * TOTAL);
	srand((unsigned)time(NULL));
	for(int i = 0;i < TOTAL;i++){
		arr[i] = rand() % TOTAL;
	}
	quickSort(arr,0,TOTAL);
	print(arr,TOTAL);
	free(arr);
	return 0;
}