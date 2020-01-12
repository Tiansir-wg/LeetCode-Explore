#include <stdio.h>
void bubbleSort(int arr[],int length){
	if(length <= 0 || !arr)
		return;
	// flag 修改标记，如果一轮完毕没有修改则说明基本有序，直接返回
	int temp,flag = 0;
	for(int i = 0;i < length - 1;i++){
		for(int j = 0;j < length - i - 1;j++){
			// 升序
			if(arr[j] < arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] =  temp;
				flag = 1;
			}
		}
		if(flag == 0)
			return;
	}
}


void print(int arr[],int length){
	for(int i = 0;i < length;i ++){
		printf("%d\t",arr[i]);
	}
}
int main(){
	int arr[10] = {1,5,2,4,6,7,8,0,9,3};
	bubbleSort(arr,10);
	print(arr,10);
	return 0;
}