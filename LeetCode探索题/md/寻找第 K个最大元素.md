# 寻找第 K个最大元素


```
// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 采用大顶堆方式

// 采用大顶堆方式
#include <iostream>
#include <vector>
using namespace std;

class Solution
 {
public:

	// 将第k个元素向下调整,k索引从0开始
	void mergerDown(vector<int>& nums,int k,int length){
		if(k >= length - 1)
			return;

		int temp = nums[k];
		for(int i = 2 * k + 1;i < length;i = i * 2 + 1){
			if(k + 1 <= length - 1 && nums[i] < nums[i+1]){
				i = i + 1;
			}

			if(temp > nums[i]){
				break;
			}else{

				nums[k] = nums[i];

				k = i;
			}
		}
		nums[k] = temp;
	}
    int findKthLargest(vector<int>& nums, int k) {

    	int size = nums.size();

    	// 构建大顶堆
    	for(int i = size / 2 - 1;i >= 0;i--){
    		mergerDown(nums,i,size);
    	}
    	// 将堆顶元素和堆最后一个元素置换，将当前最大值置换到末尾
		for(int i = 0;i < k;i++){
			int temp = nums[0];
			nums[0] = nums[size - i - 1];
			nums[size - i - 1] = temp;

			// 继续对前面的元素进行调整,使其成为最大堆
			mergerDown(nums,0,size - i - 1);

    	}

    	// 后面的倒数第一第二。分别是第一大第二大元素
    	return nums[size - k];
    }
};

int main(){
	Solution s;
	vector<int> v;
	v.push_back(3);
		v.push_back(2);

	v.push_back(1);

	v.push_back(5);

	v.push_back(6);

	v.push_back(4);

	std::cout << s.findKthLargest(v,2);
	return 0;
}
```