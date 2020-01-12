// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 注意：给定 n 是一个正整数。

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n){
	if(n ==  0)
		return 0;
	if(n == 1)
		return 1;

	int *temp  =  (int*)malloc(sizeof(int) * (n+1));
	temp[0] = 1;
	temp[1] = 1;

	for(int i = 2;i <= n;i++){
		temp[i] =  temp[i - 1] + temp[i - 2]; 
	}

	return temp[n];

}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",climbStairs(n));
	return 0;
}