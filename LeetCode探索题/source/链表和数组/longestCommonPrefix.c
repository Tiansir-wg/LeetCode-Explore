// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestCommonPrefix(char **strs, int strsSize){
	if(strsSize == 0)
		return "";
	// 最长公共前缀的长度,初始时假设第一个串为最长前缀
	int max_common_len = strlen(strs[0]);

	// 第一个串为空串直接返回
	if(max_common_len == 0)
		return "";

	char *max_common_prefix = (char*)malloc(sizeof(char) * (max_common_len + 1));

    // i表示第几个串，将每个串和第一个串的每个字符进行比较
	for(int i = 1;i < strsSize;i++){

		// 只要有一个空串就直接返回
		if(strlen(strs[i]) == 0)
			return "";

		// max_common_len需要进行不断更新，每个遇到一个不相等的字符时就将该字符的位置
		// 作为新的长度
		for(int j = 0;j < max_common_len && strs[i][j] != '\0';){
			// 相等则比较下一个
			if(strs[i][j] == strs[0][j]){
				j++;
			}

            // 不相等则更新长度并比较下一个字符串
            if(strs[i][j] == '\0' || j == max_common_len || strs[i][j] != strs[0][j]){
            	max_common_len = j;

				break;
            }
		}


	}


	if(max_common_len == 0)
		return "";


	strncpy(max_common_prefix,strs[0],max_common_len);
	max_common_prefix[max_common_len] = '\0';

	return max_common_prefix;

}

int main(){

	char arr[3][10] = {"flower","flow","flight"};

	printf("%s",longestCommonPrefix(arr,3));

	return 0;
}