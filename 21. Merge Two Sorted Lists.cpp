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
        
        // ������� 
		if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
		
		// ȷ��ͷ��� 
        ListNode* head = nullptr;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
		
		// ������ֵ��С���ν��ڵ㴮������ 
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
        
        // �������δ�����꣬��ֱ�ӽ���cur֮�󼴿� 
        l1 != nullptr ? cur->next = l1 : cur->next = l2;
        
        return head;
    }
};
