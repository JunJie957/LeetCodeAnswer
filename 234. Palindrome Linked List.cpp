// ����1�����ö���Ĵ洢�ռ� 
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

// ����2������ָ��+��ת����+�Ƚ�
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

            cur->next = pre;   // ��ת
            pre = cur;
        }
         
        // �������ڵ㣬�м�ڵ㲻��
        if (fast != nullptr) slow = slow->next; 

        while (cur != nullptr) {
            if (cur->val != slow->val) return false;
            cur = cur->next;
            slow = slow->next;
        }
        return true;
    }
}; 
