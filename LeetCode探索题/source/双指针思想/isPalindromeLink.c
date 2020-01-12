// 请判断一个链表是否为回文链表
#include <stdio.h>
#include <stdbool.h>
typedef struct ListNode {
      int val;
      struct ListNode *next;
}ListNode;
// 算法思想：
// 1. 采用快慢指针方式找到链表的中间节点
// 2. 将后面的半段链表采用迭代的方式逆置
// 3. 从两端链表头部进行比较，如果完全符合则是回文链表
bool isPalindrome(struct ListNode* head){

    // 链表为空或只有一个节点
    if(!head || !head->next){
        return true;
    }

    // 只有两个节点
    if(!head->next->next){
        if(head->val == head->next->val){
            return true;
        }else{
            return false;
        }
    }

    // 三个以上节点采用快慢指针
    ListNode *fast = head;
    ListNode *slow = head;

    // 后一条链表的开始
    ListNode *secondHead = NULL;
    while(fast->next){
        fast = fast->next->next;
        slow = slow->next;
        // 偶数个节点时快指针最终指向最后一个节点的后面，即空指针
        // 此时慢指针指向第二个链表的开始
        if(!fast){
            secondHead = slow;
            break;
        }

        // 奇数个节点时快指针最终指向最后一个节点
        if(fast && !fast->next){
            secondHead = slow->next;
            break;
        }
    }

    // 下面用迭代的方式转置后面一条链表,pos表示当前位置，
    ListNode *pos = secondHead;
    ListNode *pos_next = NULL;
    secondHead = NULL;
    while(pos){
        pos_next = pos->next;
        pos->next = secondHead;
        secondHead = pos;
        pos = pos_next;
    }

    // 逐个比较每个元素是否相等
    for(ListNode *l1 = head,*l2 = secondHead;l1 && l2;){
        if(l1->val == l2->val){
            l1 = l1->next;
            l2 = l2->next;
        }else{
            return false;
        }
    }

    return true;
}