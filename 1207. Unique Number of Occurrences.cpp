// ¹þÏ£±í
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
        for (auto& iter : arr) {
            ++um[iter];
        }
        unordered_set<int> us;
        for (auto& iter : um) {
            if (us.find(iter.second) != us.end()) return false;
            us.emplace(iter.second);
        }
        return true;
    }
}; 
