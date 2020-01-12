#include <stdio.h>
#include <stdlib.h>
void getNext(char *pattern, int *next, int size)
{

    // i指向当前待求位置，j始终指向模式串中匹配的最长前后缀
    // 前缀的下一个位置
    int i = 0, j = -1;
    next[0] = -1;

    while (i < size - 1)
    {
        // j = -1时说明模式串没有匹配的前后缀，从第一个位置开始
        // 如果 pattern[i] == pattern[j] 说明最长匹配前后缀
        // 加上当前字符后依然构成匹配的前后缀
        if (j == -1 || pattern[i] == pattern[j])
        {
            next[++i] = ++j;
        }
        else
        // 如果不匹配则寻找上一个最长匹配前缀的下一个位置
        {
            j = next[j];
        }
    }
}

int kmp(char *str, char *pattern)
{

    if (!str || !pattern)
        return -1;
    int len;
    for (len = 0; pattern[len] != '\0'; len++)
    {
    }

    int *next = (int *)malloc(sizeof(int) * len);

    getNext(pattern, next, len);
    int i = 0, j = 0;
    while (str[i] != '\0' && pattern[j] != '\0')
    {

        if (j == -1 || pattern[j] == str[i])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (pattern[j] == '\0')
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char *str = "ababababca";
    int re = kmp(str,"abca");
    return 0;
}