#include <stdio.h>
#include <stdlib.h>
// 将奇数移动到偶数前面,采用快排的思路两个指针同时从两端移动
void exchangeOvenOddPosition(int arr[],int count){
	if(!arr || count <= 0)
		return;
	int left = 0,right = count - 1,temp;
	while(left < right){
		while(left < right && arr[right] % 2 == 0)
			right--;

		while(left < right && arr[left] % 2 == 1)
			left++;

		if(left < right){
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
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

	printf("交换前:");
	for(int i = 0;i < count;i++){
		printf("%d",arr[i]);
	}
    printf("\n");
    printf("交换后:");
    exchangeOvenOddPosition(arr,count);
	for(int i = 0;i < count;i++){
		printf("%d",arr[i]);
	}
    printf("\n");
	return 0;
}