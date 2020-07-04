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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode* prev = sentinel;
        ListNode* cur = head;
        ListNode* toDelete = nullptr;

        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                toDelete = cur;
            }
            else
                prev = cur;

            cur = cur->next;
            
            if (toDelete != nullptr)
            {
                delete toDelete;
                toDelete = nullptr;
            }
        }

        ListNode* res = sentinel->next;
        delete sentinel;
        sentinel = nullptr;
        return res;
    }
};