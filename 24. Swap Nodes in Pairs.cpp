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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* pre = head;
        ListNode* cur = pre->next;
        ListNode* before = nullptr;

        ListNode* newHead = cur; // �µ�ͷ���
        while (pre != nullptr && cur != nullptr) {
            ListNode* last = cur->next;
            
            // ���������ڵ�
            cur->next = pre;
            pre->next = last;

            // ��ǰ��ڵ��next�����µ��׽ڵ���
            if (before != nullptr) before->next = cur;
            before = pre;

            // ��������ƶ�
            pre = last;
            if(pre != nullptr) cur = pre->next;
        }
        
        return newHead;
    }
};
