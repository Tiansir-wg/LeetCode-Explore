// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接
// 给定的两个链表的所有节点组成的。
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    int val;
    struct ListNode *next;
 }ListNode;

 struct ListNode* mergeTwoLists( ListNode* l1, ListNode* l2){
     if(!l1){
         return l2;
     }
     if(!l2){
         return l1;
     }

     // 分别指向待合并的两个链表的当前位置
     ListNode *pos_l1 = l1,*pos_l2 = l2;

     // 返回链表的头结点
     ListNode *retHead = (ListNode*)malloc(sizeof(ListNode));
     if(retHead == NULL){
         return NULL;
     }
     // 合并链表的当前位置
     ListNode *pos_ret = retHead;

     // 将两个链表较小的节点拆下来挂到新链表上
     while(pos_l1 && pos_l2){
         if(pos_l1->val < pos_l2->val){
             pos_ret->next = pos_l1;
             pos_ret = pos_l1;
             pos_l1 = pos_l1->next;    
         }else{
            pos_ret->next = pos_l2;
             pos_ret = pos_l2;
             pos_l2 = pos_l2->next;    
         }
     }

     // 处理剩余的节点
     if(pos_l1){
         pos_ret->next = pos_l1;
     }
     if(pos_l2){
         pos_ret->next = pos_l2;
     }

     ListNode *ret = retHead->next;
     free(retHead);
     return ret;
 }
 int main(){
     int count1,count2;
     scanf("%d %d",&count1,&count2);
     ListNode *head1 = (ListNode*)malloc(sizeof(ListNode)),*p = head1;

     // 输入链表1
     printf("链表一\n");
     for(int i = 0;i < count1;i++){
         p->next = (ListNode*)malloc(sizeof(ListNode));
         p = p->next;
         p->next = NULL;
         scanf("%d",&(p->val));
     }

     // 链表二
     ListNode *head2 = (ListNode*)malloc(sizeof(ListNode)),*q = head2;

     // 输入链表1
     printf("链表二\n");
     for(int i = 0;i < count2;i++){
         q->next = (ListNode*)malloc(sizeof(ListNode));
         q = q->next;
         q->next = NULL;
         scanf("%d",&(q->val));
     }
     for(ListNode *r = mergeTwoLists(head1->next,head2->next);r!=NULL;r = r->next){
         printf("%d  ",r->val);
     }
     return 0;
 }


