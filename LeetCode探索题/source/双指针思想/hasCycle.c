// 给定一个链表，判断链表中是否有环。

// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {

	// 空链表或者只有一个节点直接返回
	if(!head || !head->next){
		return false;
	}

	// 快指针速度是慢指针的两倍，这样两个指针如果指向了同一个节点则说明
	//  出现了环
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while(fast && fast->next){
		fast = fast->next->next;

		slow = slow->next;
		if(fast == slow)
			return true;
	}
    
    return false;
}
