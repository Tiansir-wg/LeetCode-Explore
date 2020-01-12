# fizzbuzz


```
#include <stdio.h>
#include <stdlib.h>

char * transferToString(int num){
 	char arr[11];
 	int length = 0;
 	int temp = num;
 	while(temp!=0){
 		arr[length] = (temp % 10) - 0 + '0';
 		temp /= 10;
 		length++;
 	}

 	char *ret = (char *)malloc(sizeof(char) * (length + 1));
 	for(int j = 0,k = length - 1;j < length;j++,k--){
 		ret[j] = arr[k];
 	}
 	ret[length] = '\0';
 	return ret;
 }

char ** fizzBuzz(int n, int* returnSize){
	char **ret = (char**)malloc(sizeof(char*) * n);
	for(int i = 1;i <= n;i++){
		if(i % 3 == 0 && i % 5 == 0){
			ret[i - 1] = "FizzBuzz";
		}else if(i % 3 == 0){
			ret[i - 1] = "Fizz";
		}else if(i % 5 == 0){
			ret[i - 1] = "Buzz";
		}else{
			ret[i - 1] = transferToString(i);
		}
	}

	*returnSize = n;
	return ret;
}

int main(){

	int n;
	scanf("%d",&n);
	char **aa = fizzBuzz(n,&n);

	for(int i = 0;i < n;i++){
		printf("%s\n",aa[i]);
	}
	return 0;
}


```