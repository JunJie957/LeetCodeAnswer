class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) 
            return "";
        else if (size == 1) 
            return strs[0];
            
        string res("");
        string cur = strs[0]; // 记录当前要进行比较的字符串
        for (int i = 1; i < size; ++i)
        {
            res.clear(); // 每次比较前，先清空 res ，以记录最新的比较结果
            int cur_len = cur.length();
            for (int j = 0; j < cur_len; ++j) 
            {
                if (cur[j] == strs[i][j]) 
                    res += cur[j];
                else 
                    break; 
            }
            if (res.empty()) return res; // 如果某次比较后，结果为空，则直接返回，不用继续比较
            else cur = res; // 更新需要进行比较的字符串
        }
        return res;
    }
};