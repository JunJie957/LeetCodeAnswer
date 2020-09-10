// 方法1：整体排序 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.emplace_back(arr[i]);
        }
        return res;
    }
};

// 方法2：优先队列 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int size = arr.size();
        if (size == 0 || k == 0) return {};
        
        priority_queue<int> q;
        for (int i = 0; i < size; ++i) {
            if (i + 1 <= k) {
                q.push(arr[i]);
            } else if (arr[i] < q.top()) {
                q.pop(); q.push(arr[i]);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top()); q.pop();
        }
        return res;
    }
};
