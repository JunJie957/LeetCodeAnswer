#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        vector<int> help(nums1.begin(), nums1.end());
        int i = 0, j = 0, loc = 0;
        while (i < m && j < n) {
            if (help[i] <= nums2[j]) {
                nums1[loc++] = help[i++];
            } else {
                nums1[loc++] = nums2[j++];
            }
        }
        while (i < m) nums1[loc++] = help[i++];
        while (j < n) nums1[loc++] = nums2[j++];
    }
};

// 倒序放置元素，可以节省内存空间
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, loc = m + n - 1;
        while (i >= 0 && j >= 0) {
            nums1[loc--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (i >= 0) nums1[loc--] = nums1[i--];
        while (j >= 0) nums1[loc--] = nums2[j--];
    }
};
