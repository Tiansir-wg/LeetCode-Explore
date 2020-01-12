// 双向冒泡排序
#include <stdio.h>
#include <stdlib.h>


// 交换 
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// 升序
void doubleDirectionBubbleSortUp(int arr[],int size){
	if(!arr || size <= 0)
		return;

	// left、right分别指向第一个位置和最后一个位置
	int left = 0,right = size - 1;

	// 是否交换过
	int flag = 0;

	// 每一轮交换能确定开头和结尾两个位置的元素，后面每次只需要对中间的几个数进行
	// 排序即可
	while(left < right){

		// 最大元素到末尾
		for(int i = left;i < right;i++){
			if(arr[i] > arr[i+1]){
				flag = 1;
				swap(&arr[i],&arr[i+1]);
			}
		}
		if(flag == 0)
			break;
		right--;

		// 最小元素到开头
		for(int j = right;j > 0;j--){
			if(arr[j] < arr[j - 1]){
				swap(&arr[j],&arr[j - 1]);
			}
		}
		left++;
	}

}

int main(){
	int count;
	printf("输入数组长度:\n");
	scanf("%d",&count);
	int *arr = (int*)malloc(sizeof(int) * count);
	for(int i = 0;i < count;i++){
		scanf("%d",&arr[i]);
	}

	printf("排序前:");
	for(int i = 0;i < count;i++){
		printf("%d",arr[i]);
	}
    printf("\n");
    printf("排序后:");
    doubleDirectionBubbleSortUp(arr,count);
	for(int i = 0;i < count;i++){
		printf("%d",arr[i]);
	}
    printf("\n");
	return 0;
}
