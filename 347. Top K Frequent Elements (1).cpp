// 方法1：堆(优先队列) 
// 时间复杂度：O(Nlogk)，哈希表遍历O(N)，每次操作优先队列 O(logk)，因为优先队列的长度为K 
// 空间复杂度：O(N) 
class Solution {
public:
    /* 自定义比较函数 */
    struct cmp {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
            ++um[nums[i]];
        
        priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto& i : um) {
            if (q.size() < k) {
                q.emplace(i);
            } else if (q.top().second < i.second) {
                    q.pop(); q.emplace(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.emplace_back(q.top().first); q.pop();
        }
        return res;
    }
};
