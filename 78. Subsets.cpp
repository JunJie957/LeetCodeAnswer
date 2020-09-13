class Solution {
    int size;
    vector<int> sub;
    vector<vector<int>> res;
public:
    /*
        nums:       整体集合
        begin:      当前子集的起始位置，去重
        subSize:    当前子集要求的个数
        sub:        当前子集
    */
    void backtrack(vector<int>& nums, int begin, int subSize, vector<int>& sub) {
        if (sub.size() == subSize) { res.emplace_back(sub); return; }
        for (int i = begin; i < size; ++i) {
            sub.emplace_back(nums[i]);
            backtrack(nums, i + 1, subSize, sub);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        for (int i = 0; i <= size; ++i) {
            sub.clear();
            backtrack(nums, 0, i, sub);
        }
        return res;
    }
};
