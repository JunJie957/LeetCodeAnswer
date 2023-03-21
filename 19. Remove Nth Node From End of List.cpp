#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = head;
        ListNode* slow = dummy;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        // fast 与 slow 之间的距离为 n
        // 当 fast 指向末尾时，slow 指向倒数第 n 个节点
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        auto del = slow->next; // 使用delete删除该节点，避免内存泄漏
        slow->next = slow->next->next;
        delete del;
        del = nullptr;

        ListNode* res = dummy->next;
        delete dummy;
        dummy = nullptr;

        return res;

    }
};
