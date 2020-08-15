struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ����ָ��ⷨ 
class Solution {
public:

    /*
        1������ָ�룬��ָ����һ������ָ����������ֻҪ��ѭ�����ͻ�����

        2����ָ����������ʱ��Ҫ�ж���һ��֮���Ƿ�Ϊ��ָ�룬����ǣ��Ͳ��ܼ����������ˣ�ֱ�ӷ���false

        3���жϲ����Ƿ�Ϊ��
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

// ��ϣ��ⷨ 
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
