//  寻找数组的第K小元素
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 递归方式
int getKthMinimumRecursion(int arr[],int low,int high,int k){

	// 边界检查
	if(k < 1 || k > high + 1)
		return -2147483648;

	int lowTemp =  low,highTemp = high;

	srand((unsigned)time(NULL));

	// 随机选择枢纽位置
	int pivotIndex = low + rand() % (high - low + 1);
	int temp = arr[pivotIndex];
	arr[pivotIndex] = arr[low];
	arr[low] = temp;

	// 确定枢纽值的位置 
	while(low < high){
		while(low < high && arr[high] >= temp){
			high--;
		}
		arr[low] = arr[high];
		while(low < high && arr[low] <= temp){
			low++;
		}
		arr[high] = arr[low];
	}

	arr[low] = temp;

	// 枢纽值是第k个元素
	if(low + 1 == k){
		return arr[low];
	}
	// 第k元素在枢纽值之前
	else if(low  + 1 > k){
		return getKthMinimumRecursion(arr,lowTemp,low - 1,k);
	}else{
		return getKthMinimumRecursion(arr,low + 1,highTemp,k);
	}
}
// 随机生成随机索引并返回中枢元素的位置
int getPivot(int arr[],int left,int right){
    srand((unsigned)time(NULL));
	int pivotIndex = rand() % (right - left + 1) + left;
	int temp = arr[pivotIndex];
	arr[pivotIndex] = arr[left];
	arr[left] = temp;
	while(left < right){
		while(left < right && arr[right] >= temp){
			right--;
		}
		arr[left] = arr[right];
		while(left < right && arr[left] <= temp){
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = temp;
	return pivotIndex;
}

// 迭代方式
int getKthMinimumIteration(int arr[],int size,int k){
	// 边界检查
	if(k < 1 || k > size){
		return -2147483648;
	}
	int left = 0;
	int right = size - 1;
	int pivot;
	while(left <= right){
		pivot = getPivot(arr,left,right);
		if(pivot + 1 == k){
			return pivot;
		}else if(pivot + 1 < k){
			left = pivot + 1;
		}else{
			right = pivot - 1;
		}
	}
	return pivot;
}
int main(){
	int arr[10] = {1,5,2,4,6,7,8,0,9,3};
	srand((unsigned)time(NULL));
	for(int i = 0;i < 20;i++){
		int k = rand() % 10 + 1;
		printf("%d %d\n",k,getKthMinimumIteration(arr,10,k));
	}
	return 0;
}