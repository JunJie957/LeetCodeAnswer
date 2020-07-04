class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 从后向前存储
        int last_loc = m + n - 1; 
        while (n) 
        {
            if (m == 0 || nums1[m - 1] < nums2[n - 1]) 
            {
                nums1[last_loc--] = nums2[--n];
            }
            else 
            {
                nums1[last_loc--] = nums1[--m];
            }
        }
    }
};