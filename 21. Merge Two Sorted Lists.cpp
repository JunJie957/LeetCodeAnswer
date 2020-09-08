// 方法1：迭代 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		/* 如果某个链表为空 */
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		/* 寻找头节点 */ 
		ListNode* newHead = nullptr;
		if (l1->val < l2->val) {
			newHead = l1;
			l1 = l1->next;
		} else {
			newHead = l2;
			l2 = l2->next;
		}

		/* 两个链表都不为空，继续遍历 */ 
		ListNode* cur = newHead;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}

		/* 如果某个链表还未遍历完成 */ 
		if (l1 != nullptr) cur->next = l1;
		if (l2 != nullptr) cur->next = l2;

		return newHead;
	}
};

// 方法2：递归
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		} else if (l2 == nullptr) {
			return l1;
		} else if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		} else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};
