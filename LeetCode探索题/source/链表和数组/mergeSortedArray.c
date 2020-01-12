// 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

// 说明:

// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。


#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

	// i指向第一个数组,j指向第二个数组,k用于记录合并后的位置
	int i = m - 1,j = n - 1,k = m + n - 1;
	for(;i >= 0 && j >= 0;){
		if(nums1[i] > nums2[j]){

			nums1[k--] = nums1[i--];
		}else{

			nums1[k--] = nums2[j--];
		}
	}

	while(i >= 0){

		nums1[k--] = nums1[i--];

	}

	while(j >= 0){

		nums1[k--] = nums2[j--];

	}
}

int main(){
	int a[] = {0,0,0};
	int b[] = {1};
	merge(a,1,0,b,1,1);
	for(int i = 0;i < 1;i++){
		printf("%d ",a[i]);

	}

	return 0;
}

