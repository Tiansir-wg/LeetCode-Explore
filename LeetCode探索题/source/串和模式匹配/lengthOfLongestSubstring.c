#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    // 辅助数组,记录每个字符最近一次出现的位置
    int map[128] = {-1};

    memset(map,-1,sizeof(map));
    
    // 最大长度的子串
    int longestLength = 0;

    if(!s){
        return 0;
    }
    // 串的长度
    int size = 0;
    for(int i = 0;s[i]!='\0';i++){
        size++;
    }

    // left、right分别表示滑动窗口的两边
    for(int left = 0,right = 0;right < size;right++){
        // 如果当前字符在滑动窗口中，则需要将上次出现的字符排除到窗口外
        if(map[s[right]] >= left){
            left = map[s[right]] + 1;
        }

        // 更新最近出现的位置
        map[s[right]] = right;

        // 更新最大长度
        longestLength =  longestLength > right - left + 1 ? longestLength : right - left + 1;
    }
    return longestLength;
}

int main(){
    char *s = "a";
    printf("%d",lengthOfLongestSubstring(s));
    return 0;
}