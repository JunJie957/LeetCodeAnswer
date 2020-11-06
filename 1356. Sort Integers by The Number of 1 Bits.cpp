// 1、手动计算位1的个数 + map + multiset 自动排序
class Solution {
public:
    int countBits(int num) {
        int cnt = 0;
        while (num != 0) {
            cnt += (num % 2);
            num /= 2;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        map<int, multiset<int>> maps;
        for (auto& iter : arr) maps[countBits(iter)].emplace(iter);
        for (auto& m : maps) {
            for (auto& i : m.second) ans.emplace_back(i);
        }
        return ans;
    }
};

// 2、手动计算每个数含有1的位数 + lambda 表达式排序
class Solution {
public:
    int cntBits(int num) {
        int cnt = 0;
        while (num != 0) {
            cnt += (num % 2);
            num /= 2;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [=](int x, int y) {
            return make_pair(cntBits(x), x) < make_pair(cntBits(y), y);
            });
        return arr;
    }
};

// 3、库函数 bitset
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [=](int x, int y) {
                return make_pair(bitset<32>(x).count(), x) < make_pair(bitset<32>(y).count(), y);
            });
        return arr;
    }
};
