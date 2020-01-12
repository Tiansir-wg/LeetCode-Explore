#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head){

    // 链表为空或只有一个节点或只有两个节点的情况
    if(!head || !head->next || !head->next->next){
        return head;
    }

    // 三个以上节点的情况
    // 奇偶链表的起始节点
    struct ListNode *oddHead = head,*evenHead = oddHead->next;
    // 奇偶链表的当前位置
    struct ListNode *oddPos = oddHead,*evenPos = evenHead;

    // 只有奇数个节点时最后 evenPos = NULL;只有偶数个节点时最后evenPos->next == NULL;
    while(evenPos && evenPos->next){
        oddPos->next = evenPos->next;
        oddPos = oddPos->next;
        evenPos->next = oddPos->next;
        evenPos = evenPos->next;
    }
    // 将偶数链表连接到奇数链表的后面
    oddPos->next = evenHead;
    return oddHead;
}