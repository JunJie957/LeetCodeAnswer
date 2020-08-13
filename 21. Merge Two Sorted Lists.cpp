/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // 特殊情况 
		if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
		
		// 确定头结点 
        ListNode* head = nullptr;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
		
		// 按照数值大小依次将节点串联起来 
        ListNode* cur = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        
        // 如果链表未遍历完，则直接接在cur之后即可 
        l1 != nullptr ? cur->next = l1 : cur->next = l2;
        
        return head;
    }
};
