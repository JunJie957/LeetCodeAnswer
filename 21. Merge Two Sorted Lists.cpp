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
        ListNode* header = new ListNode(0);
        ListNode* cur = header;
        ListNode** min = nullptr; 

        while (l1 != nullptr && l2 != nullptr)
        {
            min = (l1->val < l2->val) ? &l1 : &l2;  
            cur->next = *min;
            cur = cur->next;
            *min = (*min)->next;
        }

        cur->next = (l1 == nullptr) ? l2 : l1;
        ListNode* res = header->next;
        delete header;
        return res;
    }
};