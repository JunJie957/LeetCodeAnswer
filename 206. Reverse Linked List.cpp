/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* pre = head;
        ListNode* cur = pre->next;
        ListNode* later = cur->next;

        pre->next = nullptr;
        while (cur != nullptr) {
            cur->next = pre;
            pre = cur;
            cur = later;
            if(later != nullptr) later = later->next;
        }
        return pre;
    }
};
