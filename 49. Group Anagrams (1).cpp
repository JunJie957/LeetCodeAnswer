class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (auto& iter : strs) {
            string tmp = iter;
            sort(tmp.begin(), tmp.end());
            um[tmp].emplace_back(iter);
        }

        vector<vector<string>>res;
        for (auto& iter : um) {
            res.emplace_back(iter.second);
        }
        return res;
    }
};
