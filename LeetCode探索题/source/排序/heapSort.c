#include <stdio.h>

// 调整大根堆,now是当前需要调整的节点,len是数组长度
void adjustDown(int arr[],int now,int len){
	int temp = arr[now];
	for(int i = now * 2 + 1;i < len;i = i * 2 + 1){
		if(i + 1 < len && arr[i] < arr[i + 1]){
			i++;
		}
		if(arr[i] < temp)
			break;

		arr[now] = arr[i];
		now = i;
	}
	arr[now] = temp;
}
void heapSort(int arr[],int size){
	// 建立大根堆
	for(int i = size / 2 - 1;i >= 0;i --){
		adjustDown(arr,i,size);
	}

	// 将大根堆的第一个元素和交换到后面
	for(int i = 0;i < size;i++){
		int temp = arr[0];
		arr[0] = arr[size - i - 1];
		arr[size - i - 1] = temp;
		adjustDown(arr,0,size - i - 1);
	}
}


void print(int arr[],int length){
	for(int i = 0;i < length;i ++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[10] = {1,5,2,4,6,7,8,0,9,3};
	heapSort(arr,10);
	print(arr,10);
	return 0;
}

