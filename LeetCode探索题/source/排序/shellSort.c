#include <stdio.h>

void shellSort(int arr[],int length){
	
	// 步长每次变为原来的1/2
	for(int step = length / 2;step >= 1;step /= 2){

		// 将每隔step个元素当做一个序列进行插入排序
		for(int i = step;i < length;i++){
			int temp = arr[i];
			int j;
			for(j = i - step;j >= 0 && arr[j] > temp;j-=step){
				arr[j + step] = arr[j];
			}
			arr[j + step] = temp;
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
	shellSort(arr,10);
	print(arr,10);
	return 0;
}