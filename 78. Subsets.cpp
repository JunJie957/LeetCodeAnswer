class Solution {
    int size;
    vector<int> sub;
    vector<vector<int>> res;
public:
    /*
        nums:       ���弯��
        begin:      ��ǰ�Ӽ�����ʼλ�ã�ȥ��
        subSize:    ��ǰ�Ӽ�Ҫ��ĸ���
        sub:        ��ǰ�Ӽ�
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
