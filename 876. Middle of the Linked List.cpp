class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;

		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast != nullptr) {
			slow = slow->next;
			fast = fast->next;
			if (fast != nullptr) {
				fast = fast->next;
			}
		}
		return slow;
	}
};
