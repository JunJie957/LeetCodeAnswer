class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string temp;
        vector<string> v;
        int len = str.length();
        for (int i = 0; i < len; ++i)
        {
            if (str[i] != ' ') temp += str[i];
            else
            {
                v.push_back(temp);
                temp.clear();
            }
            if (i == len - 1) v.push_back(temp);
        }

        len = pattern.length();
        if (v.size() != len) return false;
        for (int i = 0; i < len; ++i)
        {   
            if (pattern.find(pattern[i]) != find(v.begin(), v.end(), v[i]) - v.begin()) 
                return false;   // 两个查找的位置结果要相同,才能证明模型是匹配的
        }
        return true;
    }
};