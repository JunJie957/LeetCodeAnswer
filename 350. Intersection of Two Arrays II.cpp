
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return intersect(nums2, nums1); // �����Ƚ�С���������ǰ�棬��ϣ��洢��С���ȵ�����
            
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
