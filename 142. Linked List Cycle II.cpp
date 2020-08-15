/*
��ϣ����

	1����������ʹ�ù�ϣ��洢�ڵ�ָ�루ע�ⲻ�ǽڵ��ֵ�����ǵ�ַ����
	
	2���жϵ�ǰ�ڵ��Ƿ�����ڹ�ϣ���У��������˵���л������ҵ�ǰ�ڵ���ǻ�����ʼ�㣬���ص�ǰ�ڵ��ָ�뼴�ɡ�
	
	3�����������ɣ���Ȼû����ͬ�ڵ㣬���������ѭ��
*/
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        while (head != nullptr) {
            if (s.find(head) != s.end()) {
                return head;
            }
            s.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};



/*
˫ָ�뷨��

	1����һ��ѭ��ȷ���Ƿ�Ϊѭ������
	
	2���ڶ���ѭ���ҵ�ѭ���������ʼ�ڵ�
*/ 
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // ȷ�ϴ�����Ϊѭ������
                fast = head;
                while (fast != slow) { // �ҵ�ѭ�������ѭ����ʼ���
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};


