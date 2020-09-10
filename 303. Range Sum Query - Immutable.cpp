class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int size = nums.size(), sums = 0;
        for (int i = 0; i < size; ++i) {
            sums += nums[i];
            sum.emplace_back(sums);
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? sum[j] : sum[j] - sum[i - 1];
    }
};
