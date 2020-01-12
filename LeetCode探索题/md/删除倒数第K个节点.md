# 删除倒数第K个节点


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //  采用快慢指针的方式，快指针在慢指针后n个位置
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    for(int i = 0;i < n ;i++){
        fast = fast->next;
    }
    
    // 删除的是头结点
    if(!fast)
        return head->next;
    
    // 快指针指向末尾时，慢指针指向倒数 n + 1 个节点
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    // 删除第n个倒数节点
    slow->next = slow->next->next;
    
    return head;
}


```