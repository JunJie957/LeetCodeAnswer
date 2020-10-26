// 方法1：利用额外的存储空间 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* tmp = head;
        vector<ListNode*> v;
        while (tmp != nullptr) {
            v.emplace_back(tmp);
            tmp = tmp->next;
        }

        int loc = v.size() - 1;
        tmp = head;
        while (loc >= v.size() / 2) {
            if (tmp->val == v[loc]->val) {
                tmp = tmp->next;
                --loc;
            } else {
                return false;
            }
        }
        return true;
    }
};

// 方法2：快慢指针+反转链表+比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head, *fast = head;
        ListNode* cur = nullptr, * pre = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            cur = slow;
            slow = slow->next;
            fast = fast->next->next;

            cur->next = pre;   // 反转
            pre = cur;
        }
         
        // 奇数个节点，中间节点不算
        if (fast != nullptr) slow = slow->next; 

        while (cur != nullptr) {
            if (cur->val != slow->val) return false;
            cur = cur->next;
            slow = slow->next;
        }
        return true;
    }
}; 
