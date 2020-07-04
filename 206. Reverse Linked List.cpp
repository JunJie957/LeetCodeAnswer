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
        if (head == nullptr) return nullptr;

        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next_node = cur;

        bool head_flag = false;
        while (next_node != nullptr)
        {
            next_node = cur->next;

            cur->next = pre;
            if (head_flag == false)
            {
                pre->next = nullptr;
                head_flag = true;
            }

            pre = cur;
            cur = next_node;
        }
        return pre;
    }
};