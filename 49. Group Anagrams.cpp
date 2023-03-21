#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& iter : strs) {
            string tmp = iter;
            sort(tmp.begin(), tmp.end());
            hash[tmp].emplace_back(iter);
        }

        vector<vector<string>> res;
        for (auto& iter : hash) {
            res.emplace_back(iter.second);
        }

        return res;
    }
};
