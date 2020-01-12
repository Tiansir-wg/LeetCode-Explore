# KMP算法


```
// KMP算法
#include<stdio.h>

void getNext(int next[],char pattern[],int size){
	next[0] = -1;

	int j = 0, k = -1;

	while(j < size - 1){
		if(k == -1 || pattern[k] == pattern[j]){
			next[++j] = ++k;
		}else{
			k = next[k];
		}
	}

}

int kmp(char mainString[],int mainSize,char pattern[],int patternSize,int next[]){
	
	int i = 0,j = 0;
	for(;i < mainSize && j < patternSize;){
		if(j == -1 || mainString[i] == pattern[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}

	if(j + 1 > patternSize){
		return i - j;
	}else{
		return -1;
	}

}

int main(){
	char mainString[] = "abcabaaabaabcac";

	char pattern[] = "abaabcac";

	int next[8] = {-1};

	int patternSize = sizeof(pattern) / sizeof(char);

	int mainSize = sizeof(mainString) / sizeof(char);

	getNext(next,pattern,patternSize);

	int res = kmp(mainString,mainSize,pattern,patternSize,next);

	printf("%d",res);

	return 0;

}
```