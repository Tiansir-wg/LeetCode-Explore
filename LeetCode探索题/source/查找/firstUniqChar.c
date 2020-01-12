// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
// 注意事项：您可以假定该字符串只包含小写字母。
#include<stdio.h>



int firstUniqChar(char * s){

	// 键值对的映射，key为字母的ASCII码减去一个偏移量后的值，该偏移量恰好使得小写字母a映射到
	// 索引0.value为出现的次处，默认是0表示没有出现过。
	int map['z' - 'a' + 1] = {0};

	// 每次遍历到一个字符将其次数加1
	for(int i = 0;s[i] != '\0';i++){
		map[s[i] - 'a']++;
	}

	// 最后返回的索引，如果不存在则返回-1
	int index = -1;
	
	// 再次遍历字符串，如果遇到一个只出现了一次的字符则跳出并返回
	// s[k] - 'a' 是该字符在映射中的key
	for(int k = 0; s[k] != '\0';k++){
		if(map[s[k] -  'a'] == 1){
			index = k;
			break;
		}
	}
	return index;
}


int main(){

	char *arr  =  "loveleetcode";

	printf("%d",firstUniqChar(arr));


	return 0;
}