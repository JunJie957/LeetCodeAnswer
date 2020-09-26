class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty()) return nums;
        vector<int> res;
        int size = nums.size(), index;
        for (int i = 0; i < size; ++i) {
            nums[(nums[i] - 1) % size] += size;
        }

        for (int i = 0; i < size; ++i) {
            if (nums[i] <= size) res.emplace_back(i + 1);
        }
        return res;
    }
};
