#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 97483600
// 普通的模式匹配
int plainMatch(char *str,char *pattern){
    if(!str || !pattern){
        return -1;
    }

    int i,j;
    for(i = 0;str[i]!='\0';){
        for(j = 0;pattern[j] != '\0';){
            if(str[i] == pattern[j]){
                i++;
                j++;
            }else{
                i = i - j + 1;
                j = 0;
                break;
            }
        }
        if(pattern[j] == '\0'){
            break;
        }
    }
    if(pattern[j] == '\0'){
        return i - j;
    }else
    {
        return -1;
    }
}

// kmp算法
void getNext(int *next,char *pattern,int size){
    int i = 0,k = -1;
    while(i < size - 1){
        if(k == -1 || pattern[i]==pattern[k]){
            next[++i] = ++k;
        }else{
            k = next[k];
        }
    }
}
int main(){
    char *s = (char*)malloc(sizeof(char) * SIZE);
    char *p = (char*)malloc(sizeof(char) * SIZE / 3);
    srand((unsigned)time(NULL));
    for(int i = 0;i < SIZE;i++){
        s[i] = rand() % 26;
    }
    for(int i = 0;i < SIZE / 3;i++){
        p[i] = rand() % 26;
    }
    printf("%d",plainMatch(s,p));
    return 0;
}