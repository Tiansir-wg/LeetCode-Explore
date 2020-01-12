#include <stdio.h>
#include <stdlib.h>

// 双向扩散方法
// length是字符串长度,left和right分别是扩散的起点,maxStart和maxEnd是回文串的起始索引
void diffusion(char *s,int length,int left,int right,int *maxStart,int *maxEnd){
    if(!s){
        return;
    }
    // 当前两个位置字符相等继续向左右扩散
    while(left >= 0 && right <= length - 1 && s[left] == s[right]){
        left--;
        right++;
    }

    // 如果比最大的长度还长，则更新为新的最长汇文子串
    if(right - left - 1 > *maxEnd - *maxStart + 1){
        *maxStart = left + 1;
        *maxEnd = right - 1;
    }

}
char * longestPalindrome(char * s){

    // 字符串的长度
    int length = 0;
    for(int i = 0;s[i]!='\0';i++){
        length++;
    }

    // 空串或长度为1是回文串
    if(length <= 1){
        return s;
    }

    // 最大回文子串和起始索引
    int maxStart = 0;
    int maxEnd = 0;
    
    for(int i = 0;i < length;i++){
        // aba形式
        diffusion(s,length,i,i,&maxStart,&maxEnd);
        // abba形式
        diffusion(s,length,i,i + 1,&maxStart,&maxEnd);
    }

    // 复制到返回数组
    char *ret = (char*)malloc(sizeof(char) * (maxEnd - maxStart + 2));
    for(int i = 0,j = maxStart;j <= maxEnd;j++,i++){
        ret[i] = s[j];
    }
    ret[maxEnd - maxStart + 1] = '\0';    
    return ret;
}
int main(){
    char s[ ] = "abacabaaaaaaaaa";
    printf("%s",longestPalindrome(s));
    return 0;
}