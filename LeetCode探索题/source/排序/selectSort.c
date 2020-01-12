#include <stdio.h>

void selectSort(int arr[],int length){
	if(length <= 0 || !arr)
		return;

	int temp;
	for(int i = 0;i < length - 1;i++){
		int min = i;

		// 找到最小的位置
		for(int j =  i + 1;j < length;j++){
			if(arr[j] < arr[min])
				min = j;
		}
		// 将最小的位置和当前位置的元素交换
		if(min!=i){
		   temp = arr[min];
		   arr[min] = arr[i];
		   arr[i] = temp;
		}
	}
}

void print(int arr[],int length){
	for(int i = 0;i < length;i ++){
		printf("%d\t",arr[i]);
	}
}
int main(){
	int arr[10] = {1,5,2,4,6,7,8,0,9,3};
	selectSort(arr,10);
	print(arr,10);
	return 0;
}