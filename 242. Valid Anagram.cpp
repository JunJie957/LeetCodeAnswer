/*
	方法1：哈希表 
	时间复杂度：O(n)
	空间复杂度：O(1), 哈希表的大小是确定的，不会超过26，小写字母的个数 
*/ 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        if (l1 != l2) return false;

        unordered_map<char, int> us1, us2;
        for (int i = 0; i < l1; ++i) {
            ++us1[s[i]];
            ++us2[t[i]];
        }

        for (auto& i : us1) {
            if (i.second != us2[i.first]) {
                return false;
            }
        }
        return true;
    }
};

/*
	方法2：排序后进行比较
	时间复杂度：O(nlogn), 排序成本O(nlogn)，比较成本O(n) 
	空间复杂度：O(1), 空间取决于排序实现
*/ 
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s.compare(t) == 0;
    }
};

