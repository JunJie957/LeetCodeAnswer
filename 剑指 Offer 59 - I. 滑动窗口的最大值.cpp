class MonotonicQueue {
private:
    deque<int> data;
public:

    // �������У������ݼ�������ӵ�Ԫ�ر���С�ڶ���β��Ԫ��
    // ���򣬶���β��Ԫ�����γ��ӣ�ֱ������β��Ԫ�ش�����Ԫ�أ�����Ԫ�س�Ϊ�µĶ���
    void push(int n) {
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        data.push_back(n);
    }

    // ����������Ԫ��ʼ���ڶ�ͷ
    int max() {
        return data.front();
    }

    // �����ͷԪ�ز��ǵ�ǰҪ��ջ��Ԫ�أ�˵����Ԫ���Ѿ���pushʱ��������ջ��
    void pop(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue windows;
        vector<int> res;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (i < k - 1) {
                windows.push(nums[i]);	// ǰ k - 1��Ԫ��ֱ����� 
            }
            else {
                windows.push(nums[i]); // �����������е�Ԫ�ظ����ﵽ�涨ֵ��ȡ��ǰ�����е����Ԫ�� 
                res.push_back(windows.max());
                windows.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
