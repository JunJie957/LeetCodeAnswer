// 回溯法
class Solution {
public:
    string str;
    vector<string> ans;
    vector<string> words{ "", "", "abc", "def", "ghi", "jkl" ,"mno", "pqrs", "tuv" ,"wxyz" };
    void DFS(const string& digits, int pos) {
        if (pos == digits.size()) {
            ans.emplace_back(str);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < words[num].size(); ++i) {
            str.push_back(words[num][i]);   // 选
            DFS(digits, pos + 1);
            str.pop_back(); // 不选
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        DFS(digits, 0);
        return ans;
    }
};
