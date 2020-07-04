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
    void deleteNode(ListNode* node) {
       ListNode* next_node = node->next;
       // 挂链
       node->val = next_node->val;
       node->next = next_node->next;
       // 删除之后的节点
       delete next_node;
    }
};