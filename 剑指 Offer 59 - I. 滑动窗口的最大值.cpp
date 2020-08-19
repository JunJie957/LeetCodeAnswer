class MonotonicQueue {
private:
    deque<int> data;
public:

    // 单调队列：单调递减，新添加的元素必须小于队列尾部元素
    // 否则，队列尾部元素依次出队，直到队列尾部元素大于新元素，或新元素成为新的队首
    void push(int n) {
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        data.push_back(n);
    }

    // 队列中最大的元素始终在队头
    int max() {
        return data.front();
    }

    // 如果队头元素不是当前要出栈的元素，说明此元素已经在push时，被弹出栈了
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
                windows.push(nums[i]);	// 前 k - 1个元素直接入队 
            }
            else {
                windows.push(nums[i]); // 当滑动窗口中的元素个数达到规定值，取当前窗口中的最大元素 
                res.push_back(windows.max());
                windows.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
