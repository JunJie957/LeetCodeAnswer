struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针解法 
class Solution {
public:

    /*
        1、快慢指针，快指针走一步，慢指针走两步，只要有循环，就会相遇

        2、快指针走两步的时候，要判断走一步之后，是否为空指针，如果是，就不能继续往下走了，直接返回false

        3、判断参数是否为空
    */
    
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
           
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// 哈希表解法 
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        while (head != nullptr) {
            auto iter = s.find(head);
            if (iter != s.end()) {
                return true;
            }
            else {
                s.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};
