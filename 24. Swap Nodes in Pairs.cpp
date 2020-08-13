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

        ListNode* newHead = cur; // 新的头结点
        while (pre != nullptr && cur != nullptr) {
            ListNode* last = cur->next;
            
            // 交换两个节点
            cur->next = pre;
            pre->next = last;

            // 将前面节点的next接在新的首节点上
            if (before != nullptr) before->next = cur;
            before = pre;

            // 继续向后移动
            pre = last;
            if(pre != nullptr) cur = pre->next;
        }
        
        return newHead;
    }
};
