// ¹þÏ£±í
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> um;
        for (auto& i : A) {
            for (auto& j : B) {
                    ++um[i + j];
            }
        }

        int count = 0;
        for (auto& i : C) {
            for (auto& j : D) {
                if (um.find(0 - (i + j)) != um.end()) {
                    count += um[0 - (i + j)];
                }
            }
        }
        return count;
    }
};
