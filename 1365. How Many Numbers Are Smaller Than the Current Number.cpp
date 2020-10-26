
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        for (auto& iter : nums) {
            ++count[iter];
        }

        for (int i = 1; i < 101; ++i) {
            count[i] += count[i - 1];
        }

        vector<int> ans;
        for (auto& iter : nums) {
            ans.emplace_back(iter == 0 ? 0 : count[iter - 1]);
        }
        return ans;
    }
};
