#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
      int val;
      struct ListNode *next;
}ListNode;

// 迭代方式
ListNode* reverseListRecursion(struct ListNode* head){

    // 链表为空或只有一个节点
    if(!head || !head->next){
        return head;
    }
    // 返回链表的头指针
    ListNode *retHead = NULL;

    // 当前位置和下一位置
    ListNode *pos = head;
    ListNode *next_pos = head->next;

    while(pos){
        next_pos = pos->next;
        pos->next = retHead;
        retHead = pos;
        pos = next_pos;
    }
    return retHead;
}

// 递归方式
ListNode* reverseListIternation(struct ListNode* head){
    // 链表为空或只有一个节点
    if(!head || !head->next){
        return head;
    }else{
        // 转置链表头部
        ListNode *retHead = reverseListIternation(head->next);
        // 转置链表尾部
        ListNode *retEnd = retHead;
        while(retEnd->next){
            retEnd = retEnd->next;
        }
        retEnd->next = head;
        head->next = NULL;
        return retHead;

    }
}

int main(){
    ListNode *head = NULL;
    ListNode *p;
    for(int i = 0;i < 10;i++){
        if(!head){
           head = (ListNode*)malloc(sizeof(ListNode));
           scanf("%d",&head->val);
           head->next = NULL;
           p = head->next;
        }else{
            p = (ListNode*)malloc(sizeof(ListNode));
            scanf("%d",&p->val);
            p->next = NULL;
            p = p->next;
        }
    }

    p = head;
    while(p){
        printf("%d ",p->val);
        p = p->next;
    }
    reverse(head);
    p = head;
    while(p){
        printf("%d ",p->val);
        p = p->next;
    }
    return 0;
}