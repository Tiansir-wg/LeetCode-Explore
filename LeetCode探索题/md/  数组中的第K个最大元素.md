#   数组中的第K个最大元素

 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

-------

[ 数组中的第K个最大元素](https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/50/sorting-and-searching/98/)

```
class Solution {
public:

	// 类似于快速排序找枢纽值的方式，每次必然能够找到一个枢纽值，
	// 并且该枢纽值在位置固定，所以只需要将其和枢纽值进行比较，就可以
	// 判断当前位置是不是要找的第K大的元素位置
	int findPivot(vector<int>& nums,int left,int right){
		int pivot = nums[left];
		while(left < right){
			while(left < right  &&  nums[right] >= pivot)
				right--;
			nums[left] =  nums[right];
			while(left < right && nums[left] <= pivot)
				left++;
			nums[right] = nums[left];
		}
		nums[left] =  pivot;
		return left;
	}

	// 这里采用这半查找的方式，如果当前索引不是要找的值，那么就根据相对位置决定是
	// 缩小位置向前还是向后查找
    int findKthLargest(vector<int>& nums, int k) {
    	int size = nums.size();
    	if(k < 1 || size < k)
    		return -1;

    	int left = 0,right = size - 1;

    	while(left <= right){
    		int pivot = findPivot(nums,left,right);
    		// 当前元素恰好是要寻找的第K大元素,返回即可
    		if(pivot == size - k)
    			return nums[pivot];
    		// 当前位置在要寻找的第K大元素之前，向后寻找
    		else if(pivot < size - k){
    			left = pivot + 1; 
    		}else{
    			right = pivot - 1;
    		}
    	}

    	return -1;
        
    }
};

```

