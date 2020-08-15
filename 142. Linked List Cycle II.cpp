/*
哈希表法：

	1、遍历链表，使用哈希表存储节点指针（注意不是节点的值，而是地址）。
	
	2、判断当前节点是否存在于哈希表中，如果存在说明有环，而且当前节点就是环的起始点，返回当前节点的指针即可。
	
	3、如果遍历完成，仍然没有相同节点，则此链表无循环
*/
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        while (head != nullptr) {
            if (s.find(head) != s.end()) {
                return head;
            }
            s.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};



/*
双指针法：

	1、第一次循环确认是否为循环链表
	
	2、第二次循环找到循环链表的起始节点
*/ 
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // 确认此链表为循环链表
                fast = head;
                while (fast != slow) { // 找到循环链表的循环起始结点
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};


