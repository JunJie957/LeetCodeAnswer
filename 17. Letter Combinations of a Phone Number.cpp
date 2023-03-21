#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        DFS(digits, 0);
        return ans;
    }
private:
    void DFS(const std::string& digits, int pos) {
        if (pos == digits.size()) {
            ans.emplace_back(tmp);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < words[num].size(); ++i) {
            tmp.push_back(words[num][i]);
            DFS(digits, pos + 1);
            tmp.pop_back();
        }
    }

    std::string tmp;
    std::vector<std::string> ans;
    std::vector<std::string> words { "", "", "abc", "def", "ghi", "jkl" ,"mno", "pqrs", "tuv" ,"wxyz" };
};