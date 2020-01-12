/** 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define INFINITY 2147483647
typedef struct
{
    // 主栈
    int main_stack[SIZE];
    // 最小栈
    int deputy_stack[SIZE];
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate()
{
    MinStack *minstack = (MinStack *)malloc(sizeof(MinStack));
    if (!minstack)
    {
        return NULL;
    }
    minstack->top = -1;
    for (int i = 0; i < SIZE; i++)
    {
        minstack->main_stack[i] = INFINITY;
        minstack->deputy_stack[i] = INFINITY;
    }
    return minstack;
}

void minStackPush(MinStack *obj, int x)
{
    int top = obj->top;
    obj->main_stack[top + 1] = x;
    // 比当前最小栈栈顶元素小或原本栈为空时直接入栈
    if (x < obj->deputy_stack[top] || top == -1)
    {
        obj->deputy_stack[top + 1] = x;
    }
    // 否则需要和最小栈栈顶元素进行比较，取较小者入最小栈
    else
    {
        int oldTop = obj->deputy_stack[top];
        obj->deputy_stack[top + 1] = oldTop;
    }
    obj->top = top + 1;
}

void minStackPop(MinStack *obj)
{
    if (obj->top >= 0)
    {
        obj->top--;
    }
}

int minStackTop(MinStack *obj)
{
    if (obj->top >= 0)
    {
        return obj->main_stack[obj->top];
    }
    else
    {
        return INFINITY;
    }
}

int minStackGetMin(MinStack *obj)
{
    if (obj->top >= 0)
    {
        return obj->deputy_stack[obj->top];
    }
    else
    {
        return INFINITY;
    }
}

void minStackFree(MinStack *obj)
{
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

int main()
{
    MinStack *minstack = minStackCreate();
    minStackPush(minstack, -2);
    minStackPush(minstack, 0);
    minStackPush(minstack, -3);
    int param_4 = minStackGetMin(minstack);
    minStackPop(minstack);
    int param3 = minStackTop(minstack);
    int param_5 = minStackGetMin(minstack);
    minStackFree(minstack);
    printf("%d %d", param3, param_4);
    return 0;
}