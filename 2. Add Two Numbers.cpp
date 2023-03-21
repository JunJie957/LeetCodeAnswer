#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* header = new ListNode(-1);
        ListNode* cur = header;
        int sum = 0;
        bool carry = false;
        while (l1 != nullptr || l2 != nullptr || carry) {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry) {
                sum += 1;
            }

            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum >= 10;

            sum = 0;
        }
        return header->next;
    }
};