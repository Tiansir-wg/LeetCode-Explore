#include <stdio.h>

void insertSort(int arr[],int length){
	if(length <= 0 || !arr)
		return;

	// 从第2个元素开始插入
	for(int i = 1;i < length;i++){
		int temp = arr[i];
		int j;
		// 将当前元素前面所有比其大的元素后移
		for(j = i - 1;j >= 0 && arr[j] > temp;j--){
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = temp;
	}
}

void print(int arr[],int length){
	for(int i = 0;i < length;i ++){
		printf("%d\t",arr[i]);
	}
}
int main(){
	int arr[10] = {1,5,2,4,6,7,8,0,9,3};
	insertSort(arr,10);
	print(arr,10);
	return 0;
}