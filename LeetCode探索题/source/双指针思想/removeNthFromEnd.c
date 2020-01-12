#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct ListNode {
      int val;
      struct ListNode *next;
}ListNode;

ListNode* removeNthFromEnd(struct ListNode* head, int n){
    ListNode *fast = head,*slow = head;
    int i;
    for(i = 0;i < n && fast;i++){
        fast = fast->next;
    }

    // 节点数量不足n
    if(i < n){
        return false;
    }
    // 指向待删除节点
    ListNode *temp;
    // 删除的是头结点
    if(!fast){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // fast指针指向最后一个节点时slow指向待删除节点的前驱节点
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return head;
}