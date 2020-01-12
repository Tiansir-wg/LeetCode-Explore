/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 
// 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
// 思想:两个链表从低索引到高索引对应数的低位到高位，所以从开头开始计算，其结果就是低位到高位的计算
// 需要注意的是可能会产生进位，所以需要一个进位位,这个位要加到下一个位的计算上。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    	// 新生成的链表的头指针
    	ListNode *head = NULL;

    	// p1,p2分别表示两个链表的当前位置,p表示生成链表的当前位置
    	ListNode *p1 = l1,*p2 = l2,*p = head;

    	// temp暂存当前位的和
    	int temp;

    	// 进位位
    	int carry = 0;
        
    	while(p1 != NULL && p2 != NULL){
    		// 两个位的初始和，这个和可能会超过10
    		temp = p1->val + p2->val + carry;
    		// 产生进位的情况
    		if(temp > 9){
    			carry = temp / 10;
    			temp %= 10;
    		}

    		// 没有进位时进位位归零
    		else{
    			carry =0;
    		}

    		// 第一次计算没有头结点，从头结点开始连接
    		if(head == NULL){
    			head = new ListNode(temp);
    			p = head;
    		}
    		else{
    			p->next = new ListNode(temp);
    			p = p->next;
    		}
    		p1 = p1->next;
    		p2 = p2->next;
    	}

    	// 两个链表长度不等时，直接将较长链表的位和carry做加法
        while(p1!=NULL){
            temp = p1->val + carry;
    		if(temp > 9){
    			carry = temp / 10;
    			temp %= 10;
    		}else{
    			carry =0;
    		}
            p->next = new ListNode(temp);
            p = p->next;
            p1 = p1->next;
        }
        
        while(p2!=NULL){
            temp = p2->val + carry;
    		if(temp > 9){
    			carry = temp / 10;
    			temp %= 10;
    		}else{
    			carry =0;
    		}
            p->next = new ListNode(temp);
            p = p->next;
            p2 = p2->next;
        }
        
        // 最高位之和如果产生了进位，那么需要额外的一个节点保存其值
        if(carry != 0){
            p->next = new ListNode(carry);
        }

    	return head;
        
    }
};