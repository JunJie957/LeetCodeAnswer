class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({ 1 });
       
        vector<int> cur;
        vector<int> pre;
        for (int i = 1; i <= rowIndex; ++i)
        {
            cur.clear();
            cur.push_back(1);

            pre = res[i - 1];
            for (int j = 0; j < pre.size() - 1; ++j)
            {
                cur.push_back(pre[j] + pre[j + 1]);
            }

            cur.push_back(1);
            res.push_back(cur);
        }
        return res[rowIndex];
    }
};