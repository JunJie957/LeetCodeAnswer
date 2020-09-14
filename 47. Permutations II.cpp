// ����1��ʹ��C++�⺯��
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        while (res.emplace_back(nums), next_permutation(nums.begin(), nums.end()));
        return res;
    }
}; 

// ����2������ȥ�أ�dfs
class Solution {
private:
    int size;
    vector<int> cur;
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // ������Ϊȥ����׼��
        this->size = nums.size();
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<bool> used) {
        if (cur.size() == size) {
            res.emplace_back(cur);
            return;
        }

        for (int i = 0; i < size; ++i) {
            if (used[i] || (i > 0 && !used[i - 1] && nums[i] == nums[i - 1])) 
                continue;
          
            // ѡ��i����
            cur.emplace_back(nums[i]); 
            used[i] = true; 
           
            dfs(nums, used);
           
            // ��ѡ��i����
            cur.pop_back(); 
            used[i] = false;
           
        }
    }
};
