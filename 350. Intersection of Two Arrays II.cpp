
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return intersect(nums2, nums1); // 将长度较小的数组放在前面，哈希表存储较小长度的数组
            
        vector<int> res;
        unordered_map<int, int> m;
        for (auto& i : nums1) m[i]++;

        for (auto& i : nums2) {
            auto iter = m.find(i);
            if (iter != m.end() && iter->second > 0) {
                res.push_back(i);
                --iter->second;
            }
        }
        return res;
    }
};
